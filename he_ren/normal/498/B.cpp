#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const int MAXM = 5e3 + 5;

int p[MAXN], t[MAXN];

ldb f[2][MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&p[i],&t[i]);
	
	ldb ans = 0;
	
	f[0][0] = 1;
	for(int i=1; i<=n; ++i)
	{
		int now = i&1, lst = !now;
		
		ldb curp = (ldb)p[i] / 100;
		
		ldb must = 1;
		for(int j=1; j<t[i]; ++j) must *= 1 - curp;
		
		ldb sum = 0;
		
		f[now][0] = 0;
		for(int j=1; j<=m; ++j)
		{
			sum = sum * (1 - curp) + f[lst][j-1];
			
			if(j - t[i] >= 0)
			{
				sum -= f[lst][j - t[i]] * must;
				
				f[now][j] = f[lst][j - t[i]] * must;
			}
			else f[now][j] = 0;
			
			f[now][j] += sum * curp;
		}
		
		for(int j=0; j<=m; ++j)
			ans += f[now][j];
	}
	
	printf("%.20lf",(db)ans);
	return 0;
}