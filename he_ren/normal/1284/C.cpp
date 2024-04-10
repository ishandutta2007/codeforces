#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2.5e5 + 5;

int mod;
void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

ll fac[MAXN];
int f[MAXN];

int main(void)
{
	int n;
	scanf("%d%d",&n,&mod);
	
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i] = fac[i-1]*i %mod;
	
	for(int i=1; i<=n; ++i)
		f[i] = fac[n-i]*fac[i] %mod * (n-i+1) %mod;
	for(int i=1; i<=n; ++i)
		add_mod(f[i], f[i-1]);
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		add_mod(ans,f[i]);
	printf("%d",ans);
	return 0;
}