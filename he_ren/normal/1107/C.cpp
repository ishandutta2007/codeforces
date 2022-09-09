#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

int a[MAXN];
char s[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	scanf("%s",s+1);
	
	ll ans=0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && s[j]==s[i]) ++j;
		sort(a+i,a+j);
		reverse(a+i,a+j);
		for(int k=i; k<i+d && k<j; ++k)
			ans+=a[k];
	}
	printf("%lld",ans);
	return 0;
}