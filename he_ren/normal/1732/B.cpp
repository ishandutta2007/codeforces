#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

char s[MAXN];
int a[MAXN], f[MAXN][2];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	for(int i=1; i<=n; ++i)
		a[i] = s[i] - '0';
	
	for(int i=1; i<=n; ++i)
		f[i][0] = f[i][1] = inf;
	
	f[n][0] = f[n][1] = 0;
	for(int i=n-1; i>=1; --i)
		for(int j=0; j<=1; ++j)
			for(int k=0; k<=1; ++k)
				if((a[i] ^ j) <= (a[i+1] ^ j ^ k))
					f[i][j] = min(f[i][j], f[i+1][j^k] + k);
	
	int ans = min(f[1][0], f[1][1] + 1);
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}