#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
const int MAXP = 2 * (MAXN + MAXM);
const int MAXE = 2 * (MAXN + MAXM);

mt19937 rnd((unsigned long long)new char ^ time(0));
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
int base1 = rnd() >> 1, base2 = rnd() >> 1;

vector< array<int,3> > g[MAXP];
array<int,3> es[MAXE];
int etot = 0;
inline int add_edge(int u,int v,int w)
{
	es[++etot] = {u,v,w};
	g[u].push_back({v, w, etot});
	g[v].push_back({u, w, etot});
	return etot;
}

vector<int> getmin1(vector<int> id)
{
	int len = (int)id.size();
	vector<int> a(2 * len);
	for(int i=0; i<len; ++i) a[i] = a[i+len] = es[id[i]][2];
	
	int i=0, j=1;
	while(i<len && j<len)
	{
		int k = 0;
		while(k<len && a[i+k] == a[j+k]) ++k;
		if(k == len) break;
		if(a[i+k] > a[j+k]) i += k+1;
		else j += k+1;
		if(i == j) ++j;
	}
	int pos = min(i, j);
	assert(0 <= pos && pos < len);
	rotate(id.begin(), id.begin() + pos, id.end());
	return id;
}
vector<int> getmin2(const vector<int> &id)
{
	auto A = getmin1(id), B = getmin1(vector<int>(id.rbegin(), id.rend()));
	for(int i=0; i<(int)A.size(); ++i)
		if(es[A[i]][2] != es[B[i]][2])
			return es[A[i]][2] < es[B[i]][2]? A: B;
	return A;
}

vector<int> getpt(const vector<int> &id)
{
	int len = (int)id.size();
	assert(len >= 1);
	if(len == 1) return {es[id[0]][0]};
	int lst = -1;
	for(int k=0; k<=1; ++k)
		if(es[id[0]][k] == es[id[1]][0] || es[id[0]][k] == es[id[1]][1])
			lst = max(lst, es[id[0]][k ^ 1]);
	vector<int> res;
	for(int e: id)
		res.push_back(lst ^= es[e][0] ^ es[e][1]);
	return res;
}

pii gethash(const vector<int> &id)
{
	int res1 = 0, res2 = 0;
	for(int e: id)
		res1 = ((ll)res1 * base1 + es[e][2]) %mod1,
		res2 = ((ll)res2 * base2 + es[e][2]) %mod2;
	return {res1, res2};
}

bool vis[MAXP];
void dfs_cir(int u,vector<int> &cir)
{
	vis[u] = 1;
	for(auto it: g[u]) if(!vis[it[0]])
		cir.push_back(it[2]),
		dfs_cir(it[0], cir);
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	auto getid = [&] (int stage,int type,int i)
	{
		return i + (type? n: 0) + (stage? n+m: 0);
	};
	auto getw = [&] (char c1,char c2)
	{
		if(c1 > c2) swap(c1, c2);
		return c1 * 1000 + c2;
	};
	
	map<int,int> cnt;
	for(int i=1; i<=n+m; ++i)
	{
		static char s1[10], s2[10];
		int x, y;
		scanf("%s%s%d%d",s1,s2,&x,&y);
		int u = getid(0, *s1 == 'T' || *s1 == 'B', x);
		int v = getid(0, *s2 == 'T' || *s2 == 'B', y);
		int w = getw(*s1, *s2);
		add_edge(u, v, w);
		++cnt[w];
	}
	
	if(cnt[getw('T', 'B')] && cnt[getw('L', 'R')])
		return printf("No solution"), 0;
	for(char c1: {'T', 'B'}) for(char c2: {'L', 'R'})
	{
		int rem = cnt[getw(c1, c2)];
		int x = c2 == 'L'? 1: m, kx = c2 == 'L'? 1: -1;
		int y = c1 == 'T'? 1: n, ky = c1 == 'T'? 1: -1;
		
		int u = getid(1, 1, x), v = getid(1, 0, y), w = getw(c1, c2);
		for(; rem; u += kx, v += ky, --rem)
			add_edge(u, v, w);
	}
	{
		int rem = cnt[getw('T', 'B')];
		int x = cnt[getw('L', 'T')] + 1, y = cnt[getw('L', 'B')] + 1;
		
		int u = getid(1, 1, x), v = getid(1, 1, y), w = getw('T', 'B');
		for(; rem; ++u, ++v, --rem)
			add_edge(u, v, w);
	}
	{
		int rem = cnt[getw('L', 'R')];
		int x = cnt[getw('L', 'T')] + 1, y = cnt[getw('R', 'T')] + 1;
		
		int u = getid(1, 0, x), v = getid(1, 0, y), w = getw('L', 'R');
		for(; rem; ++u, ++v, --rem)
			add_edge(u, v, w);
	}
	
	vector< pair< pii, vector<int> > > fir, sec;
	for(int rt=1; rt<=2*(n+m); ++rt) if(!vis[rt])
	{
		vector<int> cir;
		dfs_cir(rt, cir);
		cir.push_back(g[rt][1][2]);
		cir = getmin2(cir);
		(rt <= n+m? fir: sec).emplace_back(gethash(cir), getpt(cir));
	}
	sort(fir.begin(), fir.end());
	sort(sec.begin(), sec.end());
	
	if(fir.size() != sec.size())
		return printf("No solution"), 0;
	
	static int ans[MAXP];
	for(int i=0; i<(int)fir.size(); ++i)
	{
		if(fir[i].first != sec[i].first)
			return printf("No solution"), 0;
		vector<int> &vec1 = fir[i].second;
		vector<int> &vec2 = sec[i].second;
		assert(vec1.size() == vec2.size());
		for(int j=0; j<(int)vec1.size(); ++j)
			ans[vec2[j] - (n+m)] = vec1[j];
	}
	
	for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
	putchar('\n');
	for(int i=1; i<=m; ++i) printf("%d ",ans[i+n]-n);
	return 0;
}