#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using ll = long long;

struct pt
{
	public:
		int x,y;
		pt(int _x=0, int _y=0): x(_x), y(_y) {}

		bool operator == (const pt& o) const {return x==o.x&&y==o.y;}
		bool operator != (const pt& o) const {return x!=o.x||y!=o.y;}
		int sum() const {return x+y;}

		void out() {printf("(%d %d)", x, y);}
		void in() {scanf("%d%d", &x, &y);}
};

pt move(pt n)
{
	if(!n.y) return {n.x-1, n.y};
	if(!n.x) return {n.x, n.y-1};
	int dx=-n.x&n.x, dy=-n.y&n.y;
	if(dx<dy) return {n.x-1, n.y};
	else return {n.x, n.y-1};
}

int all(int v)
{
	return v?(1<<31-__builtin_clz(v))-1:0;
}

pt lca(pt a, pt b)
{
	pt f;
	for(int k=30, ak, bk;k>=0;--k)
	{
		if(a.x>>k&1) a.x^=1<<k, ak=1;
		else if(a.y>>k&1) a.y^=1<<k, ak=2;
		else ak=0;

		if(b.x>>k&1) b.x^=1<<k, bk=1;
		else if(b.y>>k&1) b.y^=1<<k, bk=2;
		else bk=0;

		if(!ak&&!bk) continue;
		if(ak&&bk)
		{
			if(ak==bk)
			{
				(ak==1?f.x:f.y)|=1<<k;
				continue;
			}
			break;
		}
		if(ak==1) f.x|=b.x&~(all(b.y));
		if(ak==2) f.y|=b.y&~(all(b.x));
		if(bk==1) f.x|=a.x&~(all(a.y));
		if(bk==2) f.y|=a.y&~(all(a.x));
		break;
	}
	return f;
}
 
bool anc(pt p, pt c) // is p an ancestor of c?
{
	return lca(p,c)==p;
}


bool cmpmap(const pt& a, const pt& b) {return a.x<b.x || !(b.x<a.x) && a.y < b.y;}
bool cmppre(const pt& a, const pt& b) // log n
{
	if(a==b) return 0;
	pt l=lca(a,b);
	return a==l || b!=l && anc({l.x+1, l.y}, a); // (l.x | l.y)&1 MUST == 0 if a!=l and b!=l
}

struct evt
{
	public:
		int t,d;
		evt(int _t=0, int _d=0): t(_t), d(_d) {}
		bool operator < (const evt& o) const {return t<o.t;}
};
const int MM = 1e5+10;

int M, N;
std::map<pt, int, decltype(*cmpmap)> map(cmpmap);
std::vector<pt> pts;
std::vector<int> a[MM*6]; // 3 nodes/path, double for virt tree
std::vector<evt> evts;

int dfs(int n)
{
	int v=map[pts[n]];
	for(int x:a[n])
	{
		//pts[n].out(); printf(" -> "); pts[x].out(); printf("\n");
		int w=dfs(x);
		if(w)
		{
			evts.emplace_back(pts[n].sum(), 1);
			evts.emplace_back(pts[x].sum(), -1);
		}
		v+=w;
	}
	if(n==0 && v)
	{
		evts.emplace_back(pts[n].sum()-1, 1);
		evts.emplace_back(pts[n].sum(), -1);
	}
	assert(v>=0);
	return v;
}

int main()
{
	//lca({9, 6}, {5, 2}).out(); //8, 4
	//return 0;
	scanf("%d", &M);
	for(int i=0;i<M;++i)
	{
		pt a, b;
		a.in(), b.in();
		pt l=lca(a,b);
		map[a]++;
		map[b]++;
		map[l]--;
		if(l!=pt(0,0))
		{
			l=move(l);
			map[l]--;
			pts.push_back(l);
		}

		pts.push_back(a);
		pts.push_back(b);
	}

	pts.push_back({0,0});
	std::sort(pts.begin(), pts.end(), cmppre);
	pts.resize(std::distance(pts.begin(), std::unique(pts.begin(), pts.end())));

	for(int i=1, mi=pts.size();i<mi;++i)
		pts.push_back(lca(pts[i], pts[i-1]));
	std::sort(pts.begin(), pts.end(), cmppre);
	pts.resize(std::distance(pts.begin(), std::unique(pts.begin(), pts.end())));
	//for(auto x:pts) x.out(), printf("\n");

	//construct virtual tree (overkill? i can't think of easier way to solve this prob...)
	N=pts.size();
	{
		std::stack<int> q;
		q.push(0);
		for(int i=1;i<pts.size();++i)
		{
			for(;!anc(pts[q.top()], pts[i]);) q.pop(); // q cannot be empty because 0 is anc of everything
			a[q.top()].push_back(i);
			q.push(i);
		}
	}

	dfs(0);
	std::sort(evts.begin(), evts.end());
	//for(auto x:evts) printf("[%3d: %3d]\n", x.t, x.d);
	int f=0;
	bool pr=0;
	for(int i=0,j=0, c=0;i<evts.size();i=j)
	{
		for(;j<evts.size() && evts[i].t==evts[j].t;++j) c+=evts[j].d;
		if(!i) pr=c&1;
		//printf("%d\n", pr);
		if((c&1)!=pr)
			pr=c&1, ++f;
	}
	f+=pr;
	
	printf("%d\n", f);
	return 0;
}