#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];
int lst[MAXN][2][2];

inline bool chk(int l,int r)
{
	bool has[2][2];
	for(int x=0; x<=1; ++x)
		for(int y=0; y<=1; ++y)
			has[x][y] = lst[r][x][y] >= l;
	if(has[0][0] && has[0][1]) return 0;
	if(has[1][0] && has[1][1]) return 0;
	if(has[0][0] && has[1][0]) return 0;
	if(has[0][1] && has[1][1]) return 0;
	return 1;
}

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	for(int i=1; i<=n; ++i)
	{
		for(int x=0; x<=1; ++x)
			for(int y=0; y<=1; ++y)
				lst[i][x][y] = lst[i-1][x][y];
		if(s[i] != '?')
			lst[i][s[i] - '0'][i&1] = i;
	}
	
	ll ans = 0;
	for(int i=1,j=1; i<=n; ++i)
	{
		while(!chk(j,i)) ++j;
		ans += i - j + 1;
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}