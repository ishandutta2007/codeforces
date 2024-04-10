#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const int MAXX = 1e4 + 5;

struct BIT
{
	int tree[MAXX];
	#define lowbit(x) ((x)&-(x))
	inline void clear(void){ memset(tree,0,sizeof(tree));}
	inline void update(int x,int k)
	{
		while(x<MAXX)
			tree[x] += k,
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline int query(int l,int r){ return query(r) - query(l-1);}
}tree;

struct Line
{
	int x,sy,ey;
};
inline bool cmp(const Line &p,const Line &q){ return p.x<q.x;}
vector<Line> r,c;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int sx,sy, ex,ey;
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		sx += 5000 + 1;
		sy += 5000 + 1;
		ex += 5000 + 1;
		ey += 5000 + 1;
		
		if(sx == ex)
			r.push_back((Line){ sx, min(sy,ey), max(sy,ey)});
		else
			c.push_back((Line){ sy, min(sx,ex), max(sx,ex)});
	}
	
	sort(r.begin(),r.end(),cmp);
	
	ll ans = 0;
	for(int i=0; i<(int)r.size(); ++i)
	{
		int x = r[i].x, sy = r[i].sy, ey = r[i].ey;
		
		static vector<pii> vec;
		vec.clear();
		
		tree.clear();
		for(int j=0; j<(int)c.size(); ++j)
			if(c[j].x >= sy && c[j].x <= ey && x >= c[j].sy && x <= c[j].ey)
				tree.update(c[j].x, 1),
				vec.push_back(make_pair(c[j].sy-1, c[j].x));
		
		sort(vec.begin(), vec.end());
		for(int j=i-1, k=(int)vec.size()-1; j>=0 && k>=0; --j)
		{
			while(k>=0 && vec[k].first >= r[j].x)
				tree.update(vec[k].second, -1),
				--k;
			
			int l = max(sy, ::r[j].sy);
			int r = min(ey, ::r[j].ey);
			if(l>r) continue;
			int cnt = tree.query(l,r);
			
			ans += cnt * (cnt-1) / 2;
		}
	}
	printf("%lld",ans);
	return 0;
}