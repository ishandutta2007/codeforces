#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

const int MN = 1e5+10;
const double INF = 0x3f3f3f3f;
const double EPS = 1e-4;

bool equ(const double& a, const double& b) {return std::abs(a-b)<EPS;}
struct Edge
{
	public:
		int n, w;
};

struct Rule
{
	public:
		int m, b;
		bool operator == (const Rule& o) const {return m==o.m && b==o.b;}
		double operator () (const double& x) const {return m*x+b;}
};

int N, M;
double val[MN], X;
bool vis[MN], bad;
std::vector<Edge> a[MN];
std::vector<int> cur;
Rule rule[MN];

void dfs(int n, const Rule& r)
{
	if(vis[n])
	{
		if(rule[n]==r) return;
		else if(rule[n].m==r.m)
			bad=1;
		else
		{
			double x=(double)(r.b-rule[n].b)/(rule[n].m-r.m);
			if(equ(x,X) || equ(X, INF))
				X=x;
			else
				bad=1;
		}
	}
	else
	{
		vis[n]=1;
		cur.push_back(n);
		rule[n]=r;
		for(auto x:a[n])
		{
			dfs(x.n, {-r.m, x.w-r.b});
			if(bad)
				break;
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0,x,y,v;i<M;++i)
	{
		scanf("%d%d%d", &x, &y, &v);
		a[x].push_back({y,v});
		a[y].push_back({x,v});
	}
	for(int i=1;i<=N;++i)
		if(!vis[i])
		{
			X=INF;
			cur.clear();
			dfs(i, {1,0});
			if(bad)
				break;
			if(equ(X, INF))
			{
				std::vector<int> tmp;
				for(int n:cur)
					tmp.push_back(-rule[n].m*rule[n].b);
				std::nth_element(tmp.begin(), tmp.begin()+tmp.size()/2, tmp.end());
				X=tmp[tmp.size()/2];
			}
			for(int n:cur)
				val[n]=rule[n](X);
		}
	if(bad)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for(int i=1;i<=N;++i)
			printf("%.8lf%c", val[i], " \n"[i==N]);
	}
	return 0;
}