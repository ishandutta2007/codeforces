#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

char s[MAXN];
int cnt[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	ll ans=0;
	for(int x='a'; x<='z'; ++x)
	{
		for(int i=1; i<=n; ++i)
		{
			cnt[i]=cnt[i-1];
			if(s[i]==x) ++cnt[i];
		}
		if(ans<cnt[n]) ans=cnt[n];
		for(int y='a'; y<='z'; ++y)
		{
			ll res=0;
			for(int i=1; i<=n; ++i)
				if(s[i]==y)
					res += cnt[i-1];
			if(ans<res) ans=res;
		}
	}
	printf("%lld",ans);
	return 0;
}