#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	char c;
	scanf("%d %c\n%s",&n,&c,s+1);
	
	bool ok = 1;
	for(int i=1; i<=n; ++i)
		if(s[i] != c) ok = 0;
	if(ok)
	{
		printf("0\n");
		return;
	}
	
	for(int i=1; i<=n; ++i)
	{
		ok = 1;
		for(int j=i; j<=n; j+=i)
			if(s[j] != c)
				ok = 0;
		if(ok)
		{
			printf("1\n%d\n",i);
			return;
		}
	}
	
	printf("2\n");
	printf("%d %d\n",n,n-1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}