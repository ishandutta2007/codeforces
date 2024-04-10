#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXM = 1e5 + 5;

int n;
int a[MAXN][MAXN];
char s[MAXM];

void add_mod(int &a,int b){ a+=b; if(a>n) a-=n;}

void solve(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) scanf("%d",&a[i][j]);
	scanf("%s",s+1);
	
	pii chg[4];
	for(int i=1; i<=3; ++i) chg[i] = make_pair(i, 0);
	
	for(int i=1; i<=m; ++i)
	{
		if(s[i] == 'R') add_mod(chg[2].second, 1);
		if(s[i] == 'L') add_mod(chg[2].second, -1 + n);
		if(s[i] == 'D') add_mod(chg[1].second, 1);
		if(s[i] == 'U') add_mod(chg[1].second, -1 + n);
		if(s[i] == 'I') swap(chg[2], chg[3]);
		if(s[i] == 'C') swap(chg[1], chg[3]);
	}
	
	static int ans[MAXN][MAXN];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			int bef[4] = {0, i, j, a[i][j]};
			int aft[4];
			for(int k=1; k<=3; ++k)
				aft[k] = bef[chg[k].first],
				add_mod(aft[k], chg[k].second);
			ans[aft[1]][aft[2]] = aft[3];
		}
	
	for(int i=1; i<=n; ++i, putchar('\n'))
		for(int j=1; j<=n; ++j)
			printf("%d ",ans[i][j]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}