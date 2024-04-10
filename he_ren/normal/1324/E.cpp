#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e3 + 5;
const int MAXM = 2e3 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN],f[MAXN][MAXM];

int main(void)
{
	int n,m,l,r;
	scanf("%d%d%d%d",&n,&m,&l,&r);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	memset(f,-1,sizeof(f));
	
	f[0][0]=0;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<m; ++j)
		{
			int lst = j-a[i];
			if(lst<0) lst+=m;
			
			chk_max(f[i][j], f[i-1][lst]);
			
			++lst;
			if(lst>=m) lst-=m;
			
			chk_max(f[i][j], f[i-1][lst]);
			
			if(~f[i][j] && l<=j && j<=r)
				++f[i][j];
		}
	
	int ans=-1;
	for(int i=0; i<m; ++i)
		chk_max(ans, f[n][i]);
	printf("%d",ans);
	return 0;
}