#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e3 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

ll a[MAXN],b[MAXN];
ll c[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%lld",&b[i]);
	
	sort(b+1,b+n+1);
	int ans=m;
	for(int i=1; i<=n; ++i)
	{
		ll x = (b[1]-a[i])%m;
		if(x<0) x+=m;
		
		for(int j=1; j<=n; ++j) c[j]=(a[j]+x)%m;
		sort(c+1,c+n+1); 
		
		bool flag=1;
		for(int j=1; j<=n; ++j)
			if(c[j]!=b[j])
			{
				flag=0;
				break;
			}
		if(flag) chk_min(ans,x);
	}
	printf("%d",ans);
	return 0;
}