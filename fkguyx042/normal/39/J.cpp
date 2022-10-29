#include<cstdio>
#include<algorithm>
#include<cstring>

#define seed 233
#define Mo 998244353
#define N 1000005
int hash[N],Ans[N],pow[N],i,j,sum;
char c[N],s[N];
using namespace std;
int main()
{
	scanf("%s",c); 
	pow[0]=1; for (i=1;i<N;++i) pow[i]=1ll*pow[i-1]*seed%Mo;
	scanf("%s",s); int len=strlen(s);
	for (i=0;i<len;++i) sum=(1ll*sum*seed%Mo+s[i])%Mo;
	for (i=len+1;i;--i) c[i]=c[i-1];
	for (i=1;i<=len+1;++i) hash[i]=(1ll*hash[i-1]*seed%Mo+c[i])%Mo;
	for (i=1;i<=len+1;++i)
	{
		int sed=(1ll*hash[i-1]*pow[len-i+1]%Mo+hash[len+1]-1ll*hash[i]*pow[len-i+1]%Mo)%Mo;
		sed=(sed+Mo)%Mo;
		if (sed==sum) Ans[++Ans[0]]=i;
	}
	printf("%d\n",Ans[0]);
	for (i=1;i<=Ans[0];++i) printf("%d ",Ans[i]);
}