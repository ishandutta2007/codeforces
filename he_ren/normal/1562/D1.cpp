#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

char s[MAXN];
int f[MAXN];

void solve(void)
{
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	for(int i=1; i<=n; ++i)
	{
		int x = s[i] == '+'? 1: -1;
		if(i&1) f[i] = f[i-1] + x;
		else f[i] = f[i-1] - x;
	}
	
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		
		if(f[r] - f[l-1] == 0)
			printf("0\n");
		else if((r - l + 1) % 2)
			printf("1\n");
		else
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