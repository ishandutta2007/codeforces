#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

char a[MAXN], b[MAXN];
int f[MAXN][MAXN][2], g[MAXN][MAXN][2];

void solve(void)
{
	int n;
	scanf("%d%s%s",&n,a+1,b+1);
	
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=n; ++j)
			for(int k=0; k<=1; ++k)
				f[i][j][k] = g[i][j][k] = 0;
	
	f[0][0][0] = 0; g[0][0][0] = 1;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<i; ++j)
			for(int k=0; k<=1; ++k)
				for(int x=0; x<=1; ++x) for(int y=0; y<=1; ++y)
				{
					if(a[i] != '?' && x != a[i] - '0') continue;
					if(b[i] != '?' && y != b[i] - '0') continue;
					
					ll lstf = f[i-1][j][k], lstg = g[i-1][j][k];
					lstf = (lstf + lstg * j) %mod;
					
					int xx = x, jj = j;
					if(j && xx == k)
					{
						xx ^= 1;
						--jj;
					}
					if(xx != y)
					{
						++jj;
					}
					
					add_mod(f[i][jj][xx], lstf);
					add_mod(g[i][jj][xx], lstg);
				}
	
	int ans = 0;
	for(int k=0; k<=1; ++k)
		add_mod(ans, f[n][0][k]);
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}