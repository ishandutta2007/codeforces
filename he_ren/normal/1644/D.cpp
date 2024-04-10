#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int MAXQ = 2e5 + 5;
const int mod = 998244353;

int qx[MAXQ], qy[MAXQ];

void solve(void)
{
	int n,m,d,Q;
	scanf("%d%d%d%d",&n,&m,&d,&Q);
	for(int i=1; i<=Q; ++i) scanf("%d%d",&qx[i],&qy[i]);
	
	static int delx[MAXN], dely[MAXM];
	int xcnt = 0, ycnt = 0;
	int res = 0;
	for(int i=Q; i>=1; --i)
	{
		if(xcnt == n || ycnt == m) break;
		if(delx[qx[i]] && dely[qy[i]]) continue;
		++res;
		if(!delx[qx[i]]) ++xcnt, delx[qx[i]] = 1;
		if(!dely[qy[i]]) ++ycnt, dely[qy[i]] = 1;
	}
	
	ll ans = 1;
	for(int i=1; i<=res; ++i) ans = ans * d %mod;
	printf("%lld\n",ans);
	
	for(int i=1; i<=Q; ++i)
		delx[qx[i]] = dely[qy[i]] = 0;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}