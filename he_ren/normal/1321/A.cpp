#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

int n;
int a[MAXN],b[MAXN];

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	int cnt1=0, cnt2=0;
	for(int i=1; i<=n; ++i)
	{
		if(a[i]&&b[i]) continue;
		if(a[i]) ++cnt1;
		if(b[i]) ++cnt2;
	}
	
	if(!cnt1) printf("-1");
	else printf("%d",(cnt2+cnt1)/cnt1);
	return 0;
}