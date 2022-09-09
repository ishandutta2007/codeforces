#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

ll a[MAXN];

void solve(void)
{
	int n;
	ll x;
	scanf("%d%lld",&n,&x);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	bool flag = 1, has = 0;
	for(int i=1; i<=n; ++i)
		if(a[i] != x) flag=0;
		else has = 1;
	if(flag){ printf("0\n"); return;}
	if(has){ printf("1\n"); return;}
	
	ll sum = 0;
	for(int i=1; i<=n; ++i)
		sum += a[i];
	if(sum == n * x){ printf("1\n"); return;}
	printf("2\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}