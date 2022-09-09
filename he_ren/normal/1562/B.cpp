#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;

char s[MAXN];

inline bool chk(int x)
{
	return x != 2 && x != 3 && x != 5 && x != 7;
}

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int i=1; i<=n; ++i)
		if(chk(s[i] - '0'))
		{
			printf("1\n%c\n",s[i]);
			return;
		}
	
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
		{
			int x = (s[i] - '0') * 10 + (s[j] - '0');
			bool ok = 1;
			for(int k=2; k<x; ++k)
				if(x%k == 0)
				{
					ok = 0;
					break;
				}
			if(!ok)
			{
				printf("2\n%d\n",x);
				return;
			}
		}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}