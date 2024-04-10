#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using ll = long long;

bool ckmax(auto& a, auto const& b) {return b>a?a=b,1:0;}
bool ckmin(auto& a, auto const& b) {return b<a?a=b,1:0;}

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MV = 5e4+10;
const int MN = 5e4+10;
const int B = 100;
const int C = 500;

int gcd(int a, int b)
{
	while(a)
	{
		b %= a;
		std::swap(a, b);
	}
	return b;
}
ll getval(int a, int b)
{
	int g = gcd(a, b);
	return (ll)a*b/((ll)g*g);
}

std::vector<int> divisors[MV], pdiv[MV];
struct Block
{
	public:
		int sz, b[B], z, a[B];
		ll c[B];
		ll ans, all[MV];
		void init(int _sz, int *_a, int *_b)
		{
			z = 0;
			sz = _sz;
			ans = INF;
			for(int i=0;i<sz;++i)
				ckmin(ans, c[i]=getval(a[i]=_a[i], b[i]=_b[i]));
			//printf("%lld (%d)\n", ans, sz);

			memset(all, 0x3f, sizeof all);
			for(int i=0;i<sz;++i)
				for(int g:divisors[b[i]])
					ckmin(all[g], (ll)b[i]/g);
			for(int i=2;i<MV;++i)
				for(int g:pdiv[i])
					ckmin(all[i], (ll)all[i/g]*g);
		}
		void upd(int l, int r, int v)
		{
			if(l <= 0 && sz <= r)
			{
				z = v;
				ans = all[v];
			}
			else
			{
				if(z)
				{
					for(int i=0;i<l;++i)
						c[i]=getval(a[i]=z, b[i]);
					for(int i=r;i<sz;++i)
						c[i]=getval(a[i]=z, b[i]);
					z=0;
				}
				ans = INF;
				for(int i=0;i<sz;++i)
				{
					if(l <= i && i < r)
						c[i] = getval(a[i] = v, b[i]);
					ckmin(ans, c[i]);
				}
			}
		}
		ll qry(int l, int r)
		{
			if(l <= 0 && sz <= r)
				return ans;
			if(z)
			{
				for(int i=0;i<sz;++i)
					c[i]=getval(a[i]=z, b[i]);
				z=0;
			}
			ll v=INF;
			for(int i=std::max(l, 0), mi=std::min(r, sz);i<mi;++i)
				ckmin(v, c[i]);
			return v;
		}
} blocks[C];
int a[MN], b[MN], N, Q;

int main()
{
	for(int i=1;i<MV;++i)
		for(int j=i;j<MV;j+=i)
			divisors[j].push_back(i);
	for(int i=2;i<MV;++i)
		if(pdiv[i].empty())
			for(int j=i;j<MV;j+=i)
				pdiv[j].push_back(i);
	scanf("%d%d", &N, &Q);
	for(int i=0;i<N;++i) scanf("%d", a+i);
	for(int i=0;i<N;++i) scanf("%d", b+i);

	for(int i=0;i*B<N;++i)
		blocks[i].init(std::min(B, N-i*B), a+i*B, b+i*B);
	for(int i=0;i<Q;++i)
	{
		int type;
		scanf("%d", &type);
		if(type == 1)
		{
			int l, r, v;
			scanf("%d%d%d", &l, &r, &v);
			--l;

			// [l, r) intersects [i*B, i*B+B)
			// l < (i+1)*B <=> l/B < i+1 <=> l/B <= i
			for(int i=l/B;i*B<r;++i)
				blocks[i].upd(l-i*B, r-i*B, v);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			--l;
			ll ans=INF;
			for(int i=l/B;i*B<r;++i)
				ckmin(ans, blocks[i].qry(l-i*B, r-i*B));
			printf("%lld\n", ans);
		}
	}
	return 0;
}