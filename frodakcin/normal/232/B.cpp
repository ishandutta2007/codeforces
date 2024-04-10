#include <cstdio>


using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MOD = 1000000007;
 
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

	friend mint pow(mint b, ll p)
	{
		mint r(1);
		for(;p;p>>=1, b*=b)
			if(p&1)
				r*=b;
		return r;
	}
};

const int MN = 1e2+10, MK = MN*MN;
int N, K;
ll M;
mint c[MN][MN];
mint dp[MK];
mint res[MN][2];

int main()
{
	scanf("%d%lld%d", &N, &M, &K);
	c[0][0]=1;
	for(int i=0;i<=N;++i)
	{
		c[i][i] = c[i][0] = mint(1);
		for(int j=1;j<i;++j)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
	for(int i=0;i<=N;++i)
	{
		res[i][0] = pow(c[N][i], M/N);
		res[i][1] = res[i][0]*c[N][i];
	}
	//dp[number of columns][number of dots]
	dp[0] = 1;
	for(int i=0;i<N;++i)
		for(int j=K;j>=0;--j)
		{
			bool t = i < (M%N);
			for(int l=1;l<=N;++l)
				if(j-l>=0)
					dp[j] += dp[j-l]*res[l][t];
		}
	printf("%d\n", dp[K]);
	return 0;
}