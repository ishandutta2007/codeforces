#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 3e5 + 5;
const int MAXQ = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const ll LINF = 0xffffffffffffffff;

namespace Segment_Tree
{
	const int MAXP = MAXN * 19;
	int ls[MAXP], rs[MAXP], pcnt = 0, n;
	#define lson(u) ls[u],l,mid
	#define rson(u) rs[u],mid+1,r
	void update(int &u,int l,int r,int q)
	{
		++pcnt; ls[pcnt] = ls[u]; rs[pcnt] = rs[u];
		u = pcnt;
		if(l == r){ ++rs[u]; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q);
		else update(rson(u),q);
	}
	int query(int u,int l,int r,int q)
	{
		if(!u) return 0;
		if(l == r) return rs[u];
		int mid = (l+r)>>1;
		return q<=mid? query(lson(u),q): query(rson(u),q);
	}
	inline void update(int &u,int q){ update(u,1,n,q);}
	inline int query(int u,int q){ return query(u,1,n,q);}
} using Segment_Tree::update; using Segment_Tree::query;

ll c[MAXN];
int seq[MAXN], ord[MAXN], fobi[MAXN], fobt[MAXN];
int tor[MAXN];
int rt[MAXN];

int cnt_del[MAXN];
inline int get_del(int l,int r){ return cnt_del[r] - cnt_del[l-1];}
inline int get_eq(int l,int r,int k)
{
	return query(rt[r],k) - query(rt[l-1],k);
}
inline int get_neq(int l,int r,int k)
{
	return (r-l+1) - get_eq(l,r,k) - get_del(l,r);
}

struct Data
{
	int id;
	Data(void){}
	Data(int _id): id(_id) {}
	inline ll get(void) const { return c[id];}
};

inline bool operator == (const Data &p,const Data &q){ return p.id == q.id;}
inline bool operator < (const Data &p,const Data &q)
{
	return c[p.id] == c[q.id]? p.id < q.id: c[p.id] < c[q.id];
}
inline bool operator > (const Data &p,const Data &q){ return q < p;}

inline bool operator < (const Data &p,const pair<int,ll> &q)
{
	return c[p.id] == q.second? p.id < q.first: c[p.id] < q.second;
}

struct Seg
{
	Data mn, sec;
	int l,r;
	Seg(void){}
	Seg(const Data &_mn,const Data &_sec,int _l,int _r): mn(_mn), sec(_sec), l(_l), r(_r) {}
	Seg(const Data &_mn,const Data &_sec): mn(_mn), sec(_sec) {}
	inline ll get(void) const
	{
		int k2 = get_eq(l, r, mn.id);
		int k1 = r-l+1 - k2 - get_del(l, r);
		return k1 * c[mn.id] + k2 * c[sec.id];
	}
};

int cmp_way;
inline bool operator < (const Seg &p,const Seg &q)
{
	if(cmp_way == 1)
		return p.mn == q.mn? p.sec == q.sec? p.l < q.l: p.sec > q.sec: p.mn > q.mn;
	else
		return p.l < q.l;
}

inline bool eq(const Seg &p,const Seg &q){ return p.mn == q.mn && p.sec == q.sec;}
inline Seg upd(const Seg &t,Data k)
{
	if(k > t.sec) return t;
	else if(k > t.mn) return Seg(t.mn, k, t.l, t.r);
	else return Seg(k, t.mn, t.l, t.r);
}

vector<int> g[MAXN], gw[MAXN];
pii qs[MAXN];
ll dis[MAXN];

ll res[MAXQ];

