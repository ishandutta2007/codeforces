#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXD = 1e3 + 5;
const int mod = 1e9 + 7;

int f[MAXN][MAXD];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	for(int i=1; i<=d; ++i)
	{
		f[i][0] = f[i][n+1] = 0;
		for(int j=n; j>=1; --j)
			f[i][j] = (f[i][j+1] + f[i-1][n - (j-1) + 1] + (i > 1)) %mod;
	}
	
	printf("%d\n",(f[d][1] + 1) %mod);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}