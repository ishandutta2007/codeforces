#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL
#define pii pair<int,int>

vector<int> v[510],v1[510];

ll f[510][510];
int ch[510][2],size[510],tot,root;
int num[1000010],n,m;

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

int mn[4000010];

inline void build(int o,int l,int r)
{
	if (l==r) { mn[o]=num[l];return; }
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}

inline int query(int o,int l,int r,int x,int y)
{
	if (l>=x&&r<=y) return mn[o];
	int mid=(l+r)>>1,res=m+1;
	if (x<=mid) res=min(res,query(o<<1,l,mid,x,y));
	if (y>mid) res=min(res,query(o<<1|1,mid+1,r,x,y));
	return res;
}

inline int build(int l,int r)
{
	int now=++tot,id=query(1,1,n,l,r);size[now]=1;
	if (v[id][0]<l||v[id][v[id].size()-1]>r) { puts("0");exit(0); }
	for (int i=0;i<v[id].size()-1;i++) if (v[id][i]<v[id][i+1]-1) v1[now].push_back(build(v[id][i]+1,v[id][i+1]-1));
	for (int t:v1[now]) size[now]+=size[t];
	if (v[id][0]>l) ch[now][0]=build(l,v[id][0]-1),size[now]+=size[ch[now][0]];
	if (v[id][v[id].size()-1]<r) ch[now][1]=build(v[id][v[id].size()-1]+1,r),size[now]+=size[ch[now][1]];
	return now;
}

inline void dfs(int x)
{
	if (!x) return;
	if (size[x]==1)
	{
		for (int i=0;i<=m;i++) f[x][i]=i+1;
		return;
	}
	for (int t:v1[x]) dfs(t);
	dfs(ch[x][0]);dfs(ch[x][1]);
	ll res=1;
	for (int t:v1[x]) res=res*f[t][0]%mod;
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=i;j++) f[x][i]=pls(f[x][i],f[ch[x][0]][j+1]*f[ch[x][1]][i-j+1]%mod*res%mod);
	}
}

int main()
{
	m=rd();n=rd();
	for (int i=1;i<=n;i++) v[num[i]=rd()].push_back(i);
	build(1,1,n);
	root=build(1,n);
	for (int i=0;i<=m+1;i++) f[0][i]=1;
	dfs(root);
	printf("%lld\n",f[root][0]);
	return 0;
}