#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[100010],f[10000],g[10000],r[10000],q,p;
struct orz
{
    int a,b,c;
    inline void init(int A,int B,int C)
    {
        a=A,b=B,c=C;
    }
    inline void flip(int B,int C)
    {
        a=2*B-C,b=B,c=C;
        x[a]^=1;
        x[b]^=1;
        x[c]^=1;
    }
    inline void print()
    {
        printf("%d %d %d\n",a,b,c);
    }
}w[100010],h[10000];
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i,j,k,l,u;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&x[i]);
    while(n>13)
      {
       k=x[n]+x[n-1]+x[n-2];
       if(k==0)
         n-=3;
       else if(k==1)
         {
          for(i=n;!x[i];i--);
          w[++p].flip(n-3,i);
          n-=3;
         }
       else if(k==2)
         if(x[n] && x[n-2])
           w[++p].flip(n-2,n),n-=3;
         else if(x[n-1] && x[n-2])
           w[++p].flip(n-2,n-1),n-=3;
         else
           {
            k=x[n-3]+x[n-4]+x[n-5];
            if(k==0)
              {
               w[++p].flip(n-6,n);
               w[++p].flip(n-6,n-1);
              }
            else if(k==1)
              {
               for(i=n-3;!x[i];i--);
               w[++p].flip(i,n);
               w[++p].flip(n-6,n-1);
              }
            else if(k==2)
              {
               for(i=n-3;!x[i];i--);
               w[++p].flip(i,n);
               for(i=n-3;!x[i];i--);
               w[++p].flip(i,n-1);
              }
            else
              {
               w[++p].flip(n-3,n-1);
               w[++p].flip(n-4,n);
              }
            n-=6;
           }
       else
         {
          w[++p].flip(n-1,n);
          n-=3;
         }
      }
    if(n<=13)
      {
       for(i=1;i<(1<<n);i++)
         f[i]=1e9;
       q=1;
       for(i=1;i<=q;i++)
         {
          for(j=0;j<n;j++)
            for(k=j+1;k+k-j<n;k++)
              {
               l=k+k-j;
               u=(g[i]^(1<<j)^(1<<k)^(1<<l));
               if(f[g[i]]+1<f[u])
                 {
                  f[u]=f[g[i]]+1;
                  g[++q]=u;
                  h[u].init(j+1,k+1,l+1);
                  r[u]=g[i];
                 }
              }
         }
       for(i=1,k=0;i<=n;i++)
         k+=x[i]*(1<<i-1);
       if(f[k]>1e8)
         printf("NO\n");
       else
         {
          while(k)
            {
             w[++p]=h[k];
             k=r[k];
            }
          printf("YES\n%d\n",p);
          for(i=1;i<=p;i++)
            w[i].print();
         }
      }
    return 0;
}