#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXW = 1e2 + 5;
const int MAXS = MAXN * 2;
const int inf = 0x3f3f3f3f;

int a[MAXN], w[MAXN];

int f[MAXN][MAXS];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&w[i]);
	
	memset(f,0xc0,sizeof(f));
	f[0][0] = 0;
	
	int suma = 0;
	for(int i=1; i<=n; ++i)
	{
		suma += a[i];
		for(int j=0; j<=suma; ++j)
		{
			f[i][j] = f[i-1][j];
			if(j >= a[i] && f[i-1][j - a[i]] >= 0)
				f[i][j] = max(f[i][j], f[i-1][j - a[i]] + w[i]);
		}
	}
	
	int sumw = 0;
	for(int i=1; i<=n; ++i)
		sumw += w[i];
	
	for(int i=1; i<=suma; ++i)
		if(f[n][i] >= 0 && i >= sumw - f[n][i])
		{
			printf("%d",i);
			return 0;
		}
	return 0;
}