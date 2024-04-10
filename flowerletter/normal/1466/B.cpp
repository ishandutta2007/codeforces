/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fir first
#define sec second
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int maxn = 2e5;

int T, n, a[maxn + 5], w[maxn + 5];

int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) w[a[i]]++;
		int ans = 0, last = 0;
		rep(i, 1, 2 * n + 1) {
			if(last || w[i]) ans++;
			if(w[i] + last > 1) last = 1;
			else last = 0;
		}
		rep(i, 1, n) w[a[i]]--;
		printf("%d\n", ans);
	}
	return 0;
}