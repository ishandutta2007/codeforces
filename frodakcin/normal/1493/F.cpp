#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

int N, M;
struct PF
{
	public:
		int p, a;
};

std::vector<PF> factorize(int a)
{
	std::vector<PF> f;
	for(int i=2;a>1;++i)
		if(a%i==0)
		{
			f.push_back({i, 1});
			for(a/=i;a%i==0;a/=i)
				++f.back().a;
		}
	return f;
}

bool query(int a, int b, int c, int d, int e, int f)
{
	printf("? %d %d %d %d %d %d\n", a, b, c+1, d+1, e+1, f+1);
	fflush(stdout);
	int r; scanf("%d", &r); return r;
}

template<bool dir> bool test(int l, int d)
{
	assert(d>1);
	if(dir) // query along M
	{
		for(int i=31-__builtin_clz(d-1);i>=0;--i)
		{
			int ht = std::min(1<<i+1, d)-(1<<i); ht *= l;
			int ct = l<<i;
			if(!query(N, ht, 0, ct-ht, 0, ct))
				return 0;
		}
		return 1;
	}
	else // query along N
	{
		for(int i=31-__builtin_clz(d-1);i>=0;--i)
		{
			int ht = std::min(1<<i+1, d)-(1<<i); ht *= l;
			int ct = l<<i;
			if(!query(ht, M, ct-ht, 0, ct, 0))
				return 0;
		}
		return 1;
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	int h=N, w=M, ans=1;
	{
		auto f=factorize(N);
		for(auto x:f)
		{
			int ctr=0;
			for(int i=0;i<x.a;++i)
				if(test<0>(h/x.p, x.p))
					h/=x.p, ++ctr;
				else
					break;
			ans *= ctr+1;
		}
	}
	{
		auto f=factorize(M);
		for(auto x:f)
		{
			int ctr=0;
			for(int i=0;i<x.a;++i)
				if(test<1>(w/x.p, x.p))
					w/=x.p, ++ctr;
				else
					break;
			ans *= ctr+1;
		}
	}
	printf("! %d\n", ans);
	return 0;
}