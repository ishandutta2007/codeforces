#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,a[N],x,A,B,ans,b[N];
int main()
{
   scanf("%d",&n);
   for (i=1;i<=n;++i)
   {
   	   scanf("%d",&a[i]);
   	   x+=a[i];
   }
   int rest=x%n,sum=x/n;
   for (i=1;i<=n;++i) 
   if (rest&&a[i]>sum) b[i]=sum+1,--rest;
   else b[i]=sum;
   for (i=1;i<=n;++i) { if (rest&&b[i]==sum) ++b[i],--rest; ans+=abs(b[i]-a[i]); }
   printf("%d\n",ans/2);
}