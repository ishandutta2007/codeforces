#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int>v[10000005];
long long ans;
int i,j,m,n,p,k,a[300005],sum,r[300005],l[300005],s[300005],A[300005];
int ask(int x,int y)
{
	 x=(x+k)%k;
	 return (upper_bound(v[x].begin(),v[x].end(),y)-v[x].begin());
}
int main()
{
	  scanf("%d%d",&n,&k);
	  v[0].push_back(0);
	  for (i=1;i<=n;++i) 
  {
	  scanf("%d",&a[i]); A[i]=a[i]; a[i]%=k;
	  (sum+=a[i])%=k; 
	  s[i]=sum;
	  v[sum].push_back(i);
  }
     for (i=n;i;--i)
	 {
	  r[i]=i+1;
	  while (r[i]<=n&&A[r[i]]<A[i]) r[i]=r[r[i]];
     }
     for (i=1;i<=n;++i)
     {
      l[i]=i-1;
      while (l[i]&&A[l[i]]<=A[i]) l[i]=l[l[i]];
     }
     for (i=1;i<=n;++i)
       if (i-l[i]<r[i]-i)
         for (j=l[i];j<i;++j)
           ans+=ask(s[j]+a[i],r[i]-1)-ask(s[j]+a[i],i-1);
        else 
         for (j=i;j<r[i];++j)
           ans+=ask(s[j]-a[i],i-1)-ask(s[j]-a[i],l[i]-1);
	printf("%I64d\n",ans-n);
}