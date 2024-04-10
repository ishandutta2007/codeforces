#include<cstdio>
#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
PII a[100010];
int n;
inline LL sqr(LL n){return n*n;}
inline LL max(LL a,LL b){return a>b?a:b;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i].x),a[i].x+=a[i-1].x;
	for (int i=1;i<=n;i++) a[i].y=i;
	sort(a+1,a+1+n);
	LL ans=1e+18;
	for (int i=2;i<=n;i++)
	for (int j=i-1;j>=1;j--)
	{
		ans=min(ans,sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y));
		if (abs(i-j)>=200) break;
		if (sqr(a[i].x-a[j].x)>=ans) break;
	}
	printf("%I64d\n",ans);
	return 0;
}