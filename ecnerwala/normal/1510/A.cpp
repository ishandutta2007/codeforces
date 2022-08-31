#include <bits/stdc++.h>

class expr {
public:
	int H = 0, W = 0;
	virtual void render(std::vector<std::string>& s, int dx, int dy) = 0;
	virtual void compute_bounds() = 0;

	virtual ~expr() = default;
};

class input_expr : public expr {
public:
	expr* ch;
	input_expr() { }
	~input_expr() { delete ch; }

	void compute_bounds() override {
		ch->compute_bounds();
		H = ch->H;
		W = 6 + ch->W;
	}

	void render(std::vector<std::string>& s, int dx, int dy) override {
		s[dx+1][dy+0] = 'S';
		s[dx+1][dy+1] = '-';
		s[dx+1][dy+2] = '>';
		dy += 3;
		ch->render(s, dx, dy);
		dy += ch->W;
		s[dx+1][dy+0] = '-';
		s[dx+1][dy+1] = '>';
		s[dx+1][dy+2] = 'F';
	}
};

class or_expr : public expr {
public:
	std::vector<expr*> ch;
	or_expr() { }
	~or_expr() { for (auto c : ch) delete c; }

	void compute_bounds() override {
		assert(!ch.empty());
		W = 0;
		H = -1;
		for (auto c : ch) {
			c->compute_bounds();
			H += 1 + c->H;
			W = std::max(W, c->W + 6);
		}
	}

	void render(std::vector<std::string>& s, int dx, int dy) override {
		int cur_x = 0;
		int last_arrow = -1;
		for (auto c : ch) {
			int cur_arrow = cur_x + 1;
			if (last_arrow != -1) {
				// Draw the vertical bars
				for (int x = last_arrow+1; x < cur_arrow; x++) {
					s[dx+x][dy+0] = '|';
					s[dx+x][dy+(W-1)] = '|';
				}
			}
			last_arrow = cur_arrow;
			s[dx+cur_arrow][dy+0] = '+';
			s[dx+cur_arrow][dy+1] = '-';
			s[dx+cur_arrow][dy+2] = '>';
			for (int y = 3 + c->W; y < W-2; y++) {
				s[dx+cur_arrow][dy+y] = '-';
			}
			s[dx+cur_arrow][dy+(W-2)] = '>';
			s[dx+cur_arrow][dy+(W-1)] = '+';

			c->render(s, dx + cur_x, dy + 3);
			cur_x += c->H;
			cur_x++;
		}
	}
};

class concat_expr : public expr {
public:
	std::vector<expr*> ch;
	concat_expr() { }
	~concat_expr() { for (auto c : ch) delete c; }

	void compute_bounds() override {
		assert(!ch.empty());
		W = -2;
		H = 0;
		for (auto c : ch) {
			c->compute_bounds();
			W += 2 + c->W;
			H = std::max(H, c->H);
		}
	}

	void render(std::vector<std::string>& s, int dx, int dy) override {
		bool is_first = true;
		for (auto c : ch) {
			if (!is_first) {
				s[dx+1][dy+0] = '-';
				s[dx+1][dy+1] = '>';
				dy += 2;
			} else {
				is_first = false;
			}

			c->render(s, dx, dy);
			dy += c->W;
		}
	}
};

class letters_expr : public expr {
public:
	std::string ch;
	letters_expr() {}

	void compute_bounds() override {
		H = 3;
		W = 4 + int(ch.size());
	}

	void render(std::vector<std::string>& s, int dx, int dy) override {
		for (int z = 0; z < 3; z++) {
			s[dx+z][dy+0] = s[dx+z][dy+int(ch.size())+3] = '+';
		}
		for (int i = 1; i+1 < W; i++) {
			s[dx+0][dy+i] = s[dx+2][dy+i] = '-';
		}
		for (int i = 2; i+2 < W; i++) {
			s[dx+1][dy+i] = ch[i-2];
		}
	}
};

class rep_expr : public expr {
public:
	expr* ch;
	bool can_zero;
	bool can_two;
	rep_expr(expr* ch_, char c) : ch(ch_) {
		assert(ch);
		assert((c == '+' || c == '?' || c == '*'));
		can_zero = (c == '?' || c == '*');
		can_two = (c == '+' || c == '*');
	}
	~rep_expr() {
		delete ch;
	}

