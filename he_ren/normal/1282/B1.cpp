#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN];
ll sum[MAXN],sumd[MAXN];

void solve(void)
{
	int n,p,d;
	scanf("%d%d%d",&n,&p,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+a[i];
	
	int ans=0;
	for(int i=0; i<d; ++i)
	{
		int tmp=sum[i];
		if(tmp>p) break;
		int tans=i;
		for(int j=i+d; j<=n; j+=d)
		{
			if(tmp+a[j]<=p) tmp+=a[j], tans+=d;
			else break;
		}
		chk_max(ans,tans);
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}