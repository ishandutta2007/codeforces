#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int LB = 30 + 5;

inline int cntMax(int x)
{
	int res=0, tmp=1;
	while(tmp<=x) tmp<<=1, ++res;
	return res;
}

int mod;
inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int f[LB][LB],pw[LB];

void solve(void)
{
	memset(f,0,sizeof(f));
	
	int d;
	scanf("%d%d",&d,&mod);
	
	int n=cntMax(d);
	//printf("n: %d\n",n);
	pw[0]=1;
	for(int i=1; i<=n; ++i)	pw[i] = (pw[i-1]<<1) %mod;
	
	f[0][0]=1;
	int ans=0;
	for(int i=1; i<=n; ++i)
		for(int j=i; j<=n; ++j)
		{
			int &res = f[i][j];
			for(int k=0; k<j; ++k)
				add_mod(res, f[i-1][k]);
			
			ll mul;
			if(j==n)
			{
				mul = d + 1 - pw[j-1];
				mul = ((mul%mod) + mod) %mod;
			}
			else mul = pw[j-1];
			
			res = (ll)res*mul %mod;
			add_mod(ans, res);
		}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}