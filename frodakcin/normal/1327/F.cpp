#include <cstdio>
#include <cstring>

template<class T> bool ckmax(T* a, T b) {return *a<b?*a=b,1:0;}
template<class T> bool ckmin(T* a, T b) {return b<*a?*a=b,1:0;}

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MOD = 998244353;
 
//copied from benq
struct mint
{
public:
	int val;
	mint(int _val = 0) : val(_val)
	{
		val = (-MOD <= val && val < MOD) ? val : val%MOD;
		if(val < 0) val += MOD;
	}
	explicit operator int () const {return val;}

	mint operator -() const {return mint(-val);}
	mint& operator += (mint m) {if((val += m.val) >= MOD) val -= MOD; return *this;}
	mint& operator -= (mint m) {if((val -= m.val) < 0) val += MOD; return *this;}
	mint& operator *= (mint m) {val = ti(tl(val)*m.val%MOD); return *this;}

	friend mint pow(mint a, int p)
	{
		mint r(1);
		for(;p;p>>=1, a*=a) if(p&1) r*=a;
		return r;
	}

	friend mint operator + (mint a, mint b) {return a += b;}
	friend mint operator - (mint a, mint b) {return a -= b;}
	friend mint operator * (mint a, mint b) {return a *= b;}
};

const int MN = 5e5 + 10;
const int MK = 32;

int N, K, M;
struct R
{
public:
	int l, r, x;
	bool operator < (R o) const
	{
		if(l != o.l) return l < o.l;
		if(r != o.r) return r < o.r;
		if(x != o.x) return x < o.x;
		return 0;
	}
};

R a[MN];
mint ans, d[MN], p[MN];
int cnt[MN];
int end[MN];

int main(void)
{
	scanf("%d%d%d", &N, &K, &M);
	for(int i = 0;i < M;++i)
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].x), ++a[i].r;
	ans = mint(1);
	for(int i = 0;i < K;++i)
	{
		memset(cnt, 0, sizeof(cnt[0])*(N+5));
		memset(end, -1, sizeof(end[0])*(N+5));
		for(int j = 0;j < M;++j)
			if(a[j].x>>i&1)
				++cnt[a[j].l], --cnt[a[j].r];
			else
				ckmax(end+a[j].r, a[j].l);
		d[0] = mint(1), p[1] = mint(1);
		for(int j = 1, m = 0;j <= N+1;++j)
		{
			ckmax(&m, end[j]);
			d[j] = (cnt[j] += cnt[j-1]) ? mint(0) : p[j] - p[m];
			p[j+1] = p[j] + d[j];
			//printf("dp[%d][%d] = %d\n", i, j, d[j]);
		}
		ans *= d[N+1];
	}
	printf("%d\n", ans);
	return 0;
}