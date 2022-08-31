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
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt(), m = nxt();
	set<string> first;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		first.insert(s);
	}

	int common = 0;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (first.find(s) != first.end()) {
			++common;
			--n;
		}
	}
	m -= common;

	common %= 2;
	if (common == 0) {
		puts(n > m ? "YES" : "NO");
	} else {
		puts(n >= m ? "YES" : "NO");
	}

	return 0;
}