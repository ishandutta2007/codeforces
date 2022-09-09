#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	int tmp = (1<<(n/2))-1;
	int x = tmp<<(n/2);
	printf("%d\n",2 * ((1<<n)-1-x));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}