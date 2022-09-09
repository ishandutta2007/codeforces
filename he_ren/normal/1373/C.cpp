#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;

char s[MAXN];
int fst[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	for(int i=1; i<=n; ++i) fst[i] = -1;
	
	int cur = 0, mn = 0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == '+') ++cur;
		else --cur;
		mn = min(mn, cur);
		
		if(cur<0 && fst[-cur] == -1)
			fst[-cur] = i;
	}
	
	ll ans = n;
	for(int i=0; i<-mn; ++i)
		ans += fst[i+1];
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}