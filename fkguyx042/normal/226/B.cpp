#include<cstdio>
#include<algorithm>
#include<algorithm>
#include<cstring>
using namespace std;
inline bool cmp(int a,int b) {return a>b;}
int a[100005],i,j,m,n,p,k;
long long sum[100005],Sm,len,ans[100005],q;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for (i=1;i<=n;++i) ans[1]+=1ll*a[i]*(i-1);
	for (i=2;i<n;++i)
   {  
       long long start=1;
        for (len=1,j=0;start<=n;len*=i,++j)
        {
        	long long end=min(start+len-1,(long long)n);
        	ans[i]+=1ll*(sum[end]-sum[start-1])*j;
        	start=end+1;
        }
   }
   scanf("%d",&q);
   for (;q--;)
   {
   	 scanf("%d",&k); k=min(k,n-1);
   	 printf("%I64d ",ans[k]);
   }
}