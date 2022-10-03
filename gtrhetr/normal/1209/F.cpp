#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mod 1000000007LL
#define mod1 998244353LL

vector<pii> v[100010];

pll h[1500010];
ll g[1500010];

ll bin[1500010],bin1[1500010],num[1500010];
int fa[1500010][23],id[100010],dep[1500010],n,m,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline void pre_gao()
{
	bin[0]=1;
	for (int i=1;i<=1500000;i++) bin[i]=bin[i-1]*233%mod;
	bin1[0]=1;
	for (int i=1;i<=1500000;i++) bin1[i]=bin1[i-1]*313%mod1;
}

struct node
{
	int x,y;
	node() {}
	node(int x1,int y1):x(x1),y(y1) {}
};

inline bool cmp(int x,int y)
{
	if (dep[x]!=dep[y]) return dep[x]<dep[y];
	if (h[x]==h[y]) return false;
	for (int i=22;~i;i--) if ((1<<i)<=dep[x]&&h[fa[x][i]]!=h[fa[y][i]]) x=fa[x][i],y=fa[y][i];
	return num[x]<num[y];
}

inline bool operator <(const node &x,const node &y) { return cmp(y.y,x.y); }

priority_queue<node> q;

inline void dijkstra()
{
	static int c[110];
	id[1]=tt=0;
	for (pii hh:v[1])
	{
		int t=hh.first,y=hh.second;
		int tot=0;
		while (y) c[++tot]=y%10,y/=10;
		reverse(c+1,c+tot+1);
		int lst=0;
		for (int i=1;i<=tot;i++)
		{
			fa[++tt][0]=lst;dep[tt]=dep[lst]+1;
			for (int j=1;j<=22;j++) fa[tt][j]=fa[fa[tt][j-1]][j-1];
			num[tt]=c[i];
			h[tt]=pll((h[lst].first*233+num[tt])%mod,(h[lst].second*313+num[tt])%mod1);
			g[tt]=(g[lst]*10+num[tt])%mod;
			lst=tt;
		}
		if (!id[t]||cmp(lst,id[t])) id[t]=lst,q.push(node(t,lst));
	}
	while (!q.empty())
	{
		node hhh=q.top();q.pop();
		int x=hhh.x;
		if (id[x]!=hhh.y) continue;
		for (pii hh:v[x])
		{
			int t=hh.first,y=hh.second;
			int tot=0;
			while (y) c[++tot]=y%10,y/=10;
			reverse(c+1,c+tot+1);
			int lst=id[x];
			for (int i=1;i<=tot;i++)
			{
				fa[++tt][0]=lst;dep[tt]=dep[lst]+1;
				for (int j=1;j<=22;j++) fa[tt][j]=fa[fa[tt][j-1]][j-1];
				num[tt]=c[i];
				h[tt]=pll((h[lst].first*233+num[tt])%mod,(h[lst].second*313+num[tt])%mod1);
				g[tt]=(g[lst]*10+num[tt])%mod;
				lst=tt;
			}
			if (!id[t]||cmp(lst,id[t])) id[t]=lst,q.push(node(t,lst));
		}
	}
}

int main()
{
	n=rd();m=rd();pre_gao();
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		v[x].push_back(pii(y,i));
		v[y].push_back(pii(x,i));
	}
	dijkstra();
	for (int i=2;i<=n;i++) print(g[id[i]]);
	return 0;
}