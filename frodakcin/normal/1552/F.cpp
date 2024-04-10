#include <cstdio>
#include <algorithm>

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

const int MOD = 998244353;
const int MN = 2e5+10;

struct mint
{
	public:
		int val;
		mint(int _val = 0) : val(_val)
		{
			val = (-MOD <= val && val < MOD) ? val : val%MOD;
			if(val < 0) val += MOD;
		}
		mint(ll _val) // should work
		{
			val = _val%MOD;
			if(val < 0) val += MOD;
		}
		explicit operator int () const {return val;}

		mint operator -() const {return mint(-val);}
		mint& operator += (const mint& m) {if((val += m.val) >= MOD) val -= MOD; return *this;}
		mint& operator -= (const mint& m) {if((val -= m.val) < 0) val += MOD; return *this;}
		mint& operator *= (const mint& m) {val = ti(tl(val)*m.val%MOD); return *this;}

		template<typename T>
		friend mint pow(mint a, T p)
		{
			mint r(1);
			for(;p;p>>=1, a*=a) if(p&1) r*=a;
			return r;
		}

		friend mint operator + (mint a, const mint& b) {return a += b;}
		friend mint operator - (mint a, const mint& b) {return a -= b;}
		friend mint operator * (mint a, const mint& b) {return a *= b;}
};

int N, x[MN], y[MN], s[MN];
mint bit[MN];

void upd(int n, mint v)
{
	for(++n;n<=N;n+=-n&n)
		bit[n-1]+=v;
}
mint qry(int n)
{
	mint ans;
	for(;n;n-=-n&n)
		ans+=bit[n-1];
	return ans;
}
mint qry(int l, int r) // [l, r)
{
	return qry(r)-qry(l);
}

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d%d%d", x+i, y+i, s+i);
	mint ans(x[N-1]+1);
	for(int i=0;i<N;++i)
	{
		mint v(x[i]-y[i]);
		v += qry(std::lower_bound(x, x+N, y[i])-x, i);
		upd(i, v);
		if(s[i]) ans+=v;
	}
	printf("%d\n", ans);
	return 0;
}