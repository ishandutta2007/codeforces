#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define N 100005
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,f[N],l,r;
int main()
{
	 scanf("%d%d",&m,&k);
	 f[0]=1;
	 for (i=1;i<N;++i) 
	 {
	 	 f[i]=f[i-1];
	 	 if (i-k>=0) (f[i]+=f[i-k])%=Mo;
	 }
	 for (i=1;i<N;++i) (f[i]+=f[i-1])%=Mo;
	 for (;m--;)
	 {
	 	 scanf("%d%d",&l,&r);
	 	 printf("%d\n",(f[r]-f[l-1]+Mo)%Mo);
	 }
}