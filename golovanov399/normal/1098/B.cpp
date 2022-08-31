#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct State {
	char type;
	string first, second;
	int diff;

	bool operator <(const State& other) const {
		return diff < other.diff;
	}
};

int dist(const string& s, const string& t) {
	int res = 0;
	for (int i = 0; i < (int)s.length() && i < (int)t.length(); ++i) {
		if (s[i] != t[i]) {
			++res;
		}
	}
	return res;
}

string operator *(const string& s, int k) {
	string res(s.size() * k, 0);
	for (int i = 0; i < (int)s.size(); ++i) {
		for (int j = i; j < (int)res.size(); j += (int)s.size()) {
			res[j] = s[i];
		}
	}
	return res;
}

void calc(const vector<string>& field, State& state) {
	vector<string> a;
	if (state.type == 'c') {
		a.resize(field[0].size(), string(field.size(), 'A'));
		for (int i = 0; i < (int)field.size(); ++i) {
			for (int j = 0; j < (int)field[i].size(); ++j) {
				a[j][i] = field[i][j];
			}
		}
	} else {
		a = field;
	}

	state.diff = 0;
	for (int i = 0; i < (int)a.size(); ++i) {
		string cur = (i % 2) ? state.second : state.first;
		cur = cur * (a[i].size() / 2 + 1);
		state.diff += min(dist(a[i], cur), dist(a[i], cur.substr(1)));
	}
}

vector<string> build(const vector<string>& field, State& state) {
	vector<string> a;
	if (state.type == 'c') {
		a.resize(field[0].size(), string(field.size(), 'A'));
		for (int i = 0; i < (int)field.size(); ++i) {
			for (int j = 0; j < (int)field[i].size(); ++j) {
				a[j][i] = field[i][j];
			}
		}
	} else {
		a = field;
	}
	vector<string> b;

	for (int i = 0; i < (int)a.size(); ++i) {
		string cur = (i % 2) ? state.second : state.first;
		cur = cur * (a[i].size() / 2 + 1);
		b.push_back(dist(a[i], cur) < dist(a[i], cur.substr(1)) ? cur.substr(0, a[i].size()) : cur.substr(1, a[i].size()));
	}

	vector<string> res;
	if (state.type == 'c') {
		res.resize(b[0].size(), string(b.size(), 'A'));
		for (int i = 0; i < (int)b.size(); ++i) {
			for (int j = 0; j < (int)b[i].size(); ++j) {
				res[j][i] = b[i][j];
			}
		}
	} else {
		res = b;
	}

	return res;
}

int main() {
	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	const string nucleobases = "ATGC";
	State result = {'r', "", "", INT_MAX};
	for (char c : {'r', 'c'}) {
		for (int mask = 0; mask < 16; ++mask) {
			if (__builtin_popcount(mask) != 2) {
				continue;
			}
			State state;
			state.type = c;
			state.first = state.second = "";
			for (int i = 0; i < 4; ++i) {
				if (mask & (1 << i)) {
					state.first += nucleobases[i];
				} else {
					state.second += nucleobases[i];
				}
			}
			calc(a, state);
			result = min(result, state);
		}
	}

	a = build(a, result);
	for (auto s : a) {
		cout << s << "\n";
	}

	return 0;
}