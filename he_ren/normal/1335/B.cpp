#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	
	for(int i=1,j=1; i<=n; ++i,++j)
	{
		if(j>a) j=1;
		if(j<b) putchar('a'+j-1);
		else putchar('z');
	}
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}