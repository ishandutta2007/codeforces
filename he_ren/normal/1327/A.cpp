#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(m%2 != n%2){ printf("NO\n"); return;}
	
	ll sum = (ll)m*m;
	if(sum<=n) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}