#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e4 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int need = n / 2;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && s[i] == s[j]) ++j;
		if(j - i > need)
		{
			--j;
			printf("%d %d %d %d\n",i,j-1,i+1,j);
			return;
		}
	}
	
	for(int i=need+1; i<=n; ++i)
		if(s[i] == '0')
		{
			printf("%d %d %d %d\n",1,i,1,i-1);
			return;
		}
	printf("%d %d %d %d\n",need,n,need+1,n);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}