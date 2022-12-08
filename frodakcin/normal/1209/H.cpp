#include <cstdio>
#include <cassert>
#include <cmath>
#include <map>

using ld = long double;
const ld EPS = 1e-12;
const ld INF = 1e12;

const int MN = 4e5+100;
int M, N, L;
ld tt, tl;
struct range
{
public:
	ld s;//actually stores s+1
	int l;
} a[MN];

bool equ(ld a, ld b)  {return fabs(a-b)<EPS;}
bool cmp(ld a, ld b)  {return EPS<b-a;}//a<b
bool cmp2(ld a, ld b) {return EPS<a-b;}//a>b
std::map<ld, ld, decltype(*cmp2)> map(cmp2);
int main()
{
	scanf("%d%d", &M, &L);
	{
		int p=0;
		double s;
		for(int i=0,x,y;i<M;++i)
		{
			scanf("%d%d", &x, &y);
			if(p<x)
				a[N++]={(ld)1,x-p};
			scanf("%lf", &s);
			a[N++]={(ld)s+1,y-x};
			p=y;
		}
		if(p<L)
			a[N++]={(ld)1,L-p};
	}
	map[(ld)1.] = INF;
	for(int i=0;i<N;++i)
	{
		tl += a[i].l*(1-(a[i].s/(a[i].s+1)));
		tt += a[i].l/(a[i].s+1);
		if(!equ(a[i].s,1))
			map[a[i].s]+=a[i].l/(a[i].s-1)-a[i].l/(a[i].s+1);
		for(auto it=map.begin();tl>EPS;)
		{
			assert(it != map.end());
			if(cmp(tl,it->first*it->second))
			{
				tt += tl/it->first;
				it->second -= tl/it->first;
				tl=0;
				break;
			}
			else
			{
				tt += it->second;
				tl -= it->first*it->second;
				it = map.erase(it);
			}
		}
	}
	printf("%.15lg\n", (double)tt);
	return 0;
}