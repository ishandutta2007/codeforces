#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>

template<class T> bool ckmax(T *a, T b) {return *a<b?*a=b,1:0;}
template<class T> bool ckmin(T *a, T b) {return b<*a?*a=b,1:0;}

const int MN = 2e5 + 100, MQ = 2e5 + 100;
int N, Q, a[MN], L, R;
int v[MN], V;
std::vector<int> dec, inc;
std::set<int> mid;
bool drop[MN];
struct ans4
{
public:
	int x, y, l;
	ans4(int x = 0, int y = 0, int l = -1) : x(x), y(y), l(l) {}
};
ans4 b[MN];
int c[MN];
int ni[MN], nd[MN];
int binsearch(const std::vector<int>&b , int v)
{
	int l = -1, r = b.size(), m;
	for(;r-l>1;)
	{
		m = l+(r-l)/2;
		if(a[b[m]] == v) r = m;
		else l = m;
	}
	return l;
}
int main(void)
{
	scanf("%d%d", &N, &Q);
	for(int i = 0;i < N;++i)
		scanf("%d", a+i), v[i] = a[i];
	std::sort(v, v+N);
	V = std::unique(v, v+N) - v;
	for(int i = 0;i < N;++i)
		a[i] = std::lower_bound(v, v+V, a[i])-v;
	for(int i = 0;i < N;++i)
	{
		for(;!dec.empty() && a[dec.back()] < a[i];dec.pop_back())
			if(!ckmax(drop+dec.back(), true))
				mid.insert(dec.back());
		for(;!inc.empty() && a[i] < a[inc.back()];inc.pop_back())
			if(!ckmax(drop+inc.back(), true))
				mid.insert(inc.back());
		dec.push_back(i);
		inc.push_back(i);

		if(!dec.empty() && !inc.empty() && !mid.empty())
		{
			int indd, indi;
			if(!~(indd = binsearch(dec, a[i])) || !~(indi = binsearch(inc, a[i])))
				continue;
			std::set<int>::iterator it = mid.lower_bound(std::min(dec[indd], inc[indi]));
			if(it != mid.begin())
			{
				int L = *--it;
				b[i] = {*std::lower_bound(dec.begin(), dec.end(), L), *std::lower_bound(inc.begin(), inc.end(), L), L};
			}
		}
	}
	for(int i = 0;i < N;++i)//check
		if(~b[i].l)
		{
			assert(b[i].l < b[i].x && b[i].x < i);
			assert(b[i].l < b[i].y && b[i].x < i);
			assert(a[b[i].l] < a[b[i].x] && a[i] < a[b[i].x]);
			assert(a[b[i].l] > a[b[i].y] && a[i] > a[b[i].y]);
		}
	for(int i = 0;i < N;++i)
		c[i] = i;
	for(int i = 1;i < N;++i)
		if(~b[i-1].l && (!~b[i].l || b[i].l < b[i-1].l))
			b[i] = b[i-1], c[i] = c[i-1];
	for(int i = 1;i < N;++i)
	{
		ni[i] = ni[i-1];
		nd[i] = nd[i-1];
		if(a[i] > a[i-1])
			ni[i] = i;
		if(a[i] < a[i-1])
			nd[i] = i;
	}
	for(int i = 0;i < Q;++i)
	{
		scanf("%d%d", &L, &R), --L, --R;
		if(L <= b[R].l)
		{
			printf("4\n%d %d %d %d\n", b[R].l+1, std::min(b[R].x, b[R].y)+1, std::max(b[R].x, b[R].y)+1, c[R]+1);
			continue;
		}
		if(ni[R] > L && nd[R] > L)
		{
			printf("3\n");
			if(ni[R] < nd[R])
				if(a[ni[R]] > a[nd[R]])
					printf("%d %d %d\n", ni[R], ni[R]+1, nd[R]+1);
				else
					printf("%d %d %d\n", ni[R], nd[R], nd[R]+1);
			else
				if(a[nd[R]] < a[ni[R]])
					printf("%d %d %d\n", nd[R], nd[R]+1, ni[R]+1);
				else
					printf("%d %d %d\n", nd[R], ni[R], ni[R]+1);
			continue;
		}
		printf("0\n");
	}
	return 0;
}