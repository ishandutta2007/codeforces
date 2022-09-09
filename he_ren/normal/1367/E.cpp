#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e3 + 5;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

char s[MAXN];
int t[30 + 5];

void solve(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	memset(t,0,sizeof(t));
	for(int i=1; i<=n; ++i)
		++t[s[i]-'a'];
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
	{
		int tot = gcd(i,d), len = i/tot;
		
		for(int j=0; j<26 && tot; ++j)
			tot -= min(tot, t[j]/len);
		
		if(!tot) ans = i;
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