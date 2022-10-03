#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL
#define pll pair<int,ll>

vector<int> v[5010];

pll h1[5010],h2[5010];

int mx=0;
int s1[5010],s2[5010],s3[5010];
int s[5010],f[5010],h[5010],L[5010],R[5010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline int check(int x)
{
	if (s1[x]+s2[x]+s3[x]==0) return 0;
	if ((s3[x]>=2)||(s1[x]&&s2[x])||(s1[x]&&s3[x])||(s2[x]&&s3[x])) return 2;
	return 1;
}

inline ll gao(int x)
{
	if (s1[x]+s2[x]+s3[x]==0) return 1;
	ll res=s3[x]*(s3[x]-1)+s1[x]*s2[x]+s1[x]*s3[x]+s2[x]*s3[x];
	if (res) return res;
	return s1[x]+s2[x]+s3[x]*2;
}

inline pll gao1(int l,int r)
{
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(s3,0,sizeof(s3));
	for (int i=1;i<=m;i++)
	{
		if (L[i]<=l&&R[i]>=r) { s3[f[i]]++;continue; }
		if (L[i]<=l) s1[f[i]]++;
		if (R[i]>=r) s2[f[i]]++;
	}
	int res=0;
	for (int i=1;i<=n;i++) res+=check(i);
	ll res1=1;
	for (int i=1;i<=n;i++) res1=res1*gao(i)%mod;
	return pll(res,res1);
}

inline ll gao(int l,int r)
{
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(s3,0,sizeof(s3));
	for (int i=1;i<=m;i++)
	{
		if (L[i]<=l&&R[i]>=r) { s3[f[i]]++;continue; }
		if (L[i]<=l) s1[f[i]]++;
		if (R[i]>=r) s2[f[i]]++;
	}
	int res=0;
	for (int i=1;i<=n;i++) res+=check(i);
	if (res<mx) return 0;
	ll res1=1;
	for (int i=1;i<=n;i++) res1=res1*gao(i)%mod;
	return res1;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) s[i]=rd();
	for (int i=1;i<=m;i++) f[i]=rd(),h[i]=rd();
	for (int i=1;i<=n;i++) v[s[i]].push_back(i);
	for (int i=1;i<=m;i++)
	{
		if (v[f[i]].size()<h[i]) { L[i]=n+1;R[i]=0;continue; }
		L[i]=v[f[i]][h[i]-1];
		R[i]=v[f[i]][v[f[i]].size()-h[i]];
	}
	ll ans=0;
	for (int i=0;i<=n;i++) h1[i]=gao1(i,i+1);
	for (int i=0;i<=n;i++) mx=max(mx,h1[i].first);
	printf("%d ",mx);
	for (int i=0;i<=n;i++) if (h1[i].first==mx) ans=pls(ans,h1[i].second);
	for (int i=1;i<=n;i++) ans=mns(ans,gao(i-1,i+1));
	printf("%lld\n",ans);
	return 0;
}