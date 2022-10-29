#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
const int Maxn=1000005;
int i,j,m,n,p,k;
int Two[10000010];
int f[505][505];
int main()
{
	 scanf("%d%d",&n,&k);
	 Two[0]=1;
	 for (i=1;i<=Maxn;i++) Two[i]=1ll*Two[i-1]*2ll%Mo;
	 for (i=0;i<=n;i++) f[i][0]=1;
	 for (i=1;i<=n;i++)
	   for (j=1;j<=min(i,k);j++)
	     for (p=j-1;p<=i;p++)
	       (f[i][j]+=1ll*f[p][j-1]*(Two[i-p]-1+Mo)%Mo*Two[(i-p)*p]%Mo)%=Mo;
	    printf("%d\n",f[n][k]);
}