#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

vector<int> ask(const vector<int>& a, int n) {
	cout << a.size() << "\n";
	for (int x : a) {
		cout << x << " ";
	}
	cout << endl;

	vector<int> result(n);
	for (int i = 0; i < n; ++i) {
		result[i] = nxt();
	}
	return result;
}

int main(){

	int n = nxt();
	int N = 1;
	while (N < n) {
		N *= 2;
	}

	vector<int> ans(n, 1e9 + 10);
	for (int i = 2; i <= N; i *= 2) {
		vector<int> query;
		for (int j = 0; j < n; ++j) {
			if (j % i < i / 2) {
				query.push_back(j + 1);
			}
		}
		auto res = ask(query, n);
		for (int j = 0; j < n; ++j) {
			if (j % i >= i / 2) {
				ans[j] = min(ans[j], res[j]);
			}
		}

		query.clear();
		for (int j = 0; j < n; ++j) {
			if (j % i >= i / 2) {
				query.push_back(j + 1);
			}
		}
		res = ask(query, n);
		for (int j = 0; j < n; ++j) {
			if (j % i < i / 2) {
				ans[j] = min(ans[j], res[j]);
			}
		}
	}

	cout << "-1\n";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}