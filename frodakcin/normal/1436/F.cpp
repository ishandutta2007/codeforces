#include <cstdio>

using ll = long long;

const int MOD = 998244353;
const int MM = 1e5+10;
const int MV = 1e5+10;

struct mint
{
	public:
		int v;
		mint(int _v=0) :v(_v)
		{
			if(v<-MOD || MOD<=v) v%=MOD;
			if(v<0) v+=MOD;
		}
		mint(ll _v)
		{
			v=_v%MOD;
			if(v<0) v+=MOD;
		}

		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {v=(ll)v*o.v%MOD; return *this;}

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}

		template<typename T> friend mint pow(mint b, T p)
		{
			mint f(1);
			for(;p;p>>=1,b*=b)
				if(p&1)
					f*=b;
			return f;
		}
};

mint inv[100];
int n[MV], p[MV], P, l[MV], mu[MV];
bool c[MV];

void pcp()
{
	inv[1]=1;
	for(int i=2;i<100;++i)
		inv[i]=mint(MOD-MOD/i)*inv[MOD%i];
	mu[1]=1;
	for(int i=2;i<MV;++i)
	{
		if(!c[i]) n[i]=1, l[i]=P, p[P++]=i, mu[i]=-1;
		for(int j=0,k;j<P&&(k=i*p[j])<MV;++j)
		{
			c[k]=1;
			if(j==l[i])
			{
				n[k]=n[i], l[k]=j;
				break;
			}
			else
				n[k]=i, l[k]=j, mu[k]=-mu[i];
		}
	}
}

int M;
ll mul[MV];
mint dp[MV], dp2[MV];

int main()
{
	pcp();
	scanf("%d", &M);
	mint ans(0);
	for(int i=0;i<M;++i)
	{
		int a,f,b=1;
		scanf("%d%d", &a, &f);
		for(int x=a;x>1;x=n[x]) b*=p[l[x]];
		dp[b] += mint(a)*mint(f);
		dp2[b] += mint(a)*mint(a)*mint(f);
		mul[b] += f;
	}
	for(int i=1;i<MV;++i)
		for(int j=i*2;j<MV;j+=i)
			dp[i]+=dp[j], dp2[i]+=dp2[j], mul[i]+=mul[j];
	for(int i=1;i<MV;++i)
		if(mul[i]>=1 && mu[i])
		{
			if(mul[i]>=2)
			{
				ans += mint(mu[i])*dp[i]*dp[i]*(inv[4]*mint(mul[i])*pow(mint(2), mul[i]-1));
				ans -= mint(mu[i])*dp2[i]*(inv[4]*mint(mul[i])*pow(mint(2), mul[i]-1));
			}
			ans += mint(mu[i])*dp2[i]*(mint(mul[i]-1)*pow(mint(2),mul[i]-1)*inv[2]);
		}
	printf("%d\n", ans);
	return 0;
}