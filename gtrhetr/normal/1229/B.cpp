#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define mod 1000000007LL

struct node { int t,next; }a[200010];

pll st[100010][60],h[110];

ll num[100010],ans=0;
int head[100010],len[100010],n,tot;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline ll gcd(ll x,ll y) { return (!y)?x:gcd(y,x%y); }

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void dfs(int x,int y)
{
	if (x==1) st[x][len[x]=1]=pll(num[x],1);
	else
	{
		int top=len[y];
		for (int i=1;i<=top;i++) h[i]=pll(gcd(st[y][i].first,num[x]),st[y][i].second);
		h[++top]=pll(num[x],1);
		len[x]=0;
		for (int i=1,j;i<=top;i=j)
		{
			for (j=i;j<=top&&h[j].first==h[i].first;j++);
			len[x]++;st[x][len[x]].first=h[i].first;
			for (int k=i;k<j;k++) st[x][len[x]].second+=h[k].second;
		}
	}
	for (int i=1;i<=len[x];i++) ans=pls(ans,st[x][i].first%mod*st[x][i].second%mod);
	for (int i=head[x];i;i=a[i].next) if (a[i].t!=y) dfs(a[i].t,x);
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<n;i++) { int x=rd(),y=rd();add(x,y);add(y,x); }
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}