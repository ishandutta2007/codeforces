#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXB = 1e5 + 5;

int n, mxb, t;
int b[MAXN];

int f[MAXB];

void solve(void)
{
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	if(t>=mxb || t>=n)
	{
		static bool vis[MAXB];
		for(int i=1; i<=mxb; ++i) vis[i] = 0;
		for(int i=1; i<=n; ++i) vis[b[i]] = 1;
		
		int ans = 0;
		for(int i=1; i<=mxb; ++i)
			if(vis[i]) ++ans;
		printf("%d\n",ans);
		return;
	}
	
	for(int i=1; i<=mxb; ++i) f[i] = 0;
	for(int k=1; k<=t; ++k)
		for(int i=1; i<=n; ++i)
		{
			int x = f[b[i]-1] + 1;
			for(int j=b[i]; j<=mxb && f[j]<x; ++j)
				f[j] = x;
		}
	printf("%d\n",f[mxb]);
}

int main(void)
{
	int T;
	scanf("%d%d%d%d",&T,&n,&mxb,&t);
	while(T--) solve();
	return 0;
}