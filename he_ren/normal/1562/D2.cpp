#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

char s[MAXN];
int f[MAXN], g[MAXN], val[MAXN];

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
	
	g[n+1] = 0;
	for(int i=n; i>=1; --i)
	{
		int x = s[i] == '+'? 1: -1;
		if((i&1) == 0) g[i] = g[i+1] + x;
		else g[i] = g[i+1] - x;
	}
	
	static vector<int> pos[MAXN * 2];
	for(int i=0; i<=n*2; ++i) pos[i].clear();
	for(int i=1; i<=n; ++i)
	{
		val[i] = f[i-1] + g[i+1];
		pos[val[i] + n].push_back(i);
	}
	
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		
		if(f[r] - f[l-1] == 0)
		{
			printf("0\n\n");
			continue;
		}
		
		bool flag = 0;
		if((r - l + 1) % 2 == 0)
			--r, flag = 1;
		
		printf("%d\n",1 + flag);
		
		int need = f[l-1] + g[r+1] + n;
		printf("%d ",*lower_bound(pos[need].begin(), pos[need].end(), l));
		if(flag) printf("%d ",r+1);
		printf("\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}