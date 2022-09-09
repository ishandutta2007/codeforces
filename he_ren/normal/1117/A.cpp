#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int mx=-1;
	for(int i=1; i<=n; ++i)
		if(mx<a[i]) mx=a[i];
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		if(a[i]==mx)
		{
			int j=i;
			while(j<=n && a[j]==mx) ++j;
			if(ans<j-i) ans=j-i;
			i=j-1;
		}
	printf("%d",ans);
	return 0;
}