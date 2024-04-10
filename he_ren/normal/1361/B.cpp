#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
const int MAXA = 1e7 + 5;
const int m = 7;
const int MAXM = m + 5;
const ll MOD = 1e9 + 7;

struct Mode
{
	ll mod, ans;
	inline ll pw(ll a,int b)
	{
		ll res=1;
		while(b)
		{
			if(b&1) res = res*a%mod;
			a=a*a%mod;
			b>>=1;
		}
		return res;
	}
	inline void plus(int x){ ans = (ans + x) %mod;}
	inline void minus(int x){ ans = (ans + mod - x) %mod;}
}pp[MAXM];


int a[MAXN];

void solve(void)
{
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	if(p==1){ printf("%d\n",n&1); return;}
	
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	
	for(int i=1; i<=m; ++i)
		pp[i].ans = 0,
		pp[i].mod = rand()%MOD + MOD;
	pp[1].mod = 1e9 + 7;
	pp[2].mod = 1e9 + 9;
	pp[3].mod = 998244353;
	pp[4].mod = 19491001;
	pp[5].mod = 19260817;
	
	for(int i=1; i<=n; ++i)
	{
		bool flag=1;
		for(int j=1; j<=m; ++j)
			if(pp[j].ans)
			{
				flag = 0;
				break;
			}
		
		if(flag)
		{
			for(int j=1; j<=m; ++j)
				pp[j].plus(pp[j].pw(p, a[i]));
		}
		else
		{
			for(int j=1; j<=m; ++j)
				pp[j].minus(pp[j].pw(p, a[i]));
		}
	}
	printf("%lld\n",pp[1].ans);
}

int main(void)
{
	srand(time(0));
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}