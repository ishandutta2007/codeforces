#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	int m = nxt();
	int len = 1e9;
	for (int i = 0; i < m; ++i) {
		int l = nxt() - 1, r = nxt();
		len = min(len, r - l);
	}

	printf("%d\n", len);
	for (int i = 0; i < n; ++i) {
		printf("%d ", i % len);
	}
	puts("");

	return 0;
}