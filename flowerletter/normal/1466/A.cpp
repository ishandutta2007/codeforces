/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fir first
#define sec second
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int maxn = 50; 

int T, n, ans, a[maxn + 5], cnt[maxn + 5];

int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		rep(i, 1 , 50) cnt[i] = 0;
		ans = 0;
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) rep(j, i + 1, n) {
			cnt[a[j] - a[i]] = 1;
		}
		rep(i, 1, 50) ans += cnt[i];
		printf("%d\n", ans); 
	}
	return 0;
}