#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 2e6;
const int MAXN = 2e6 + 5;
const int mod = 1e9 + 7;

int f[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	printf("%d\n",f[n]);
}

int main(void)
{
	for(int i=3; i<=maxn; ++i)
	{
		f[i] = (f[i-1] + (ll)f[i-2] * 2ll) %mod;
		if(i%3 == 0) f[i] = (f[i] + 4) %mod;
	}
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}