#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	int l = n + 1, r = 0;
	for(int i=1; i<=n; ++i)
		if(s[i] == '0')
		{
			l = min(l, i);
			r = max(r, i);
		}
	if(r == 0)
	{
		printf("0\n");
		return;
	}
	
	if(count(s+l,s+r+1,'1') == 0)
	{
		printf("1\n");
	}
	else
	{
		printf("2\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}