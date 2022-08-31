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

const int N = 111111;
int cnt[N];

int main(){

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		cnt[x] += 1;
	}

	int ans = 1;
	for (int i = 2; i < N; ++i) {
		int cur = 0;
		for (int j = i; j < N; j += i) {
			cur += cnt[j];
		}
		ans = max(ans, cur);
	}

	printf("%d\n", ans);

	return 0;
}