#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXD = MAXN * 2;

inline int Abs(int x){ return x<0? -x: x;}

int fa[MAXN];
inline void dsu_init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
int find(int u){ return fa[u]==u? u: fa[u]=find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

struct Node
{
	int x,y;
}p[MAXN];

int dsc[MAXD], dcnt = 0;

inline bool cmp_x(const int a,const int b){ return p[a].x < p[b].x;}
inline bool cmp_y(const int a,const int b){ return p[a].y < p[b].y;}
inline int get_y_dis(int u,int v){ return Abs(dsc[p[v].y] - dsc[p[u].y]);}
inline int get_x_dis(int u,int v){ return Abs(dsc[p[v].x] - dsc[p[u].x]);}

struct Edge_uvw
{
	int u,v,w;
}ee[MAXN*4];
int m = 0;

int n;

int has[MAXD][MAXD];
int le[MAXD][MAXD], ri[MAXD][MAXD], up[MAXD][MAXD], down[MAXD][MAXD];

bool check(ll lim)
{
	dsu_init(n);
	
	int blocks = n;
	for(int i=1; i<=m; ++i)
	{
		if(ee[i].w > lim) continue;
		int u = ee[i].u, v = ee[i].v;
		if(find(u) == find(v)) continue;
		connect(u,v); --blocks;
	}
	if(blocks <= 1) return 1;
	if(blocks >= 5) return 0;
	
	for(int i=1; i<=dcnt; ++i)
		for(int j=1; j<=dcnt; ++j) if(!has[i][j])
		{
			set<int> rt;
			if(le[i][j] && dsc[j] - dsc[p[le[i][j]].y] <= lim) rt.insert(find(le[i][j]));
			if(ri[i][j] && dsc[p[ri[i][j]].y] - dsc[j] <= lim) rt.insert(find(ri[i][j]));
			if(up[i][j] && dsc[i] - dsc[p[up[i][j]].x] <= lim) rt.insert(find(up[i][j]));
			if(down[i][j] && dsc[p[down[i][j]].x] - dsc[i] <= lim) rt.insert(find(down[i][j]));
			
			if(blocks - (int)rt.size() + 1 == 1) return 1;
		}
	
	if(blocks == 2)
	{
		for(int i=1; i<=m; ++i)
		{
			int u = ee[i].u, v = ee[i].v, w = ee[i].w;
			if(find(u) == find(v)) continue;
			if((w-2+1)/2 + 1 <= lim) return 1;
		}
	}
	
	return 0;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].x,&p[i].y);
	
	for(int i=1; i<=n; ++i)
		dsc[++dcnt] = p[i].x,
		dsc[++dcnt] = p[i].y;
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	for(int i=1; i<=n; ++i)
		p[i].x = lower_bound(dsc+1,dsc+dcnt+1, p[i].x) - dsc,
		p[i].y = lower_bound(dsc+1,dsc+dcnt+1, p[i].y) - dsc;
	
	static vector<int> row[MAXD], col[MAXD];
	for(int i=1; i<=n; ++i)
		row[p[i].x].push_back(i),
		col[p[i].y].push_back(i);
	
	for(int i=1; i<=dcnt; ++i)
	{
		vector<int> &vec = row[i];
		sort(vec.begin(),vec.end(),cmp_y);
		for(int j=1; j<(int)vec.size(); ++j)
			ee[++m] = (Edge_uvw){ vec[j-1], vec[j], get_y_dis(vec[j-1], vec[j])};
	}
	for(int i=1; i<=dcnt; ++i)
	{
		vector<int> &vec = col[i];
		sort(vec.begin(),vec.end(),cmp_x);
		for(int j=1; j<(int)vec.size(); ++j)
			ee[++m] = (Edge_uvw){ vec[j-1], vec[j], get_x_dis(vec[j-1], vec[j])};
	}
	
	for(int i=1; i<=n; ++i)
	{
		int x = p[i].x, y = p[i].y;
		has[x][y] = le[x][y] = ri[x][y] = up[x][y] = down[x][y] = i;
	}
	for(int i=1; i<=dcnt; ++i)
	{
		for(int j=1; j<=dcnt; ++j)
			if(!has[i][j])  le[i][j] = le[i][j-1];
		for(int j=dcnt; j>=1; --j)
			if(!has[i][j])  ri[i][j] = ri[i][j+1];
	}
	for(int j=1; j<=dcnt; ++j)
	{
		for(int i=1; i<=dcnt; ++i)
			if(!has[i][j]) up[i][j] = up[i-1][j];
		for(int i=dcnt; i>=1; --i)
			if(!has[i][j]) down[i][j] = down[i+1][j];
	}
	
	ll l=1, r=2e9;
	if(!check(r)) return printf("-1"), 0;
	while(l<r)
	{
		ll mid = (l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld",l);
	return 0;
}