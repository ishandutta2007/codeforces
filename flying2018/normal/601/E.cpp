#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 1010
#define M 30010
#define P 10000019
#define mod 1000000007
using namespace std;
int l[M],r[M],v[M],w[M],_p[N];
bool fla[M];
vector<int>val[M<<2];
int f[N],ans,k;
void insert(int u,int l,int r,int L,int R,int v1)
{
	if(L<=l && r<=R){val[u].push_back(v1);return;}
	int mid=(l+r)>>1;
	if(L<=mid) insert(u<<1,l,mid,L,R,v1);
	if(R>mid) insert(u<<1|1,mid+1,r,L,R,v1);
}
void answer(int u,int l,int r)
{
	int swp[N],rres;
	for(int p:val[u])
	{
		for(int i=k-w[p];i>=0;i--)
		if(f[i]+v[p]>f[i+w[p]])
		{
			ans=(ans-1ll*f[i+w[p]]*_p[i+w[p]-1]%mod+mod)%mod;
			f[i+w[p]]=f[i]+v[p];
			ans=(ans+1ll*f[i+w[p]]*_p[i+w[p]-1]%mod+mod)%mod;
		}
	}
	for(int i=0;i<=k;i++) swp[i]=f[i];rres=ans;
	if(l==r){if(fla[l]) printf("%d\n",ans);return;}
	int mid=(l+r)>>1;
	answer(u<<1,l,mid);
	for(int i=0;i<=k;i++) f[i]=swp[i];ans=rres;
	answer(u<<1|1,mid+1,r);
	for(int i=0;i<=k;i++) f[i]=swp[i];ans=rres;
}
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]),l[i]=1;
	_p[0]=1;
	for(int i=1;i<=k;i++) _p[i]=1ll*_p[i-1]*P%mod;
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)
		{
			++n,scanf("%d%d",&v[n],&w[n]);
			l[n]=i;
		}
		else if(opt==2)
		{
			int u;
			scanf("%d",&u);
			r[u]=i;
		}
		else fla[i]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(!r[i]) r[i]=m;
		insert(1,1,m,l[i],r[i],i);
	}
	answer(1,1,m);
	return 0;
}