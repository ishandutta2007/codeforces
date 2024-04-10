#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int x,y,a,b;
	scanf("%d%d%d%d",&x,&y,&a,&b);
	if((y-x)%(a+b)){ printf("-1\n"); return;}
	printf("%d\n",(y-x)/(a+b));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}