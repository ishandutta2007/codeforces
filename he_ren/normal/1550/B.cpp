#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

char s[MAXN];

void solve(void)
{
	int n,a,b;
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	
	int cnt = 0;
	for(int i=1; i<=n; ++i)
		if(s[i] != s[i-1]) ++cnt;
	
	if(b >= 0)
		printf("%d\n",n * a + n * b);
	else
		printf("%d\n",n * a + (cnt / 2 + 1) * b);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}