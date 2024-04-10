#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;

char s[MAXN];
char res[MAXN][MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	vector<int> a,b;
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == '1') a.push_back(i);
		else b.push_back(i);
	}
	
	if(1 <= b.size() && b.size() <= 2)
	{
		printf("NO\n");
		return;
	}
	
	for(int i=1; i<=n; ++i)
	{
		res[i][n+1] = 0;
		for(int j=1; j<=n; ++j)
			res[i][j] = i == j? 'X': '=';
	}
	
	if(b.size()) b.push_back(b[0]);
	for(int i=0; i+1<(int)b.size(); ++i)
	{
		int u = b[i], v = b[i+1];
		res[u][v] = '+'; res[v][u] = '-';
	}
	
	printf("YES\n");
	for(int i=1; i<=n; ++i) printf("%s\n",res[i]+1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}