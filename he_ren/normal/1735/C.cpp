#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	static int nxt[30], pre[30];
	memset(nxt, -1, sizeof(nxt));
	memset(pre, -1, sizeof(pre));
	
	for(int i=1; i<=n; ++i)
	{
		int c = s[i] - 'a';
		if(nxt[c] != -1)
		{
			s[i] = nxt[c] + 'a';
			continue;
		}
		
		int u = c, cnt = 1;
		while(pre[u] != -1) u = pre[u], ++cnt;
		if(cnt == 26) u = -1;
		
		for(int j=0; j<26; ++j) if(j != u && pre[j] == -1)
		{
			nxt[c] = j; pre[j] = c;
			break;
		}
		
		s[i] = nxt[c] + 'a';
	}
	
	printf("%s\n",s+1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}