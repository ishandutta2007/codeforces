#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

void solve(void)
{
	int r,b,d;
	scanf("%d%d%d",&r,&b,&d);
	if(r > b) swap(r,b);
	
	if(b%r == 0)
	{
		if(b/r - 1 >= d) printf("REBEL\n");
		else printf("OBEY\n");
		return;
	}
	
	int t = gcd(r,b);
	if(t + (ll)r * (d-1) >= b) printf("OBEY\n");
	else printf("REBEL\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}