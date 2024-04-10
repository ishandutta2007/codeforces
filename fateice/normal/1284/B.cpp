#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,x[100010],f[1000010],l[100010],r[100010],p;
L ans;
inline void add(int i)
{
    for(;i<=1000001;i+=(i&-i))
      f[i]++;
}
inline int sum(int i)
{
    int k=0;
    for(;i>0;i^=(i&-i))
      k+=f[i];
    return k;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      {
       scanf("%d",&m);
       for(j=1;j<=m;j++)
         scanf("%d",&x[j]),x[j]++;
       for(j=2;j<=m;j++)
         if(x[j]>x[j-1])
           break;
       if(j>m)
         {
          p++;
          l[p]=x[1];
          r[p]=x[m];
         }
      }
    ans=(L)n*n;
    for(i=1;i<=p;i++)
      add(l[i]);
    for(i=1;i<=p;i++)
      ans-=sum(r[i]);
    cout<<ans;
    return 0;
}