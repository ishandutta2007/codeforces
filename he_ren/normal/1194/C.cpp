#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1e2 + 5;
const int MAXM = 1e2 + 5;
const int MAXD = 1e2 + 5;

char s[MAXN], t[MAXM], p[MAXD];
int cnt[26 + 5];

void solve(void)
{
	scanf("%s%s%s",s+1,t+1,p+1);
	int n = strlen(s+1);
	int m = strlen(t+1);
	int d = strlen(p+1);
	if(n>m){ printf("NO\n"); return;}
	
	int now = 1;
	for(int i=1; i<=m && now<=n; ++i)
		if(t[i] == s[now]) ++now;
	if(now <= n){ printf("NO\n"); return;}
	
	for(int i=0; i<26; ++i) cnt[i] = 0;
	for(int i=1; i<=m; ++i)
		++cnt[t[i] - 'a'];
	for(int i=1; i<=n; ++i)
		--cnt[s[i] - 'a'];
	for(int i=1; i<=d; ++i)
		--cnt[p[i] - 'a'];
	
	for(int i=0; i<26; ++i)
		if(cnt[i] > 0){ printf("NO\n"); return;}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}