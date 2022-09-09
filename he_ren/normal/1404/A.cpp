#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

char s[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	for(int i=n; i>d; --i)
		if(s[i] != '?')
		{
			if(s[i-d] == '?') s[i-d] = s[i];
			else if(s[i-d] != s[i]){ printf("NO\n"); return;}
		}
	
	int cnt[2] = {0,0}, x = 0;
	for(int i=1; i<=d; ++i)
	{
		if(s[i] == '?') ++x;
		else ++cnt[s[i] - '0'];
	}
	while(x)
	{
		if(cnt[0] < cnt[1]) ++cnt[0];
		else ++cnt[1];
		--x;
	}
	if(cnt[0] != cnt[1]){ printf("NO\n"); return;}
	
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}