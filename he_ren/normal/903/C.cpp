#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 5e3 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans=1;
	sort(a+1,a+n+1);
	for(int i=1,j=1; j<=n; i=j)
	{
		while(j<=n && a[j]==a[i]) ++j;
		chk_max(ans,j-i);
	}
	printf("%d",ans);
	return 0;
}