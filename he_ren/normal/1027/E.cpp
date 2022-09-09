#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 5e2 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ if((a+=b)>=mod) a-=mod;}

int f[MAXN][MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	f[0][0]=1;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<i; ++j)
			for(int k=0; k<=j; ++k)
				add_mod(f[i][max(k,i-j)], f[j][k]);
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n && i*j<d; ++j)
			add_mod(ans,(2ll*f[n][i]*f[n][j])%mod);
	printf("%d",ans);
	return 0;
}