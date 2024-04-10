#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

void solve(void)
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	if(c)
		printf("%d",a&&d&&a==d);
	else printf("%d",a==d);
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}