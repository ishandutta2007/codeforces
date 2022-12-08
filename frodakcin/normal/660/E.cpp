#include <cstdio>

using ll = long long;

const int MOD = 1e9+7;
struct mint
{
public:
	int v;
	mint(int _v=0):v(_v){}
	mint& operator += (mint o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
	mint& operator -= (mint o) {if((v-=o.v)<0) v+=MOD; return *this;}
	mint& operator *= (mint o) {v=(int)((ll)v*o.v%MOD); return *this;}

	friend mint operator + (mint a, mint b){return a+=b;}
	friend mint operator - (mint a, mint b){return a-=b;}
	friend mint operator * (mint a, mint b){return a*=b;}

	friend mint pow(mint b, int p)
	{
		mint r(1);
		for(;p;p>>=1,b*=b)
			if(p&1)
				r*=b;
		return r;
	}
};

const int MN = 1e6+10;

int N, M;
mint c, p, f, x, inv;

int main(void)
{
	scanf("%d%d", &N, &M);
	c=mint(1), x=pow(mint(M), N), inv=pow(mint(M), MOD-2);
	for(int i=0;i<=N;++i)
	{
		//printf("%d: %d\n", i, c);
		f+=c*x, x*=inv;
		p=p*mint(M-1)+c;
		c=p*mint(M);
	}
	printf("%d\n", f);
	return 0;
}