#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e3 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN];

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		while((k<<1)<a[i])
		{
			k<<=1;
			++ans;
		}
		chk_max(k,a[i]);
	}
	printf("%d",ans);
	return 0;
}