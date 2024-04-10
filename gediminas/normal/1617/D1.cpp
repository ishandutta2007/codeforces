#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

#ifdef LOCAL
set<int> __impost;
int __n;
set<int> __read_imp() {
	set<int> t;
	int n;
	cin >> n;

	if (n <= __n / 3 or n >= 2 * __n / 3) {
		cout << "WRONG INPUT " << n << " " << __n << endl;
		exit(0);
	}

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		t.insert(x);
	}

	return t;
}
int ask(int a, int b, int c) {
	if (a < 1 or b < 1 or c < 1 or a > __n or b > __n or c > __n) {
		cout << "WRONG QUERY " << a << " " << b << " " << c << endl;
		exit(0);
	}

	return __impost.count(a) + __impost.count(b) + __impost.count(c) >= 2 ? 0 : 1;
}
void answer(vector<int> imp) {
	debug(imp);
	set<int> t(imp.begin(), imp.end());
	cout << (t == __impost and t.size() == imp.size() ? "OK" : "WA") << endl;
}
#else
int ask(int a, int b, int c) {
	cout << "? " << a << " " << b << " " << c << "\n" << flush;
	int x;
	cin >> x;

	if (x == -1) {
		exit(0);
	}

	return x;
}
void answer(vector<int> imp) {
	cout << "! " << imp.size();

	for (auto &&x : imp) {
		cout << " " << x;
	}

	cout << endl;
}
#endif

void solve(int n) {
	vector<int> t[2];
	vector<int> k(n + 1, -1);
	debug(n);

	for (int i = 1; i <= n; i += 3) {
		int a = ask(i, i + 1, i + 2);
		t[a] = {i, i + 1, i + 2};
		debug(a);
		k[i] = k[i + 1] = k[i + 2] = a;
	}

	assert (t[0].size() > 0 and t[1].size() > 0);

	int c1 = t[1][0];
	int c2 = t[1][1];
	int i1 = t[0][0];
	int i2 = t[0][1];
	int skimp = -1;
	int skger = -1;

	if (ask(c1, c2, i1) == 0) {
		skimp = i1;
		skger = t[1][2];
	}
	else if (ask(c1, c2, i2) == 1) {
		skger = c1;

		if (ask(c1, i1, i2) == 0) {
			skimp = i1;
		}
		else {
			skimp = t[0][2];
		}
	}
	else {
		skimp = i2;
		skger = i1;
	}

	vector<int> imp;
	vector<int> ger;

	for (int i = 1; i <= n; i++) {
		if (i == skimp || i == skger) {
			continue;
		}

		if (ask(i, skimp, skger) == 0) {
			imp.push_back(i);
		}
		else {
			ger.push_back(i);
		}
	}

	imp.push_back(skimp);
	ger.push_back(skger);

	return answer(imp);
}

/*input
2
6
3 4 1 2
9
4 2 3 6 8
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ttt;
	cin >> ttt;

	while (ttt--) {
#ifdef LOCAL
		cin >> __n;
		__impost = __read_imp();
		solve(__n);
#else
		int n;
		cin >> n;
		solve(n);
#endif
	}
}