#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,a[100005],b[100005],Max,l,r,Q[100005],ans;
int power(int x,int y)
{ 
	 int sum=1;
	 for (;y;y>>=1)
	 {
			 if (y&1) sum=1ll*sum*x%Mo;
			 x=1ll*x*x%Mo;
	 }
	 return sum;
}
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]),b[a[i]]++,Max=max(a[i],Max);
	 for (i=Max;i;--i) b[i]+=b[i+1];
	 for (i=1;i<=Max;++i)
   {
		  Q[0]=0;
		  for (j=1;j*j<=i;++j)
		  if (i%j==0)
		    {
				 if (j*j!=i) ++Q[0];
				 ++Q[0];
			}
		  l=1; r=Q[0];
		  for (j=1;j*j<=i;++j)
		  if (i%j==0)
		    {
			   if (j*j!=i) Q[l++]=j;
			   Q[r--]=i/j;
		    }
		  int sum=1;
		  for (j=1;j<Q[0];++j) 
		  sum=1ll*sum*power(j,b[Q[j]]-b[Q[j+1]])%Mo; 
		  sum=1ll*sum*(power(j,b[Q[j]])-power(j-1,b[Q[j]]))%Mo;
		  (ans+=sum)%=Mo;
	}
	printf("%d\n",(ans+Mo)%Mo);
}