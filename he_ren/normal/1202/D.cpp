#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxm = 1e5;
const int MAXM = maxm + 5;

void solve(void)
{
	ll n;
	scanf("%lld",&n);
	
	if(n==1)
	{
		printf("1337\n");
		return;
	}
	
	printf("133");
	
	int i=0;
	for(; (ll)(i+2) * (i+2-1) / 2 <= n-1; ++i);
	--i;
	
	int rem = n - (ll)(i+2) * (i+2-1) / 2;
	while(rem--) putchar('7');
	while(i--) putchar('3');
	printf("7\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}