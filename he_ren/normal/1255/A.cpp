#include<cstdio>
#include<algorithm>
using namespace std;

void solve(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<b) swap(a,b);
	a-=b;
	int ans = a/5; a%=5;
	ans += a/2; a%=2;
	ans += a;
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}