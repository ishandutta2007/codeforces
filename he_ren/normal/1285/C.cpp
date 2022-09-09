#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXM = 1e2 + 5;

inline void chk_min(ll &a,ll b){ if(a>b) a=b;}
inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

int p[MAXM],m=0;
ll q[MAXM];
#define bit(x,i) (((x)>>(i))&1)

int main(void)
{
	ll n;
	scanf("%lld",&n);
	
	ll sn=sqrt(n), t=n;
	for(int i=2; i<=sn && t>1; ++i)
		if(t%i==0)
		{
			p[m]=i; q[m]=1;
			while(t%i==0)
				t/=i, q[m]*=(ll)i;
			++m;
		}
	if(t>1) q[m++]=t;
	
	ll ans=n;
	int all = (1<<m)-1;
	for(int s=0; s<=all; ++s)
	{
		ll tmp=1;
		for(int i=0; i<m; ++i)
			if(bit(s,i)) tmp*=q[i];
		chk_min(ans, max(tmp,n/tmp));
	}
	printf("%lld %lld",ans,n/ans);
	return 0;
}