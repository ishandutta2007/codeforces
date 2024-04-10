#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	ll c,x;
	scanf("%lld%lld",&c,&x);
	
	ll num = x/c;
	printf("%lld\n",num * num * (c - x%c) + (num + 1) * (num + 1) * (x%c));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}