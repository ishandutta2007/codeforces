#include <cstdio>

using ll = long long;

const int MOD = 1e9+7;
struct mint
{
public:
	int v;
	mint(int v=0):v(v){}
	mint& operator += (mint o) {if((v+=o.v)>=MOD)v-=MOD;return *this;}
	mint& operator -= (mint o) {if((v-=o.v)<0)v+=MOD;return *this;}
	mint& operator *= (mint o) {v=(int)((ll)v*o.v%MOD);return *this;}
	mint operator - () const {return v?mint(MOD-v):mint(0);}

	friend mint operator + (mint a, mint b) {return a+=b;}
	friend mint operator - (mint a, mint b) {return a-=b;}
	friend mint operator * (mint a, mint b) {return a*=b;}
	friend mint pow(mint b, int p)
	{
		mint r(1);
		for(;p;p>>=1,b*=b) if(p&1) r*=b;
		return r;
	}
	explicit operator int() const {return v;}
};

const int MK = 1e6+10;
int N, K;
mint v[MK], n, d, f, inv[MK];
int main()
{
	scanf("%d%d", &N, &K);
	if(!K) return printf("%d\n", N), 0;
	inv[1]=mint(1);
	for(int i=1;i<=K+1;++i)
	{
		if(i>1) inv[i]=inv[MOD%i]*mint(MOD-MOD/i);
		v[i]=pow(mint(i), K)+v[i-1];
	}
	if(N<=K+1)
	{
		printf("%d\n", v[N]);
		return 0;
	}
	n=mint(N), d=mint(1);
	for(int i=1;i<=K+1;++i)
		n*=mint(N-i), d*=-inv[i];
	for(int i=0;i<=K+1;++i)
	{
		//printf("%d/%d\n", n, d);
		f+=v[i]*n*pow(mint(N-i), MOD-2)*d;
		d*=-mint(K+1-i)*inv[i+1];
	}
	printf("%d\n", f);
	return 0;
}