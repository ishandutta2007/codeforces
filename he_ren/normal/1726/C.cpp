#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];

int fa[MAXN];
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	n *= 2;
	
	stack<int> sta;
	iota(fa+1, fa+n+1, 1);
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == '(')
		{
			sta.push(i);
			if(s[i-1] == ')') fa[find(i)] = find(i-1);
		}
		else
		{
			int j = sta.top(); sta.pop();
			fa[find(i)] = find(j);
		}
	}
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		ans += find(i) == i;
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}