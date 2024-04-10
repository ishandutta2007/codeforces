#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,m,q,od[N],k[N],a[N],c[N],z[N],yr[N],h,f[N];
pair<int,int>s[N];
long long ans,p[N],r[N];
int fa(int x){return (x==f[x]?x:f[x]=fa(f[x]));}
void mg(int x,int y)
{
	x=fa(x),y=fa(y);
	f[x]=y;
	ans-=p[x]-p[x-c[x]];
	ans-=p[y]-p[y-c[y]];
	c[y]+=c[x];
	ans+=p[y]-p[y-c[y]];
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i].first),s[i].second=1;
	for(int i=n+1;i<=n+m;i++)
		scanf("%d",&s[i].first),s[i].second=0;
	n+=m;
	sort(s+1,s+n+1);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&k[i]);
		od[i]=i;
	}
	sort(od+1,od+q+1,[&](int x,int y){return k[x]<k[y];});
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i].first;
		c[i]=s[i].second;
		if(c[i])
			ans+=a[i];
		p[i]=p[i-1]+a[i];
		f[i]=i;
	}
	for(int i=1;i<n;i++)
		z[i]=a[i+1]-a[i],yr[i]=i;
	sort(yr+1,yr+n,[&](int x,int y){return z[x]<z[y];});
	for(int i=1;i<=q;i++)
	{
		while(h<n&&z[yr[h+1]]<=k[od[i]])
		{
			int u=yr[h+1];
			mg(u,u+1);
			h++;
		}
		r[od[i]]=ans;
	}
	for(int i=1;i<=q;i++)
		printf("%lld\n",r[i]);
	return 0;
}