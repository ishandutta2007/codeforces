#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
const double pi=acos(-1.0);
int n,x[2510],y[2510],a[2510];
long double w[2510];
L p;
inline bool cmp(int i,int j)
{
    return w[i]<w[j];
}
inline L C(int n)
{
    return (L)n*(n-1)*(n-2)/6;
}
inline L cp(int i,int j)
{
    return (L)x[i]*y[j]-(L)x[j]*y[i];
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d%d",&x[i],&y[i]);
    p=(L)n*(n-1)*(n-2)*(n-3)*(n-4)/24;
    for(i=1;i<=n;i++)
      {
       for(j=1;j<=n;j++)
         if(j!=i)
           {
            y[j]-=y[i];
            x[j]-=x[i];
            w[j]=atan2l(y[j],x[j]);
            a[j-(j>i)]=j;
           }
       sort(a+1,a+n,cmp);
       for(k=1;k<n-1 && cp(a[1],a[k+1])>0;k++);
       j=1;
       l=k;
       for(k++;k<n;k++)
         {
          while(cp(a[j],a[k])<0)
            j++;
          p-=C(k-j);
         }
       for(k=1;k<=l;k++)
         {
          while(j<=n-1 && cp(a[j],a[k])<=0)
            j++;
          p-=C(k-j+n-1);
         }
       for(j=1;j<=n;j++)
         if(j!=i)
           {
            y[j]+=y[i];
            x[j]+=x[i];
           }
      }
    cout<<p;
    return 0;
}