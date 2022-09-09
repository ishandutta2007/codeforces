#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n;
	scanf("%d",&n);
	if(n&1) putchar('7'), n-=3;
	n>>=1;
	while(n--) putchar('1');
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}