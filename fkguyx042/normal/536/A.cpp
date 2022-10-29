#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Maxn=(int)1e6+5;
int l,r,mid,i,j,m,n,p,k,A,B,t;
long long Sum[Maxn*2],sum[Maxn*2];
void pre()
{
      sum[1]=A;
      for (i=2;i<=Maxn;++i) sum[i]=sum[i-1]+B;
      Sum[1]=sum[1];
      for (i=2;i<=Maxn;++i) Sum[i]=Sum[i-1]+sum[i];
}
int main()
{
    scanf("%d%d%d",&A,&B,&n);
    pre();
    for (;n--;)
  { 
        scanf("%d%d%d",&l,&t,&m);
        if (sum[l]>t) 
        { 
           printf("-1\n");
           continue;
        }
        int L=l,R=Maxn,Mid=0;
        for (;(L+R)>>1!=Mid;)
        {
             Mid=(L+R)>>1;
             if (sum[Mid]<=t&&Sum[Mid]-Sum[l-1]<=1ll*t*m) L=Mid;
             else R=Mid;
        }
        printf("%d\n",L);
   }
}