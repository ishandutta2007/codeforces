#include <cstdio>
#include <numeric>
#include <algorithm>
#include <vector>
#include <utility>

template<typename T> bool ckmin(T &a, const T& b) {return b<a?a=b,1:0;}
template<typename T> bool ckmax(T &a, const T& b) {return b>a?a=b,1:0;}

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
 
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

const int MN = 2e5+10;
std::pair<int, int> st[MN*4];
int a[MN];

void build(int n, int l, int r)
{
	if(r-l==1)
		st[n] = {-a[l], l};
	else
	{
		int m=l+(r-l)/2;
		build(n<<1, l, m);
		build(n<<1|1, m, r);
		st[n] = std::min(st[n<<1], st[n<<1|1]);
	}
}
std::pair<int, int> qry(int n, int l, int r, int ql, int qr)
{
	if(ql <= l && r <= qr)
		return st[n];
	else
	{
		int m=l+(r-l)/2;
		std::pair<int, int> ans(INF, INF);
		if(ql < m) ckmin(ans, qry(n<<1, l, m, ql, qr));
		if(m < qr) ckmin(ans, qry(n<<1|1, m, r, ql, qr));
		return ans;
	}
}

void solve()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i=0;i<N;++i)
		scanf("%d", a+i);
	build(1, 0, N);

	auto solve=[&](auto const& self, int l, int r)
	{
		if(r-l==1)
			return std::vector<mint>(M, mint(1));
		if(l == r)
			return std::vector<mint>();
		int m=qry(1, 0, N, l, r).second;
		auto const& a = self(self, l, m);
		auto const& b = self(self, m+1, r);

		std::vector<mint> ans(M);
		mint u(a.empty()), v(b.empty());
		for(int i=0;i<M;++i)
		{
			if(!b.empty()) v += b[i];
			ans[i] = u*v;
			if(!a.empty()) u += a[i];
		}
		return ans;
	};
	std::vector<mint> const& ans = solve(solve, 0, N);

	mint sol;
	for(int i=0;i<M;++i)
		sol += ans[i];
	printf("%d\n", sol);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}