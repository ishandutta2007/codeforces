#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

char s[3][MAXN];
bool vis[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	scanf("%s%s",s[0]+1,s[1]+1);
	
	for(int i=1; i<=n; ++i)
		if(s[0][i] == '1' && s[1][i] == '1')
		{
			printf("NO\n");
			return;
		}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}