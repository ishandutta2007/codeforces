#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN];
int pre[MAXN],suf[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	pre[0]=~0;
	for(int i=1; i<=n; ++i) pre[i] = pre[i-1]&(~a[i]);
	suf[n+1]=~0;
	for(int i=n; i>=1; --i) suf[i] = suf[i+1]&(~a[i]);
	
	int ans=-1, ansi=0;
	for(int i=1; i<=n; ++i)
	{
		int tmp = a[i]&pre[i-1]&suf[i+1];
		if(ans<tmp)
		{
			ans=tmp;
			ansi=i;
		}
	}
	printf("%d ",a[ansi]);
	for(int i=1; i<ansi; ++i) printf("%d ",a[i]);
	for(int i=ansi+1; i<=n; ++i) printf("%d ",a[i]);
	return 0;
}