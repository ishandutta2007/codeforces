#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int ans = 0;
vector<pii> qrys[MAXN], g[MAXN];

struct Data
{
	static map<int,int> eqpos;
	struct Cmp
	{
		Data *I;
		Cmp(Data *_I): I(_I) {}
		bool operator () (int x,int y) const
		{
			x += (x & 1)? I -> tag: - I -> tag;
			y += (y & 1)? I -> tag: - I -> tag;
			return x < y;
		}
	};
	map<int,int,Cmp> a;
	set<pii> ord;
	int tag;
	Data(void): a(this), tag(0) {}
	inline int size(void) const
	{
		return a.size();
	}
	void trim(decltype(a.begin()) it,bool flag)
	{
		if(it != a.end() && it -> first % 2 == 0 && it != a.begin())
		{
			auto jt = prev(it);
			if(jt -> first % 2 != 0)
			{
				if(flag)
					ord.emplace(it -> first - jt -> first, jt -> first);
				else
					ord.erase({it -> first - jt -> first, jt -> first});
			}
		}
	}
	void add(int k)
	{
		k *= 2;
		while(ord.size() && ord.begin() -> first - (tag + k) * 2 <= 0)
		{
			auto it = a.find(ord.begin() -> second);
			ord.erase(ord.begin());
			if(it == a.end()) continue;
			
			int x = it -> first, t = it -> second;
			a.erase(it++);
			while(it != a.end()
			   && it -> first % 2 == 0
			   && it -> first - x - (tag + k) * 2 <= 0
			   && t != 0)
			{
				int cur = min(it -> second, t);
				it -> second -= cur;
				t -= cur;
				ans -= cur;
				if(it -> first - x - (tag + k) * 2 == -1)
					eqpos[(x + tag + k) / 2] += cur;
				if(!it -> second) a.erase(it++);
			}
			if(t != 0) a.emplace(x, t);
			trim(it, 1);
		}
		tag += k;
	}
	int geteq(int x,int t)
	{
		int y = x ^ 1;
		y += (y & 1)? - tag: tag;
		auto it = a.find(y);
		if(it == a.end()) return 0;
		
		int cur = min(t, it -> second);
		it -> second -= cur;
		t -= cur;
		ans -= cur;
		eqpos[x / 2] += cur;
		if(!it -> second)
		{
			trim(it, 0);
			a.erase(it++);
			trim(it, 1);
		}
		return cur;
	}
	void insert(int x,int t)
	{
		if(!t) return;
		x += (x & 1)? - tag: tag;
		auto it = a.find(x);
		if(it != a.end()){ a[x] += t; return;}
		it = a.upper_bound(x);
		trim(it, 0);
		auto jt = a.emplace_hint(it, x, t);
		if(!(x & 1)) it = jt;
		trim(it, 1);
	}
	void merge(Data &oth)
	{
		for(auto it: oth.a)
		{
			int x = it.first, t = it.second;
			x += (x & 1)? oth.tag: - oth.tag;
			t -= geteq(x, t);
			insert(x, t);
		}
	}
	void finish(void)
	{
		int sta = 0;
		for(pii it: a)
		{
			if(it.first & 1) sta += it.second;
			else
			{
				int cur = min(sta, it.second);
				sta -= cur; ans -= cur;
			}
		}
	}
};
map<int,int> Data::eqpos;

Data* f[MAXN];

void dfs_tree(int u,int fa)
{
	for(pii it: g[u]) if(it.first != fa)
		dfs_tree(it.first, u);
	
	Data *res = new Data();
	Data::eqpos.clear();
	for(pii it: g[u]) if(it.first != fa)
	{
		int v = it.first, w = it.second;
		Data *cur = f[v];
		cur -> add(w);
		if(res -> size() < cur -> size()) swap(res, cur);
		res -> merge(*cur);
		delete cur;
	}
	
	for(pii it: qrys[u])
	{
		if(Data::eqpos.count(it.first))
		{
			auto oth = Data::eqpos.find(it.first);
			int cur = min(it.second, oth -> second);
			it.second -= cur;
			oth -> second -= cur;
			ans -= cur;
			if(!it.second) continue;
		}
		
		int x = it.first << 1, tx = it.second;
		int y = it.first << 1 | 1, ty = it.second;
		tx -= res -> geteq(x, tx);
		ty -= res -> geteq(y, ty);
		res -> insert(x, tx);
		res -> insert(y, ty);
		
		Data::eqpos.erase(it.first);
	}
	f[u] = res;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	int Q;
	scanf("%d",&Q);
	for(int i=1; i<=Q; ++i)
	{
		int x, y, u;
		scanf("%d%d%d",&x,&y,&u);
		ans += y;
		qrys[u].emplace_back(x, y);
	}
	
	dfs_tree(1,0);
	f[1] -> finish();
	
	printf("%d\n",ans);
	return 0;
}