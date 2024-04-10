//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int mod = 1e9+7;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn = 511;
const int maxm = 511;
const int maxv = maxn*2;
struct PQtree
{
	#define getstate(x) (szr[x]==0?0:(szr[x]<sz[x]?1:2))
	int n, tot, ty[maxv]; //0 P 1 Q
	int sz[maxv], szr[maxv];
	int fail;
	char *s;
	vector<int> con[maxv];
	void init(int _n)
	{
		n = _n;
		memset(ty, 0, sizeof(ty));
		tot = n+1;
		for (int i=1; i<=n; i++) con[n+1].PB(i);
	}
	void dfs(int x)
	{
		sz[x] = x<=n?1:0;
		szr[x] = x<=n?(s[x]=='1'):0;
		for (auto u : con[x])
		{
			dfs(u);
			sz[x] += sz[u];
			szr[x] += szr[u];
		}
	}
	int mergeP(vector<int> v)
	{
		if (!v.size()) return 0;
		if (v.size()==1) return v[0];
		int p = ++tot;
		for (auto x : v) con[p].PB(x);
		return p;
	}
	void addson(int x, int u) {if (u) con[x].PB(u);}
	void join(int x, int y) {for (auto u : con[y]) con[x].PB(u);}
	int solve(int x, int t) //0:all 1:0*1* 2:1*0*
	{
		if (fail) return 0;
		vector<int> v[3];
		for (auto u : con[x]) v[getstate(u)].PB(u);
		if (v[1].size()>2||t>0&&v[1].size()>1) return fail=1, 0;
		if (t==0&&v[1].size()==1&&v[2].size()==0) return solve(v[1][0], 0);
		if (ty[x]==0)
		{
			int p2 = mergeP(v[2]);
			if (t==0)
			{
				con[x] = v[0];
				if (v[1].size()==0) addson(x, p2);
				else
				{
					int p1 = solve(v[1][0], 1);
					addson(p1, p2); 
					if (v[1].size()>1) join(p1, solve(v[1][1], 2));
					addson(x, p1);
				}
				return x;
			}
			else
			{
				ty[x] = 1;
				con[x].clear();
				addson(x, mergeP(v[0]));
				if (v[1].size()>0) join(x, solve(v[1][0], 1));
				addson(x, p2);
				if (t==2) reverse(con[x].begin(), con[x].end());
				return x;
			}
		}
		else
		{
			if (getstate(con[x][0])==2||getstate(con[x].back())==0) reverse(con[x].begin(), con[x].end());
			vector<int> ncon;
			int tmp = 0;
			for (auto u : con[x])
			{
				int st = getstate(u);
				if (st==1)
				{
					int p1;
					if (tmp==0) tmp = 1, p1 = solve(u, 1);
					else if (tmp==1) tmp = 2, p1 = solve(u, 2);
					else return fail=2, 0;
					for (auto v : con[p1]) ncon.PB(v);
				}
				else if (st==2)
				{
					ncon.PB(u);
					if (tmp==0) tmp++;
					else if (tmp==2) return fail=3, 0;
				}
				else if (st==0)
				{
					ncon.PB(u);
					if (tmp==1) tmp++;
				}
			}
			if (t>0&&tmp==2) return fail=4, 0;
			con[x] = ncon;
			if (t==2) reverse(con[x].begin(), con[x].end());
			return x;
		}
	}
	void restrict(char *_s)
	{
		s = _s;
		dfs(n+1);
		solve(n+1, 0);
	}
	vector<int> ans;
	void putans(int x)
	{
		if (x<=n) ans.PB(x);
		for (auto u : con[x]) putans(u);
	}
	vector<int> getans()
	{
		ans.clear();
		putans(n+1);
		return ans;
	}
}A;
char s[maxn][maxn];
int main()
{
	int n;
	scanf("%d", &n);
	A.init(n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", s[i]+1);
		A.restrict(s[i]);
	}
	if (A.fail) puts("NO");
	else
	{
		puts("YES");
		vector<int> v = A.getans();
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++) putchar(s[i][v[j-1]]);
			puts("");
		}
	}
	return 0;
}