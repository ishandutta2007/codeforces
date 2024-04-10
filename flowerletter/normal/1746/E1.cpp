#include <bits/stdc++.h>

using namespace std;

bool query(vector<int> arr) {
	cout << "? " << arr.size() << " ";
	for (int x : arr)
		cout << x << " ";
	cout << endl;
	string s;
	cin >> s;
	return s == "YES";
}

struct data_t {
	int siz;
	vector<pair<int, int>> se;
	void fix() {
		sort(se.begin(), se.end());
	}
	data_t(int siz, vector<pair<int, int>> se) : siz(siz), se(se) {
		sort(se.begin(), se.end());
	}
	data_t() : siz(0), se(vector<pair<int, int>>()) {
	}
};

bool query(data_t vec) {
	vector<int> pos;
	for (auto [l, r] : vec.se)
		for (int k = l; k <= r; ++k)
			pos.push_back(k);
	return query(pos);
}

bool gogo(int x) {
	cout << "! " << x << endl;
	string ret;
	cin >> ret;
	return ret == ":)";
}

data_t merge(data_t a, data_t b) {
	vector<pair<int, int>> res = a.se;
	res.insert(res.end(), b.se.begin(), b.se.end());
	return data_t(a.siz + b.siz, res);
}

ostream& operator<<(ostream& f, data_t &c) {
	f << "(" << c.siz << "){ ";
	for (auto [a, b] : c.se)
		f << "[" << a << ", " << b << "] ";
	f << " }";
	return f;
}

pair<data_t, data_t> gogo(data_t L, data_t R) {
	//cerr << "gogo L = " << L << ", R = " << R << "\n";
	auto judge = [&](int th, data_t p) {
		data_t x, y;
		bool gg = false;
		//cerr << "th = " << th << ", p = " << p << "\n";
		for (auto [l, r] : p.se) {
			//cerr << "Range [" << l << ", " << r << "]\n";
			int len = r - l + 1;
			if (gg) {
				y.se.emplace_back(l, r);
			}
			else if (x.siz + len < th) {
				x.siz += len;
				x.se.emplace_back(l, r);
			}
			else {
				int pos = th - x.siz + l;
				//cerr << "Case 3, pos = " << pos << "\n";
				//assert(l <= pos - 1);
				//assert(pos <= r);
				if (l <= pos - 1) x.se.emplace_back(l, pos - 1);
				if (pos <= r) y.se.emplace_back(pos, r);
				x.siz = th;
				y.siz = p.siz - th;
				gg = true;
			}
		}
		x.fix(); y.fix();
		return make_pair(x, y);
	};
	auto [a, b] = judge((R.siz + 1) / 2, R);
	//cerr << "a = " << a << ", b = " << b << "\n";
	data_t z, w, l, r;
	if (L.siz == 0 || L.siz % 2 == 1 || R.siz % 2 == 0) {
		auto [c, d] = judge(L.siz / 2, L);
		//cerr << "c = " << c << ", d = " << d << "\n";
		z = merge(a, c), w = merge(b, d), l = c, r = d;
	}
	else {
		auto [c, d] = judge(L.siz / 2 - 1, L);
		//cerr << "c = " << c << ", d = " << d << "\n";
		z = merge(a, c), w = merge(b, d), l = c, r = d;
	}
	//cerr << "z = " << z << "\n";
	z.fix(); w.fix();
	return query(z) ? make_pair(z, r) : make_pair(w, l);
}

pair<int, int> go(data_t L, data_t R) {
	//cerr << "go L = " << L << ", R = " << R << "\n";
	int sl = L.siz, sr = R.siz;
	//cerr << "sl = " << sl << ", sr = " << sr << "\n";
	if (sl == 2 && sr == 1) 
		return query(R) ? go(R, L) : go(L, data_t());
	if (sl + sr <= 2) {
		vector<int> cand;
		for (auto [a, b] : L.se)
			for (int k = a; k <= b; ++k)
				cand.push_back(k);
		for (auto [a, b] : R.se)
			for (int k = a; k <= b; ++k)
				cand.push_back(k);
		return make_pair(cand.at(0), cand.at(((int)cand.size()) - 1));
	}
	auto [a, b] = gogo(L, R);
	return go(a, b);
}

void solve() {
	int n;
	cin >> n;
	auto [a, b] = go(data_t(n, { make_pair(1, n) }), data_t());
	gogo(a) || gogo(b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}