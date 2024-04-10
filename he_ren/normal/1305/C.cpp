#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXM = 1e3 + 5;

int n,m,a[MAXN];
int t[MAXM];

inline int pw(int a,ll b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%m;
		a=a*a%m;
		b>>=1ll;
	}
	return res;
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) ++t[a[i]%m];
	for(int i=0; i<m; ++i)
		if(t[i]>1)
		{
			printf("0");
			return 0;
		}
	
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
			ans = (ll)ans * (a[i]-a[j]) %m;
	printf("%d",ans);
	return 0;
}