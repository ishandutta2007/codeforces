#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXX = 1e6 + 5;

int a[MAXN];
int fir[MAXX], lst[MAXX];

int mxlst[MAXX], mnfir[MAXX];

int main(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=0; i<=x+1; ++i)
		fir[i] = n+1, lst[i] = 0;
	for(int i=1; i<=n; ++i)
		fir[a[i]] = min(fir[a[i]], i),
		lst[a[i]] = max(lst[a[i]], i);
	
	int mxl = 0;
	mxlst[0] = 0;
	for(int i=1; i<x; ++i)
	{
		if(fir[i] < mxlst[i-1]) break;
		mxlst[i] = max(mxlst[i-1], lst[i]);
		mxl = i;
	}
	
	int mnr = x+1;
	mnfir[x+1] = n+1;
	for(int i=x; i>1; --i)
	{
		if(lst[i] > mnfir[i+1]) break;
		mnfir[i] = min(mnfir[i+1], fir[i]);
		mnr = i;
	}
	
	ll ans = 0;
	for(int i=0, j=mnr; i<=mxl && j<=x+1; ++i)
	{
		while(j<=x+1 && (j<=i+1 || mnfir[j] < mxlst[i])) ++j;
		ans += x+1 - j + 1;
	}
	printf("%lld",ans);
	return 0;
}