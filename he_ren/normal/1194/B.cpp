#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int MAXN = 5e4 + 5;
const int MAXM = 5e4 + 5;

string s[MAXN];

int r[MAXN], c[MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; ++i)
		cin>>s[i];
	
	for(int i=0; i<n; ++i) r[i] = 0;
	for(int i=0; i<m; ++i) c[i] = 0;
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(s[i][j] == '*')
				++r[i],
				++c[j];
	
	int ans = n*m;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			ans = min(ans, (n-r[i]) + (m-c[j]) - (s[i][j] == '.'));
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}