#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define N 10000005
const int Mo=(int)1e9+7;
int n,i;
long long f[N];
int main()
{
	 scanf("%d",&n);
	 f[1]=0;
	 f[2]=3;
	 f[3]=6;
	 for (i=4;i<=n;++i) f[i]=(f[i-1]*2+f[i-2]*3)%Mo;
	 printf("%d\n",f[n]);
}