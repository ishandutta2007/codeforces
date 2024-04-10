#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n;
	scanf("%d",&n);
	if(n==1) printf("-1\n");
	else
	{
		if((n-1)*2 %3 == 0)
			putchar('3'),
			--n;
		for(int i=1; i<n; ++i) putchar('2');
		printf("3\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}