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

void panic() {
	puts("NO");
	exit(0);
}

int main(){

	int n = nxt();
	int ss = 20000;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		int k;
		string s;
		cin >> k >> s;
		if (cur == 0 && s != "South") {
			panic();
		}
		if (cur == ss && s != "North") {
			panic();
		}
		if (s == "South") {
			cur += k;
		} else if (s == "North") {
			cur -= k;
		}
		if (cur < 0 || cur > ss) {
			panic();
		}
	}
	if (cur) {
		panic();
	} else {
		puts("YES");
	}

	return 0;
}