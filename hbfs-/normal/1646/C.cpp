#include <bits/stdc++.h>
#define N 20
#define INF (1<<29)
using namespace std;
long long fact[N];
inline int rd() {int r;scanf("%d",&r);return r;}

bool vis[N];
int ans;
long long n;


int main() {
	int T;
	cin >> T;
	
	fact[0] = 1LL;
	for (int i=1;i<=16;i++)
		fact[i] = 1LL * fact[i-1] * i;
	
	
	while (T--) {
		cin >> n;
		ans = INF;
		
		for (int i=0;i<(1<<13);i++) {
			long long cur = n;
			for (int j=0;j<13;j++)
				if ((i>>j)&1) {
					cur = cur - fact[j+3];
				}
			if (cur < 0) continue;
			int p1 = __builtin_popcountll(cur);
			int p2 = __builtin_popcount(i);
			ans = min(p1+p2, ans);
		}
		cout << ans << endl;
	}
	return 0;
}