#include <cstdio>
#include <cassert>

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

	friend mint operator + (mint a, mint b){return a+=b;}
	friend mint operator - (mint a, mint b){return a-=b;}
	friend mint operator * (mint a, mint b){return a*=b;}

	friend mint pow(mint b, int p)
	{
		mint r(1);
		for(;p;p>>=1,b*=b) if(p&1) r*=b;
		return r;
	}
	explicit operator int() const {return v;}
};
const int MN = 2e6+10;

ll f;
mint pf[MN], fv, v[MN];
int N, K, p[MN], P, l[MN], mu[MN];
bool c[MN];
int main()
{
	scanf("%d%d", &N, &K);
	for(int i=2;i<=K;++i)
	{
		if(!c[i])
			l[i]=P, p[P++]=i, mu[i]=1;
		for(int j=0,k;j<=l[i]&&(k=p[j]*i)<=K;++j)
		{
			c[k]=1;
			l[k]=j;
			if(j<l[i]) mu[k]=-mu[i];
		}
	}
	for(int i=1;i<=K;++i)
		v[i] = pow(mint(i), N);
	for(int i=2;i<=K;++i)
		if(mu[i])
		{
			mint pr(0);
			for(int j=i,k=1;j<=K;j+=i,++k)
				if(mu[i]>0)
					pf[j] -= pr, pf[j] += pr = v[k];
				else
					pf[j] += pr, pf[j] -= pr = v[k];
		}
	for(int i=1;i<=K;++i)
	{
		f += (pow(mint(i), N)-(fv += pf[i])).v^i;
		//printf("%d: %d\n", i, fv);
	}
	printf("%lld\n", f%MOD);
	return 0;
}