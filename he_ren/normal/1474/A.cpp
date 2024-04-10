#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int lst = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j>=0; --j)
		{
			if(s[i] - '0' + j != lst)
			{
				putchar(j + '0');
				lst = s[i] - '0' + j;
				break;
			}
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