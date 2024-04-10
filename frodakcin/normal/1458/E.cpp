#include <cstdio>
#include <cassert>
#include <set>
#include <algorithm>

const int MN = 1e5+10;
const int INF = 0x3f3f3f3f;

int N, M, x[MN], y[MN];

struct dat
{
	public:
		int x, i;
		bool operator < (const dat& o) const {return x<o.x||!(o.x<x)&&i<o.i;}
};
std::set<dat> xm, ym;
std::set<dat> L;

struct dia
{
	public:
		int x, y, l;
		bool operator < (const dia& o) const {return x<o.x;}
};
std::set<dia> set;

bool loss(int u, int v)
{
	if(L.find({u,v})!=L.end()) return 1;
	auto it=set.upper_bound({u, -1, -1});
	if(it == set.begin()) return 0;
	--it;
	if(u-v == it->x-it->y && u-it->x<it->l) return 1;
	return 0;
}
void rem(int i)
{
	auto it=xm.find({x[i], i});
	if(it != xm.end()) xm.erase(it);
	it=ym.find({y[i], i});
	if(it != ym.end()) ym.erase(it);
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<N;++i)
	{
		scanf("%d%d", x+i, y+i);
		xm.insert({x[i], i});
		ym.insert({y[i], i});
		L.insert({x[i], y[i]});
	}

	for(int u=0, v=0;;)
	{
		for(bool ok=1;ok;)
		{
			ok=0;
			for(;!xm.empty() && xm.begin()->x <= u;)
			{
				int i=xm.begin()->i;
				if(x[i]==u)
				{
					if(y[i]<=v) ++u, ok=1;
					if(y[i]==v) ++v;
				}
				xm.erase(xm.begin());
			}

			for(;!ym.empty() && ym.begin()->x <= v;)
			{
				int i=ym.begin()->i;
				if(y[i]==v)
				{
					if(x[i]<=u) ++v, ok=1;
					if(x[i]==u) ++u;
				}
				ym.erase(ym.begin());
			}
		}

		if(xm.empty() && ym.empty())
		{
			auto z=set.insert({u, v, INF});
			assert(z.second);
			break;
		}
		int t=std::min(xm.empty()?INF:xm.begin()->x-u, ym.empty()?INF:ym.begin()->x-v);
		auto z=set.insert({u, v, t});
		assert(z.second);
		u+=t, v+=t;
	}

	//for(auto x:set) printf("%d %d %d\n", x.x, x.y, x.l);

	for(int i=0;i<M;++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(loss(a, b))
			printf("LOSE\n");
		else
			printf("WIN\n");
	}
	return 0;
}