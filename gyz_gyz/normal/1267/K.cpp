#include<bits/stdc++.h>
using namespace std;
#define N 21
#define LL long long
LL T,k,n,a[N],p[N],cnt[N];
LL cal()
{
    LL ans=1;
    memset(cnt,0,sizeof(cnt));
    for(LL i=n;i>=1;i--)
      ans*=i-max(a[i],1ll)+1,cnt[a[i]]++;
    for(LL i=0;i<N;i++)
      ans/=p[cnt[i]];
    return ans;
}
int main()
{
	p[0]=1;
	for(LL i=1;i<N;i++)
	  p[i]=p[i-1]*i;
	scanf("%lld",&T);
	while(T--)
	  {
	  n=0;
	  scanf("%lld",&k);
	  for(LL i=2;i<N && k;i++)
	    a[++n]=k%i,k/=i;
      sort(a+1,a+n+1);
      LL ans=cal();
      if(a[1]==0)
        {
        for(LL i=1;i<n;i++)
          a[i]=a[i+1];
        n--;
        ans-=cal();
        }
      printf("%lld\n",ans-1);
	  }
}