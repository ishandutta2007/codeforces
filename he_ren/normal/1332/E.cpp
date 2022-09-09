#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

struct Matrix
{
	ll g[2][2];
	Matrix(void){ g[0][0]=g[0][1]=g[1][0]=g[1][1]=0;}
	inline void set(void){ g[0][0]=g[1][1]=1;}
	inline void operator *= (const Matrix b)
	{
		Matrix a = *this;
		g[0][0]=g[0][1]=g[1][0]=g[1][1]=0;
		for(int k=0; k<=1; ++k)
			for(int i=0; i<=1; ++i)
				for(int j=0; j<=1; ++j)
					g[i][j] += a.g[i][k] * b.g[k][j] %mod;
		g[0][0]%=mod; g[0][1]%=mod;
		g[1][0]%=mod; g[1][1]%=mod;
	}
	inline ll& operator () (const int x,const int y){ return g[x][y];}
};

inline Matrix pw(Matrix a,ll b)
{
	Matrix res;
	res.set();
	while(b)
	{
		if(b&1ll) res*=a;
		a*=a;
		b>>=1ll;
	}
	return res;
}

inline ll pw(ll a,ll b)
{
	a%=mod; b%=mod-1;
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int main(void)
{
	ll n,m,l,r;
	scanf("%lld%lld%lld%lld",&n,&m,&l,&r);
	ll tot = n*m, len = r-l+1;
	
	if(tot&1)
	{
		printf("%lld",pw(len,tot));
		return 0;
	}
	
	ll a,b;//a: # of even	b: # of odd
	if(l&1ll) a = len/2ll;
	else a = (len+1)/2ll;
	b = len-a;
	
	//printf("x:%lld  y:%lld\n",x,y);
	//printf("a:%lld  b:%lld\n",a,b);
	
	a%=mod; b%=mod;
	
	Matrix g;
	g(0,0)=a; g(0,1)=b;
	g(1,0)=b; g(1,1)=a;
	
	Matrix res = pw(g,tot);
	
	//printf("%d %d\n",res1(0,0),res1(1,0));
	
	printf("%lld",res(0,0));
	return 0;
}