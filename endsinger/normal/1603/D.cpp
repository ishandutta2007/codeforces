#include<bits/stdc++.h>
using namespace std;
const int N=100005,lg=18,mx=100000;
int m[N],p[N],pl=1,pr=1;
long long s[N],f[lg][N],v=1;
vector<int>e[N];
long long cl(){return s[pr/pl];}
long long cr(){long long t=0;for(auto x:e[pr])if(x>=pl)t+=p[pr/x];return t;}
long long sol(int l,int r)
{
	while(pl>l)
	{
		pl--;
		v+=cl();
	}
	while(pr<r)
	{
		pr++;
		v+=cr();
	}
	while(pl<l)
	{
		v-=cl();
		pl++;
	}
	while(pr>r)
	{
		v-=cr();
		pr--;
	}
	return v;
}
void dfs(int k,int l,int r,int a,int b)
{
	if(l>r)
		return;
	int m=l+r>>1,p=m;
	f[k][m]=f[k-1][m];
	for(int i=min(m-1,b);i>=a;i--)
	{
		long long v=f[k-1][i]+sol(i+1,m);
		if(v<f[k][m])
		{
			f[k][m]=v;
			p=i;
		}
	}
	dfs(k,l,m-1,a,p);
	dfs(k,m+1,r,p,b);
}
int main()
{
	for(int i=1;i<=mx;i++)
	{
		m[i]+=(i==1);
		p[i]+=i;
		for(int j=i+i;j<=mx;j+=i)
			m[j]-=m[i],p[j]-=p[i];
	}
	for(int i=1;i<=mx;i++)
		f[0][i]=1e18;
	for(int i=1;i<=mx;i++)
		s[i]=s[i-1]+p[i];
	for(int i=1;i<=mx;i++)
		for(int j=i;j<=mx;j+=i)
			e[j].push_back(i);
	for(int k=1;k<=17;k++)
		dfs(k,0,mx,0,mx);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(k<=17)
			printf("%lld\n",f[k][n]);
		else
			printf("%d\n",n);
	}
	return 0;
}