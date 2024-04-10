#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXQ = 2e5 + 5;

int fa[MAXN];
inline void init(int _n){ for(int i=1; i<=_n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

struct Data
{
	int type,u,v,w,id;
	Data(void){}
	Data(int _type,int _u,int _v,int _w,int _id = -1): type(_type), u(_u), v(_v), w(_w), id(_id) {}
};

int a[MAXN];

int main(void)
{
	int n,Q,s,d;
	scanf("%d%d%d%d",&n,&Q,&s,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	vector<Data> vec;
	for(int i=1; i<=Q; ++i)
	{
		int v,k;
		scanf("%d%d",&v,&k);
		vec.emplace_back(2, s, v, k, i);
	}
	
	set<int> t(a+1,a+n+1);
	init(n);
	while(1)
	{
		bool ok = 1;
		for(int i=1; i<=n; ++i)
			if(find(i) != find(1)) ok = 0;
		if(ok) break;
		
		static vector<int> ids[MAXN];
		for(int i=1; i<=n; ++i) ids[i].clear();
		for(int i=1; i<=n; ++i) ids[find(i)].push_back(i);
		
		vector<Data> es;
		for(int rt=1; rt<=n; ++rt) if(find(rt) == rt)
		{
			vector<int> &id = ids[rt];
			for(int x: id) t.erase(a[x]);
			
			int mnu = -1, mnv = -1, mndis = 1e9;
			auto chk = [&] (int u,int v)
			{
				int k = min(abs(a[u] + d - a[v]), abs(a[u] - d - a[v]));
				if(k < mndis)
					mnu = u, mnv = v, mndis = k;
			};
			
			auto getid = [&] (int pos)
			{
				return lower_bound(a+1,a+n+1,pos) - a;
			};
			
			auto chk2 = [&] (int u,int pos)
			{
				auto it = t.lower_bound(pos);
				if(it != t.end()) chk(u, getid(*it));
				if(it != t.begin()) chk(u, getid(*--it));
			};
			
			for(int x: id)
			{
				chk2(x, a[x] + d);
				chk2(x, a[x] - d);
			}
			
			es.emplace_back(1, mnu, mnv, mndis);
			
			for(int x: id) t.insert(a[x]);
		}
		
		for(Data &cur: es) if(find(cur.u) != find(cur.v))
			connect(cur.u, cur.v),
			vec.push_back(cur);
	}
	
	sort(vec.begin(), vec.end(), [&] (Data p,Data &q){
		return p.w == q.w? p.type < q.type: p.w < q.w;
	});
	
	init(n);
	static int res[MAXQ];
	for(Data cur: vec)
	{
		if(cur.type == 1)
			connect(cur.u, cur.v);
		else
			res[cur.id] = (find(cur.u) == find(cur.v));
	}
	
	for(int i=1; i<=Q; ++i)
		printf(res[i]? "YES\n": "NO\n");
	return 0;
}