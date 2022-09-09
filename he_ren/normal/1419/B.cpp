#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

inline ll calc(ll n){ return n * (n+1) / 2;}

void solve(void)
{
	ll x;
	scanf("%lld",&x);
	
	ll cur = 2;
	int ans = 0;
	while(x >= calc(cur-1))
	{
		++ans;
		x -= calc(cur-1);
		cur *= 2;
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}