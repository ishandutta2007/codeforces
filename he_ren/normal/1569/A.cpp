#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int i=1; i<n; ++i)
		if(s[i] != s[i+1])
		{
			printf("%d %d\n",i,i+1);
			return;
		}
	printf("-1 -1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}