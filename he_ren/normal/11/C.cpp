#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 250 + 10;
const int MAXM = 250 + 10;

inline void clear(int a[],int n){ memset(a,0,(n+1)<<2);}

char s[MAXN][MAXM];
int r[2][MAXN][MAXM], d[2][MAXN][MAXM], rd[2][MAXN][MAXM], ld[2][MAXN][MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	n += 2; m += 2;
	memset(s[1],'0',m+1); memset(s[n],'0',m+1);
	for(int i=2; i<n; ++i) scanf("%s",s[i]+2), s[i][1] = s[i][m] = '0';
	
	for(int k=0; k<=1; ++k)
	{
		for(int i=0; i<=n+1; ++i)
			clear(r[k][i], m+1), clear(d[k][i], m+1), clear(rd[k][i], m+1), clear(ld[k][i], m+1);
		for(int i=n; i>=1; --i)
			for(int j=m; j>=1; --j) if(s[i][j] - '0' == k)
			{
				r[k][i][j] = r[k][i][j+1] + 1;
				d[k][i][j] = d[k][i+1][j] + 1;
				rd[k][i][j] = rd[k][i+1][j+1] + 1;
				ld[k][i][j] = ld[k][i+1][j-1] + 1;
			}
	}
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) if(r[1][i][j] >= 2)
		{
			int len = r[1][i][j];
			
			if(d[1][i][j] == len)
			if(r[1][i+len-1][j] == len && d[1][i][j+len-1] == len)
			
			if(r[0][i-1][j-1] >= len + 2 && d[0][i-1][j-1] >= len + 2)
			if(r[0][i+len][j] >= len + 1 && d[0][i][j+len] >= len + 1)
			
			if(r[0][i+1][j+1] == len-2 && d[0][i+1][j+1] == len-2)
			if(r[0][i+len-2][j+1] == len-2 && d[0][i+1][j+len-2] == len-2)
			++ans;
		}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) if(rd[1][i][j] >= 2)
		{
			int len = rd[1][i][j];
			
			if(ld[1][i][j] == len)
			if(rd[1][i+len-1][j-len+1] == len && ld[1][i+len-1][j+len-1] == len)
			
			if(rd[0][i-1][j] >= len + 1 && ld[0][i-1][j] >= len + 1)
			if(rd[0][i-1][j+1] >= len && ld[0][i-1][j-1] >= len)
			
			if(rd[0][i+len-1][j-len] >= len + 1 && ld[0][i+len-1][j+len] >= len + 1)
			if(rd[0][i+len][j-len] >= len && ld[0][i+len][j+len] >= len)
			
			if(rd[0][i+1][j] >= len-1 && ld[0][i+1][j] >= len-1)
			if(rd[0][i+2][j] >= len-2 && ld[0][i+2][j] >= len-2)
			
			if(rd[0][i+len-1][j-len+2] >= len-1 && ld[0][i+len-1][j+len-2] >= len-1)
			if(rd[0][i+len-1][j-len+3] >= len-2 && ld[0][i+len-1][j+len-3] >= len-2)
				++ans;
		}
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}