#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 40 + 5;
const int MAXA = 40 + 5;
const int MAXB = 40 + 5;

char s[MAXN];
pii f[MAXN][MAXA][MAXB][MAXN];

void solve(void)
{
	int n,a,b;
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	
	memset(f, 0, sizeof(f));
	f[0][0][0][0] = make_pair(1, -1);
	for(int i=0; i<n; ++i)
		for(int j=0; j<a; ++j)
			for(int k=0; k<b; ++k)
				for(int x=0; x<=i; ++x) if(f[i][j][k][x].first)
				{
					int cur = s[i+1] - '0';
					f[i+1][(j * 10 + cur) % a][k][x+1] = make_pair(1, j);
					f[i+1][j][(k * 10 + cur) % b][x] = make_pair(2, k);
				}
	
	int mnx = -1;
	for(int i=1; i<n; ++i) if(f[n][0][0][i].first)
		if(mnx == -1 || abs(2 * i - n) < abs(2 * mnx - n))
			mnx = i;
	if(mnx == -1){ printf("-1\n"); return;}
	
	static char ans[MAXN];
	for(int i=n, j=0, k=0; i>=1; --i)
	{
		ans[i] = f[i][j][k][mnx].first == 1? 'R': 'B';
		if(ans[i] == 'R') j = f[i][j][k][mnx].second, --mnx;
		else k = f[i][j][k][mnx].second; 
	}
	
	ans[n+1] = 0;
	printf("%s\n",ans+1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}