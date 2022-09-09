#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int mod = 998244353;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int ans=1;
	for(char i='a'; i<='z'; ++i)
	{
		ll l=0,r=0;
		for(int j=1; s[j]==i; ++j) ++l;
		for(int j=n; s[j]==i; --j) ++r;
		
		ans = ((ll)ans+(l+1)*(r+1)-1) %mod;
	}
	printf("%d",ans);
	return 0;
}