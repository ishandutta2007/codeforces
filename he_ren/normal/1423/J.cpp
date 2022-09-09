#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int LB = 60 + 5;
const int mod = 1e9 + 7;

#define bbit(i) (1ll<<(i))
#define bdig(x,i) (((x)>>(i))&1)

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

const int MAXF = 5 + 5;
ll fac[MAXF], inv[MAXF];
inline ll c(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

ll f[LB][3];

void solve(void)
{
	register ll m;
	scanf("%lld",&m);
	
	f[0][0] = 1;
	f[1][0] = f[1][1] = 0;
	if(bdig(m,1)) f[1][0] = 2;
	else f[1][0] = f[1][1] = 1;
	
	register int lb = 2;
	while((m>>lb) >= 2) ++lb;
	
	for(register int i=2; i<=lb; ++i)
	{
		if(bdig(m,i))
		{
			f[i][0] = (f[i-1][0] * 3 + f[i-1][1]) %mod;
			
			f[i][1] = (f[i-1][0] + 3 * (f[i-1][1] + f[i-1][2])) %mod;
			
			f[i][2] = f[i-1][2];
		}
		else
		{
			f[i][0] = f[i-1][0];
			
			f[i][1] = (f[i-1][2] + 3 * (f[i-1][1] + f[i-1][0])) %mod;
			
			f[i][2] = (f[i-1][2] * 3 + f[i-1][1]) %mod;
		}
	}
	
	printf("%lld\n",f[lb][0]);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}