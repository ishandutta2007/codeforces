#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

char s[MAXN];

int f[MAXN], g[MAXN];
void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	f[0] = g[n+1] = 1;
	for(int i=1; i<=n; ++i)
	{
		f[i] = f[i-1];
		if(s[i] == '1' && s[i-1] == '1') f[i] = 0;
	}
	for(int i=n; i>=1; --i)
	{
		g[i] = g[i+1];
		if(s[i] == '0' && s[i+1] == '0') g[i] = 0;
	}
	
	for(int i=0; i<=n; ++i)
	{
		if(s[i] == '1' && s[i+1] == '0') continue;
		if(f[i] && g[i+1])
		{
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}