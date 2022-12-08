#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <numeric>

//all of these bounds have no padding!
const int MN = 1<<12, MQ = 1<<16;
const int S = 1<<8, B = 1<<4;

struct mrg
{
public:
	int a,b;
	void out() {printf("%d %d\n", a, b);}
};
std::vector<mrg> f;
std::vector<int> g;
int N, M, Q, cnt, a[MN], b[MN];

int get(int a, int b)
{
	if(!~a) return b;
	if(!~b) return a;
	f.push_back({a,b});
	return ++cnt;
}
struct blk
{
public:
	int N, L, R;
	std::vector<int> v;
	std::vector<std::vector<int> > f;//f[l][r-l] as opposed to f[l][r]. Inc/inc for memory
	blk *l, *r;
	blk(){}
	blk(int _L, int _R) : L(_L), R(_R)
	{
		//printf("%d %d\n", _L, _R);
		N=R-L;
		v.resize(N, -1);
		f.resize(N, {});
		std::iota(v.begin(), v.end(), L);
		assert(N>0);
		std::sort(v.begin(), v.end(), [](int s, int t){return b[s]<b[t];});
		int M=L+(R-L)/2;
		//printf("%d %d %d: HERE\n", N, L, R);
		if(R-L>1)
		{
			l = new blk(L, M);
			r = new blk(M, R);
		}
		for(int i=0;i<N;++i)
		{
			f[i].assign(N-i, -5);
			f[i][0] = b[v[i]];
			for(int j=1;i+j<N;++j)
				f[i][j] = get(l->ans(b[v[i]], b[v[i+j]]), r->ans(b[v[i]], b[v[i+j]]));
		}
		//printf("%d %d %d: HERE\n", N, L, R);
	}
	int ans(int l, int r)//[l,r] for simplicity above
	{
		int i,j;
		for(i=0;i<N&&b[v[i]]<l;++i);
		for(j=i;j<N&&b[v[j]]<=r;++j);
		//printf("\t b[v[0]] = %d\n", b[v[0]] <= r);
		//printf("N:%d, %d %d (%d %d) %d %d\n", N, l, r, L, R, i, j);
		if(i<j) return f[i][j-i-1];
		return -1;
	}
} v[B];
int main()
{
	scanf("%d%d", &N, &Q);
	cnt=N;
	for(int i=0;i<N;++i)
		scanf("%d", a+i), b[--a[i]]=i+1;
	M=(N+S-1)/S;
	assert(M <= B);
	for(int i=0;i<M;++i)
		v[i] = blk(i*S, std::min((i+1)*S, N));
	for(int i=0,l,r;i<Q;++i)
	{
		int c=-1;
		scanf("%d%d", &l, &r);
		for(int j=0;j<M;++j)
			c = get(c, v[j].ans(l,r));
		g.push_back(c);
	}
	printf("%d\n", cnt);
	for(auto x:f) x.out();
	assert(g.size()==Q);
	for(int i=0;i<Q;++i) printf("%d%c", g[i], " \n"[i+1==Q]);
	return 0;
}