int main(void)
{
	int n,m,Q;
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1; i<=n; ++i) scanf("%llu",&c[i]);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(v); gw[u].push_back(w);
		g[v].push_back(u); gw[v].push_back(w);
	}
	for(int i=1; i<=Q; ++i)
	{
		scanf("%d%d",&qs[i].first,&qs[i].second);
		c[qs[i].first] += qs[i].second;
	}
	
	static bool vis[MAXN];
	memset(dis, 0x3f, sizeof(dis));
	priority_queue< pair<ll,int> > q;
	dis[1] = 0; q.push({0, 1});
	while(q.size())
	{
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i], w = gw[u][i];
			if(dis[v] > dis[u] + w)
				dis[v] = dis[u] + w,
				q.push({-dis[v], v});
		}
	}
	
	fobi[1] = -1;
	for(int u=1; u<=n; ++u)
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i], w = gw[u][i];
			if(dis[v] == dis[u] + w)
			{
				if(fobi[v] == 0) fobi[v] = u;
				else fobi[v] = -1;
			}
		}
	
	for(int i=1; i<=n; ++i) seq[i] = i;
	sort(seq+1,seq+n+1, [](int u,int v){ return dis[u] < dis[v];});
	for(int i=1; i<=n; ++i) ord[seq[i]] = i;
	
	for(int i=1; i<=n; ++i)
	{
		fobt[i] = fobi[seq[i]];
		cnt_del[i] = cnt_del[i-1] + (fobt[i] == -1);
	}
	
	Segment_Tree::n = n + 1;
	for(int i=1; i<=n; ++i)
	{
		rt[i] = rt[i-1];
		if(fobt[i] != -1 && fobt[i] != 1)
			update(rt[i], fobt[i]);
	}
	
	tor[n] = n+1;
	for(int i=n-1; i>=1; --i)
	{
		if(dis[seq[i]] == dis[seq[i+1]])
			tor[i] = tor[i+1];
		else
			tor[i] = i+1;
	}
	
	c[0] = 0;
	c[MAXN-1] = LINF;
	Data dinf(MAXN-1), ndinf(0);
	
	set<Seg> t;
	cmp_way = 1;
	ll ans = 0;
	{
		static vector<int> eff[MAXN];
		for(int i=1; i<=n; ++i)
			eff[tor[i]].push_back(seq[i]);
		Seg cur(dinf, dinf);
		int lst = 1;
		for(int i=2; i<=n; ++i)
		{
			Seg nxt = cur;
			for(int x: eff[i]) nxt = upd(nxt, Data(x));
			if(!eq(nxt, cur) && lst + 1 <= i - 1)
			{
				cur.l = lst + 1; cur.r = i - 1;
				t.insert(cur);
				ans += cur.get();
				lst = i - 1;
			}
			cur = nxt;
		}
		if(lst + 1 <= n)
		{
			cur.l = lst + 1; cur.r = n;
			t.insert(cur);
			ans += cur.get();
		}
	}
	
//	auto print_seq = [&] (void)
//	{
//		printf("seq:\n");
//		for(int i=1; i<=n; ++i)
//		{
//			int u = seq[i];
//			printf("%d, c = %lld, tor = %d\n",u,c[u],tor[i]);
//		}
//		printf("\n");
//	};
//	auto print_t = [&] (void)
//	{
//		printf("t:\n");
//		for(Seg cur: t)
//		{
//			printf("[%d, %d], mn = (%d, %d)\n",cur.l,cur.r,cur.mn.id,cur.sec.id);
//		}
//		printf("\n");
//		printf("res = %lld\n",ans);
//	};
	
//	print_seq();
//	print_t();	
	
	res[Q+1] = ans;
	for(int k=Q; k>=1; --k)
	{
		int x = qs[k].first;
		ll nc = c[x] - qs[k].second;
		
//		printf("=============================\n");
//		printf("k = %d, x = %d, c[x] = %lld\n",k,x,nc);
//		swap(c[x], nc);
//		print_seq();
//		swap(c[x], nc);
		
		auto itl = t.lower_bound(Seg(x, dinf, -inf, -inf));
		auto it = t.upper_bound(Seg(x, ndinf, inf, inf));
		if(itl != it)
		{
			--it;
			int l = itl -> l, r = it -> r;
			int cnt = get_neq(l, r, x);
			ans = ans - (ll)cnt * c[x] + (ll)cnt * nc;
			++it;
		}
		
		pair<int,ll> ndat = make_pair(x, nc);
		if(it == t.end() || it -> sec < ndat)
		{
			c[x] = nc;
			res[k] = ans;
			continue;
		}
		
		int pos = tor[ord[x]];
		if(pos > n) it = t.end();
		else if(it -> l < pos)
		{
			cmp_way = 2;
			it = t.lower_bound(Seg(0, 0, pos, pos));
			if(it == t.end() || it -> l > pos)
			{
				assert(it != t.begin());
				--it;
				Seg cur1 = *it, cur2 = cur1;
				t.erase(it);
				cur1.r = pos - 1; cur2.l = pos;
				t.insert(cur1);
				it = t.insert(cur2).first;
			}
			cmp_way = 1;
		}
		
		vector<Seg> nxt;
		while(it != t.end() && !(it -> sec < ndat))
			nxt.push_back(*it), t.erase(it++);
		
		for(Seg &cur: nxt) ans -= cur.get();
		c[x] = nc;
		
		if(!nxt.size()){ res[k] = ans; continue;}
		for(Seg &cur: nxt)
		{
			if(cur.sec == x)
			{
				if(x < cur.mn) swap(cur.mn, cur.sec);
			}
			else cur = upd(cur, x);
		}
		
		vector<Seg> lst;
		swap(lst, nxt);
		for(Seg &cur: lst)
		{
			if(nxt.size() && eq(nxt.back(), cur))
				nxt.back().r = cur.r;
			else
				nxt.push_back(cur);
		}
		for(Seg &cur: nxt)
			ans += cur.get(), t.insert(cur);
		
//		print_t();
		res[k] = ans;
	}
	
	for(int i=1; i<=Q+1; ++i)
		printf("%llu\n",res[i]);
	return 0;
}