#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
const int MAXN = 1e5 + 5;
const ldb eps = 1e-10;

db f[2][MAXN];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	if(d >= m){ printf("1"); return 0;}
	if(n+d < m){ printf("0"); return 0;}
	
	f[0][d] = 1;
	int l=d, r=d;
	for(int i=0; i<n+m; ++i)
	{
		int now = i&1, nxt = now^1;
		for(int j=max(l-1,0); j<=r+1; ++j) f[nxt][j]=0;
		
		int xx = 2*n+d-i, yy = 2*(n-i+m);
		ldb pp = (db)xx/yy, qq = (db)1/yy;
		
		for(int j=l; j<=r; ++j)
		{
			if(f[now][j] <= eps) continue;
			
			db p = pp - j * qq;
			f[nxt][j+1] += f[now][j] * p;
			if(j) f[nxt][j-1] += f[now][j] * (1-p);
		}
		
		if(l) --l;
		while(l<=r && f[nxt][l]<=eps) ++l;
		
		++r;
		while(l<=r && f[nxt][r]<=eps) --r;
		
		if(l>r){ printf("0"); return 0;}
	}
	
	db ans=0;
	for(int i=l; i<=r; ++i)
		ans += f[(n+m)&1][i];
	printf("%.20lf",ans);
	return 0;
}