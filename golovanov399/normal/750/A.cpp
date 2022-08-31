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

	int n = nxt(), k = nxt();
	k = 240 - k;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (5 * i <= k) {
			k -= 5 * i;
			ans += 1;
		} else {
			break;
		}
	}
	printf("%d\n", ans);

	return 0;
}