#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=n-1; i>=1; --i)
	{
		int num = n-i;
		if(num >= d)
		{
			for(int j=1; j<i; ++j) putchar('a');
			putchar('b');
			
			for(int j=1; j<=n-i-d; ++j) putchar('a');
			putchar('b');
			
			for(int j=1; j<d; ++j) putchar('a');
			putchar('\n');
			return;
		}
		d -= num;
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}