#include<bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

struct segment {
	int max_cnt;
	int pref_cnt;
	int suff_cnt;
	bool pref_state;
	bool suff_state;
	bool all_same;

	segment() {
		max_cnt = pref_cnt = suff_cnt = 0;
		pref_state = 0;
		suff_state = 0;
		all_same = true;
	}

	segment(char c) {
		all_same = true;
		max_cnt = 1;
		pref_cnt = suff_cnt = 1;
		if (c == '>') {
			pref_state = 1;
			suff_state = 0;
		} else if (c == '<') {
			pref_state = 0;
			suff_state = 1;
		} else assert(false);
	}

	segment(const segment& a, const segment& b) {
		if (a.max_cnt == 0) {
			*this = b;
			return;
		}
		if (b.max_cnt == 0) {
			*this = a;
			return;
		}
		max_cnt = std::max(a.max_cnt, b.max_cnt);
		if (a.suff_state + b.pref_state <= 1) {
			max_cnt = std::max(max_cnt, a.suff_cnt + b.pref_cnt);
		}

		pref_cnt = (a.all_same && b.pref_state + a.suff_state <= 1) ? (a.pref_cnt + b.pref_cnt) : a.pref_cnt;
		pref_state = a.pref_state;
		suff_cnt = (b.all_same && b.pref_state + a.suff_state <= 1) ? (b.suff_cnt + a.suff_cnt) : b.suff_cnt;
		suff_state = b.suff_state;

		all_same = a.all_same && b.all_same && a.suff_state + b.pref_state <= 1;
	}

	friend std::ostream& operator << (std::ostream& o, const segment& s) {
		return o << '(' << s.pref_cnt << '-' << s.pref_state << ' ' << s.max_cnt << '-' << s.all_same << ' ' << s.suff_cnt << '-' << s.suff_state << ')';
	}
};

struct node {
	bool flip;
	segment v[2];
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	string S; cin >> S;
	vector<node> seg(2*N);
	for (int i = 0; i < N; i++) {
		seg[N+i].flip = false;
		seg[N+i].v[0] = segment(S[i]);
		seg[N+i].v[1] = segment(S[i] ^ '<' ^ '>');
	}
	for (int a = N-1; a > 0; a--) {
		seg[a].flip = false;
		seg[a].v[0] = segment(seg[2*a].v[0], seg[2*a+1].v[0]);
		seg[a].v[1] = segment(seg[2*a].v[1], seg[2*a+1].v[1]);
	}

	auto do_flip = [&](int a) {
		if (a >= 2 * N) return;
		seg[a].flip ^= 1;
		swap(seg[a].v[0], seg[a].v[1]);
	};

	auto downdate_all = std::y_combinator([&](auto self, int a) -> void {
		if (!a) return;
		self(a/2);
		if (seg[a].flip) {
			do_flip(2*a);
			do_flip(2*a+1);
			seg[a].flip = false;
		}
	});
	auto update_all = [&](int a) {
		assert(a >= N);
		for (a /= 2; a; a /= 2) {
			seg[a].v[0] = segment(seg[2*a].v[0], seg[2*a+1].v[0]);
			seg[a].v[1] = segment(seg[2*a].v[1], seg[2*a+1].v[1]);
			if (seg[a].flip) {
				swap(seg[a].v[0], seg[a].v[1]);
			}
		}
	};

	for (int q = 0; q < Q; q++) {
		int l, r; cin >> l >> r; l--, r--;
		assert(l <= r);
		downdate_all(N+l);
		downdate_all(N+r);
		segment lval, rval;
		for (int a = N+l, b = N+r+1; a < b; a /= 2, b /= 2) {
			if (a & 1) {
				do_flip(a);
				lval = segment(lval, seg[a].v[0]);
				a++;
			}
			if (b & 1) {
				--b;
				do_flip(b);
				rval = segment(seg[b].v[0], rval);
			}
		}
		update_all(N+l);
		update_all(N+r);
		cout << segment(lval, rval).max_cnt << '\n';
	}

	return 0;
}