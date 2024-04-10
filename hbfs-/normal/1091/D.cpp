#include <bits/stdc++.h>
#define N 1000500
#define mod 998244353
using namespace std;
typedef long long LL;
int n;
LL S,ans,cur=1;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd();
	S = 1LL;
	for (int i=1;i<=n;i++) S = 1LL * S * i % mod;
	ans = 1LL * n * S % mod;
	for (int i=n;i>=2;i--) {
		cur = 1LL * cur * i % mod;
		ans = (ans - cur + mod) % mod;
	}
	//ans = (ans + 1) % mod;
	cout << ans << endl;
	return 0;
}