#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	ll ans = (ll)n * (n-1) / 2;
	for(int i=1; i<n; ++i)
		if(s[i] != s[i+1]) --ans;
	
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && s[j] == s[i]) ++j;
		
		int side = (i!=1) + (j<=n);
		ans -= (j-i-1) * side;
	}
	printf("%lld",ans);
	return 0;
}