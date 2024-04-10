#include<cstdio>
const int MAXN = 2e2 + 5;
const int MAXM = 2e2 + 5;

int n,m,pos[MAXM];
bool vis[MAXN];

inline bool chk(int mid)
{
	for(int i=1; i<=n; ++i) vis[i]=0;
	for(int i=1; i<=m; ++i)
		for(int j=0; j<mid; ++j)
		{
			if(pos[i]-j >= 1) vis[pos[i]-j]=1;
			if(pos[i]+j <= n) vis[pos[i]+j]=1;
		}
	for(int i=1; i<=n; ++i)
		if(!vis[i]) return 0;
	return 1;
}


void solve(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i) scanf("%d",&pos[i]);
	
	int l=0, r=n;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}