	void compute_bounds() override {
		ch->compute_bounds();
		H = (can_zero ? 3 : 0) + ch->H + (can_two ? 2 : 0);
		W = 3 + ch->W + 3;
	}

	void render(std::vector<std::string>& s, int dx, int dy) override {
		assert(can_zero || can_two);
		if (can_zero) {
			s[dx+1][dy+0] = '+';
			for (int y = 1; y < W-2; y++) {
				s[dx+1][dy+y] = '-';
			}
			s[dx+1][dy+(W-2)] = '>';
			s[dx+1][dy+(W-1)] = '+';
			s[dx+2][dy+0] = '|';
			s[dx+3][dy+0] = '|';
			s[dx+2][dy+(W-1)] = '|';
			s[dx+3][dy+(W-1)] = '|';
			dx += 3;
		}
		s[dx+1][dy+0] = '+';
		s[dx+1][dy+1] = '-';
		s[dx+1][dy+2] = '>';
		s[dx+1][dy+(W-3)] = '-';
		s[dx+1][dy+(W-2)] = '>';
		s[dx+1][dy+(W-1)] = '+';
		ch->render(s, dx, dy + 3);
		if (can_two) {
			for (int x = 2; x <= ch->H+1; x++) {
				s[dx+x][dy+0] = s[dx+x][dy+(W-1)] = (x == ch->H+1 ? '+' : '|');
			}
			s[dx+ch->H+1][dy+1] = '<';
			for (int y = 2; y < W-1; y++) s[dx+ch->H+1][dy+y] = '-';
		}
	}
};

expr* parse_term(std::string::iterator& st, const std::string::iterator en);
expr* parse_expr(std::string::iterator& st, const std::string::iterator en);

expr* parse_term(std::string::iterator& st, const std::string::iterator en) {
	assert(st != en);
	concat_expr* cur_term = new concat_expr();
	letters_expr* cur_letters = nullptr;

	while (st != en) {
		if ('A' <= *st && *st <= 'Z') {
			if (cur_letters == nullptr) {
				cur_letters = new letters_expr;
				cur_term->ch.push_back(cur_letters);
			}
			cur_letters->ch.push_back(*st);
			++st;
		} else if (*st == '(') {
			cur_letters = nullptr;
			++st;
			cur_term->ch.push_back(parse_expr(st, en));
			assert(*st == ')');
			++st;
		} else if (*st == '+' || *st == '?' || *st == '*') {
			if (cur_letters != nullptr && cur_letters->ch.size() >= 2) {
				// pop out the last character
				char c = cur_letters->ch.back(); cur_letters->ch.pop_back();
				cur_letters = new letters_expr;
				cur_letters->ch.push_back(c);
				cur_term->ch.push_back(cur_letters);
			}
			cur_letters = nullptr;
			cur_term->ch.back() = new rep_expr(cur_term->ch.back(), *st);
			++st;
		} else break;
	}
	return cur_term;
}

expr* parse_expr(std::string::iterator& st, const std::string::iterator en) {
	std::vector<expr*> cur_exprs;
	assert(st != en);
	expr* first_term = parse_term(st, en);
	if (!(st != en && *st == '|')) {
		return first_term;
	}
	or_expr* res = new or_expr;
	res->ch.push_back(first_term);
	while (st != en && *st == '|') {
		++st;
		res->ch.push_back(parse_term(st, en));
	}
	return res;
}

expr* parse_input(std::string::iterator& st, const std::string::iterator en) {
	input_expr* res = new input_expr;
	res->ch = parse_expr(st, en);
	return res;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	string S; cin >> S;
	auto it = S.begin();
	expr* ROOT = parse_input(it, S.end());
	assert(it == S.end());

	ROOT->compute_bounds();
	cout << ROOT->H << ' ' << ROOT->W << '\n';
	vector<string> ans(ROOT->H, string(ROOT->W, ' '));
	ROOT->render(ans, 0, 0);
	for (const auto& s : ans) cout << s << '\n';

	delete ROOT;

	return 0;
}