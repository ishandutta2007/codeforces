#include <cstdio>
#include <cassert>
#include <algorithm>

using ll = long long;
const ll INF = 4e18;
const int MN = 1e5+10;

int N;
ll a[MN], b[MN], K;
struct pick
{
public:
	ll v;
	int i;
	bool operator < (pick o) const {return v > o.v;}
};
pick c[MN];

ll binsearch(ll v, ll d)
{
	ll l=0, r=v+1, m;
	for(;r-l>1;)
	{
		m=l+(r-l)/2;
		if(v-3*m*m-3*m-1 < d)
			r=m;
		else
			l=m;
	}
	return l;
}
int main(void)
{
	scanf("%d%lld", &N, &K);
	for(int i=0;i<N;++i)
		scanf("%lld", a+i);
	ll l=-INF, r=INF, m, tot;
	for(;r-l>1;)
	{
		m=l+(r-l)/2;
		tot = 0;
		for(int i=0;i<N;++i)
			b[i] = binsearch(a[i], m), tot+=b[i];
		if(tot<K)
			r=m;
		else
			l=m;
	}
	//printf("MDIF = %lld\n", r);
	tot = 0;
	for(int i=0;i<N;++i)
	{
		b[i]=binsearch(a[i], r);
		tot += b[i];
		if(b[i] == a[i])
			c[i] = {-INF, i};
		else
			c[i] = {a[i]-3*b[i]*b[i]-3*b[i]-1, i};
	}
	//assert(tot <= K);
	//assert(tot+N >= K);
	std::sort(c, c+N);
	for(int i=0;tot < K;++tot,++i)
		++b[c[i].i];
	//assert(tot == K);
	for(int i=0;i<N;++i)
		printf("%lld%c", b[i], " \n"[i+1==N]);
	return 0;
}