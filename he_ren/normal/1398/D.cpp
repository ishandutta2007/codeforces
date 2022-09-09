#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;

inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

int a[MAXN], b[MAXN], c[MAXN];

ll f[MAXN][MAXN][MAXN];

void solve(void)
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	for(int i=1; i<=x; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=y; ++i) scanf("%d",&b[i]);
	for(int i=1; i<=z; ++i) scanf("%d",&c[i]);
	
	sort(a+1,a+x+1); reverse(a+1,a+x+1);
	sort(b+1,b+y+1); reverse(b+1,b+y+1);
	sort(c+1,c+z+1); reverse(c+1,c+z+1);
	
	for(int i=0; i<=x; ++i)
		for(int j=0; j<=y; ++j)
			for(int k=0; k<=z; ++k)
			{
				ll &res = f[i][j][k] = 0;
				if(i) chk_max(res, f[i-1][j][k]);
				if(j) chk_max(res, f[i][j-1][k]);
				if(k) chk_max(res, f[i][j][k-1]);
				if(i&&j) chk_max(res, f[i-1][j-1][k] + a[i] * b[j]);
				if(i&&k) chk_max(res, f[i-1][j][k-1] + a[i] * c[k]);
				if(j&&k) chk_max(res, f[i][j-1][k-1] + b[j] * c[k]);
			}
	printf("%lld\n",f[x][y][z]);
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}