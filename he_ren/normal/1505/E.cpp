#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5 + 5;
const int MAXM = 5 + 5;

int n,m;
char s[MAXN][MAXM];

int dfs(int x,int y)
{
	if(x == n && y == m) return s[x][y] == '*';
	if(x == n) return dfs(x, y+1) + (s[x][y] == '*');
	if(y == m) return dfs(x+1, y) + (s[x][y] == '*');
	if(s[x+1][y] == s[x][y+1]) return dfs(x, y+1) + (s[x][y] == '*');
	return (s[x+1][y] == '*'? dfs(x+1, y): dfs(x, y+1)) + (s[x][y] == '*');
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i] + 1);
	
	printf("%d",dfs(1,1));
	return 0;
}