#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int a[4];

void solve(void)
{
	for(int i=1; i<=3; ++i) scanf("%d",&a[i]);
	sort(a+1,a+3+1);
	if(a[3]>a[1]+a[2]+1) printf("NO\n");
	else printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}