#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXP = 20 + 5;
const int ALL = (1<<20) + 5;

#define bit(x,i) (((x)>>(i))&1ll)
#define lowbit(x) ((x)&-(x))

ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}

ll p[MAXP];
int pcnt=0;
void gao(ll x)
{
	pcnt=0;
	int sx = sqrt(x);
	for(ll i=2; i<=sx && x>1; ++i)
		if(x%i==0)
		{
			p[++pcnt]=i;
			while(x%i==0) x/=i;
		}
	if(x>1) p[++pcnt]=x;
}

int tot1[ALL];

ll calc(ll r)
{
	int all = (1<<pcnt)-1;
	
	ll res=0;
	for(int i=0; i<=all; ++i)
	{
		ll tmp=1;
		for(int j=1; j<=pcnt; ++j)
			if(bit(i,j-1)) tmp*=p[j];
		if(tot1[i]&1) res-=r/tmp;
		else res+=r/tmp;
	}
	return res;
}

void solve(void)
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	
	ll tmp=gcd(n,m);
	n/=tmp; m/=tmp; //x in [n,n+m) , gcd(x,m)=1
	gao(m);
	printf("%lld\n",calc(n+m-1)-calc(n-1));
}

int main(void)
{
	tot1[0]=0;
	for(int i=1; i<ALL; ++i) tot1[i]=tot1[i^lowbit(i)]+1;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}