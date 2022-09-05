//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
    char s[100000];
    int it, len;
    fastio() {it=len=0;}
    inline char get()
    {
        if (it<len) return s[it++]; it=0;
        len=fread(s, 1, 100000, stdin);
        if (len==0) return EOF; else return s[it++];
    }
    bool notend()
    {
        char c=get();
        while (c==' '||c=='\n') c=get();
        if (it>0) it--;
        return c!=EOF;
    }
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
    ll r=0; bool ng=0; char c; c=_buff.get();
    while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
    if (c=='-') ng=1, c=_buff.get();
    while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
    return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
    if (x<0) putchar('-'), x=-x;
    register short a[20]={}, sz=0;
    while (x) a[sz++]=x%10, x/=10;
    if(sz==0) putchar('0');
    for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn = 101111;
const int maxv = 100;
const int maxe = 200;
ll ANS;
int n, m, deg[maxn];
vector<int> i_con[maxn], con[maxn];
int w[maxn];
void reduce_graph()
{
	static bool red[maxn];
	static int q[maxn], qn;
	qn = 0;
	for (int i=1; i<=n; i++)
	{
		if (deg[i]==1)
		{
			q[qn++] = i;
		}
	}
	for (int i=0; i<qn; i++)
	{
		int x = q[i];
		if (deg[x]!=1) continue;
		int u = -1;
		for (auto v: i_con[x])
		{
			if (!red[v])
			{
				u = v;
				break;
			}
		}
		assert(u!=-1);
		ANS += 1ll*w[x]*(n-w[x])*2;
		w[u] += w[x];
		red[x] = 1;
		deg[u]--;
		deg[x]--;
		if (deg[u]==1)
		{
			q[qn++] = u;
		}
	}
	for (int i=1; i<=n; i++)
	{
		if (red[i]) continue;
		for (auto j: i_con[i])
		{
			if (!red[j]) con[i].PB(j);
		}
	}
}
vector<int> v;
int vid[maxn], etot;
int belong[maxn];
int dis[maxv][maxn];
bool vis[maxn];
int tmp_T;
void dfs(int x, int pre, vector<int> &v)
{
	vis[x] = 1;
	belong[x] = etot;
	v.PB(w[x]);
	for (auto u : con[x])
	{
		if (!vis[u])
		{
			dfs(u, x, v);
		}
		else if (u!=pre) tmp_T = u; 
	}
}
struct edge
{
	int S, T, n;
	vector<int> a;
	vector<ll> pre_ans, suf_ans, pre_sum, suf_sum, ans, ans_it;
	void init(vector<int> _a, int _S, int _T)
	{
		S = _S;
		T = _T;
		a = _a;
		n = a.size();
		pre_ans.resize(n+1);
		suf_ans.resize(n+1);
		pre_sum.resize(n+1);
		//cerr<<"init:"<<S<<","<<T<<endl;
		//for (auto x: a) cerr<<x<<" ";cerr<<endl;
		ans.resize(2*n+1);
		ans_it.resize(2*n+1);
		for (int i=0; i<n; i++)
		{
			pre_ans[i] = (i>0?pre_ans[i-1]:0)+1ll*(i+1)*a[i];
			pre_sum[i] = (i>0?pre_sum[i-1]:0)+a[i];
		}
		for (int i=n-1; i>=0; i--)
		{
			suf_ans[i] = (i+1<n?suf_ans[i+1]:0)+1ll*(n-i)*a[i];
		}
		int it = -1;
		for (int i=-n; i<=n; i++)
		{
			while ((it+1)+1<=n-(it+1)+i) it++;
			ans_it[i+n] = it;
			ans[i+n] = (it<0?0:pre_ans[it])+suf_ans[it+1];
		}
	}
	void calc(int D)
	{
		int it = 0;
		ll ans = 0;
		for (int i=0; i<n; i++)
		{
			while (it<n&&(it-i)<=i+1+D+(n-it)) it++;
			ans += 1ll*a[i]*(pre_ans[it-1]-pre_ans[i]-1ll*(pre_sum[it-1]-pre_sum[i])*(i+1));
			ans += 1ll*a[i]*(suf_ans[it]+1ll*(pre_sum[n-1]-pre_sum[it-1])*(i+1+D));
		}
		ANS += ans*2;
	}
	ll query(int Sdis, int Tdis)
	{
		int dlt = Tdis-Sdis;
		dlt = max(dlt, -n);
		dlt = min(dlt, n);
		int it = ans_it[dlt+n];
		return (it<0?0:1ll*pre_sum[it])*Sdis+(1ll*pre_sum[n-1]-(it<0?0:pre_sum[it]))*Tdis+ans[dlt+n];
	}
}E[maxe];
void SSSP(int id, int S)
{
	static int q[maxn], qn;
	for (int i=0; i<maxn; i++) dis[id][i] = -1;
	dis[id][S] = 0; qn = 0; q[qn++] = S;
	for (int i=0; i<qn; i++)
	{
		int x = q[i];
		for (auto u : con[x])
		{
			if (dis[id][u]==-1)
			{
				dis[id][u] = dis[id][x]+1;
				q[qn++] = u;
			}
		}
	}
}
void prework()
{
	for (int i=1; i<=n; i++)
	{
		if (deg[i]>2)
		{
			vid[i] = v.size();
			v.PB(i);
		}
		else vid[i] = -1;
	}
	if (v.size()==0)
	{
		for (int i=1; i<=n; i++)
		{
			if (deg[i]>=1)
			{
				vid[i] = v.size();
				v.PB(i);
				if (v.size()>=2) break;
			}
		}
		if (v.size()==1)
		{
			cout<<ANS<<endl;
			exit(0);
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i=0; i<v.size(); i++)
	{
		SSSP(i, v[i]);
		vis[v[i]] = 1;
	}
	for (int i=0; i<v.size(); i++)
	{
		int x = v[i];
		for (auto u : con[x])
		{
			if (!vis[u])
			{
				vector<int> tv;
				dfs(u, x, tv);
				E[etot++].init(tv, x, tmp_T);
			}
		}
	}
	for (int i=0; i<etot; i++)
	{
		E[i].calc(dis[vid[E[i].S]][E[i].T]);
	}
}
void solve()
{
	for (int i=1; i<=n; i++)
	{
		if (deg[i]==0) continue;
		if (vid[i]==-1)
		{
			for (int j=0; j<v.size(); j++)
			{
				ANS += 1ll*dis[j][i]*w[v[j]]*w[i];
			}
			for (int j=0; j<etot; j++)
			{
				if (j==belong[i]) continue;
				ANS += 1ll*E[j].query(dis[vid[E[j].S]][i],dis[vid[E[j].T]][i])*w[i];
			}
		}
		else
		{
			for (int j=1; j<=n; j++) if (deg[j]>0) ANS += 1ll*dis[vid[i]][j]*w[i]*w[j];
		}
	}
}
int main()
{
	getii(n, m);
	for (int i=1; i<=n; i++) w[i] = 1;
	for (int i=1; i<=m; i++)
	{
		int x, y;
		getii(x, y);
		i_con[x].PB(y);
		i_con[y].PB(x);
		deg[x]++; deg[y]++;
	}
	reduce_graph();
	prework();
	solve();
  	cout<<ANS/2<<endl;
    return 0;
}