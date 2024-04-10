#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 5e2 + 5;
const int MAXD = 5e2 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

template<typename T>
inline void chk_max(T &a,T b){ if(a<b) a=b;}

int a[MAXN],b[MAXN];

bool f[MAXN][MAXD];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	
	ll suma=0,sumb=0;
	for(int i=1; i<=n; ++i) suma += a[i];
	for(int i=1; i<=n; ++i) sumb += b[i];
	
	f[0][0]=1;
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<d; ++j)
			f[i][(j + a[i]) %d] = f[i-1][j];
		for(int j=0; j<d; ++j)
		{
			for(int x=1; x<=a[i] && x<d; ++x)
			{
				int y=d-x;
				if(y>b[i]) continue;
				f[i][(j + a[i]-x) %d] |= f[i-1][j];
			}
		}
	}
	
	ll ans = suma/d + sumb/d;
	for(int i=0; i<d; ++i)
		if(f[n][i])
			chk_max(ans, (suma+sumb-i)/d);
	
	printf("%lld",ans);
	return 0;
}