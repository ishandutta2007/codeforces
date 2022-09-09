#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXA = 1e2 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN], b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i],&b[i]);
	
	int sum = 0;
	for(int i=1; i<=n; ++i) sum += b[i];
	for(int i=1; i<=n; ++i) a[i] *= 2;
	
	static int f[2][MAXN][MAXN * MAXA];
	memset(f,0xc0,sizeof(f));
	f[0][0][0] = 0;
	int cursum = 0;
	for(int i=1; i<=n; ++i)
	{
		int lstsum = cursum; cursum += b[i];
		
		int now = i&1, lst = !now;
		for(int j=0; j<=i; ++j)
		{
			for(int k=0; k<=cursum; ++k)
			{
				f[now][j][k] = -inf;
				if(j<i && k <= lstsum) f[now][j][k] = f[lst][j][k];
			}
			
			if(j) for(int k=b[i]; k<=cursum; ++k)
				f[now][j][k] = max(f[now][j][k], f[lst][j-1][k - b[i]] + a[i]);
		}
	}
	
	for(int i=1; i<=n; ++i)
	{
		int ans = 0;
		for(int j=0; j<=sum; ++j)
			ans = max(ans, min(f[n&1][i][j], j + sum));
		printf("%.20lf ",ans / 2.0);
	}
	return 0;
}