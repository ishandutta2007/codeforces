#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 110
#define ll long long
#define inf 100000000000
using namespace std;
ll f[N][N][2];
struct line{
	ll p,l;
	bool operator <(const line a)const{return p<a.p;}
}v[N];
ll ans;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&v[i].p,&v[i].l);
	sort(v+1,v+n+1);
	v[0].p=-inf;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=1;k++)
			{
				ans=max(ans,f[i][j][k]);
				ll l=v[j].p+(k?v[j].l:0);
				ll maxn=-inf,p,q;
				for(int u=i+1;u<=n;u++)
					for(int t=0;t<=1;t++)
					{
						ll r=v[u].p+(t?v[u].l:0);
						if(r>maxn) maxn=r,p=u,q=t;
						ll res=min(v[u].l,r-l)+maxn-r;
						f[u][p][q]=max(f[u][p][q],f[i][j][k]+res);
					}
			}
	printf("%lld\n",ans);
	return 0;
}