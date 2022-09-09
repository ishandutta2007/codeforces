#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

inline ll read(void)
{
	ll res = 0;
	char c = getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

struct Stack
{
	int sta[MAXN], pos[MAXN], tp, val[MAXN];
	
	vector<int> vec[65], vsum[65];
	inline int getnum(int k,int l,int r)
	{
		int lef = lower_bound(vec[k].begin(), vec[k].end(), l) - vec[k].begin();
		int rig = upper_bound(vec[k].begin(), vec[k].end(), r) - vec[k].begin();
		return vsum[k][rig] - vsum[k][lef];
	}
	
	int fa[MAXN], n;
	int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
	inline void connect(int u,int v){ fa[find(u)] = find(v);}
	
	inline void init(int _n)
	{
		n = _n;
		for(int i=0; i<=n; ++i) fa[i] = i;
		for(int i=0; i<=60; ++i) vsum[i] = {0};
		tp = 0;
	}
	
	inline int size(void) const { return tp;}
	inline int top(void) const { return sta[tp];}
	inline void push(int r,int k)
	{
		int l = sta[tp] + 1;
		sta[++tp] = r;
		vec[k].push_back(tp);
		vsum[k].push_back(vsum[k].back() + r-l+1);
		pos[r] = tp;
		val[r] = k;
	}
	inline void pop(void)
	{
		if(!tp) return;
		int k = val[sta[tp]];
		vec[k].pop_back();
		vsum[k].pop_back();
		--tp;
	}
	
	inline int get(int l,int r,int k)
	{
		if(l>r) return 0;
		int u = find(l), v = find(r);
		if(u == v) return val[u] == k? (r-l+1): 0;
		
		int pu = pos[u], pv = pos[v];
		
		int res = 0;
		if(val[u] == k) res += u-l+1;
		if(val[v] == k) res += r-sta[pv-1];
		if(pu+1 <= pv-1) res += getnum(k, pu+1, pv-1);
		return res;
	}
}smn, smx;

#define bbitl(i) (1ll<<(i))
#define bdigl(x,i) (((ll)(x)>>(i))&1)

ll a[MAXN];
int b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) a[i] = read();
	
	for(int i=1; i<=n; ++i)
		b[i] = __builtin_popcountll(a[i]);
	
	ll ans = 0;
	
	smn.init(n); smx.init(n);
	int cur = 0;
	for(int i=1; i<=n; ++i)
	{
		while(smn.size() && a[smn.top()] >= a[i])
		{
			int j = smn.top(); smn.pop();
			cur -= smx.get(smn.top() + 1, j, b[j]);
			smn.connect(j, i);
		}
		cur += smx.get(smn.top() + 1, i - 1, b[i]);
		smn.push(i, b[i]);
		
		while(smx.size() && a[smx.top()] <= a[i])
		{
			int j = smx.top(); smx.pop();
			cur -= smn.get(smx.top() + 1, j, b[j]);
			smx.connect(j, i);
		}
		cur += smn.get(smx.top() + 1, i, b[i]);
		smx.push(i, b[i]);
		
		ans += cur;
	}
	
	printf("%lld",ans);
	return 0;
}