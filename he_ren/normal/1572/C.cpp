#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e3 + 5;

int a[MAXN];
int pre[MAXN];

int f[MAXN][MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int lst[MAXN];
	memset(lst,0,(n+1)<<2);
	for(int i=1; i<=n; ++i)
	{
		pre[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	
	for(int l=n; l>=1; --l)
	{
		f[l][l] = 0;
		for(int r=l+1; r<=n; ++r)
		{
			f[l][r] = f[l][r-1];
			for(int k=pre[r]; k>=l; k=pre[k])
				f[l][r] = max(f[l][r], f[l][k] + f[k+1][r-1] + 1);
		}
	}
	
	printf("%d\n",n-f[1][n]-1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}