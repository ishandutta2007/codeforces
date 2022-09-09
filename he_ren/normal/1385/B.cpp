#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int MAXN = 50 + 5;
const int MAXM = MAXN * 2;

int q[MAXM];
bool vis[MAXM];

void solve(void)
{
	int n;
	scanf("%d",&n);
	int m = 2 * n;
	for(int i=1; i<=m; ++i) scanf("%d",&q[i]);
	
	for(int i=1; i<=m; ++i) vis[i] = 0;
	for(int i=1; i<=m; ++i) if(!vis[i])
	{
		printf("%d ",q[i]);
		vis[i] = 1;
		for(int j=i+1; j<=m; ++j)
			if(q[j] == q[i]) vis[j] = 1;
	}
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}