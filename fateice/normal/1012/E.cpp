#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,a[200010],b[200010],x[200010],y[200010],f[200010],r[200010],c[200010],p,d[200010],q;
map<int,int> h;

inline int fa(int i)
{
    return f[i]==i?i:f[i]=fa(f[i]);
}
inline void unit(int i,int j)
{
    i=fa(i);
    j=fa(j);
    if(i!=j)
      f[i]=j;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  {
	   scanf("%d",&a[i]);
	   b[i]=a[i];
      }
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++)
      if(a[i]!=b[i])
        m--;
    if(m<0)
      {
       printf("-1\n");
       return 0;
      }
    for(i=1;i<=n;i++)
      f[i]=i;
    for(i=n;i>0;i--)
      if(a[i]!=b[i])
        {
         r[i]=h[b[i]];
         h[b[i]]=i;
        }
    for(i=1;i<=n;i++)
      if(a[i]!=b[i])
        {
         x[i]=h[a[i]];
         y[x[i]]=i;
         h[a[i]]=r[h[a[i]]];
         unit(i,x[i]);
        }
    for(i=1,j=0;i<=n;i++)
      if(a[i]!=b[i])
        {
         if(j && b[i]==b[j])
           {
            if(fa(i)!=fa(j))
              {
               f[fa(i)]=fa(j);
               swap(y[i],y[j]);
               x[y[i]]=i;
               x[y[j]]=j;
              }
           }
         j=i;
        }
    for(i=1;i<=n;i++)
      if(a[i]!=b[i] && fa(i)==i)
        c[++p]=i;
    if(m>=3 && p>=3)
      {
       m=min(m,p);
       for(i=m;i>0;i--)
         d[++q]=x[c[i]];
       for(i=1;i<m;i++)
         {
          swap(x[c[i]],x[c[i+1]]);
          f[fa(c[i])]=fa(c[i+1]);
         }
      }
    p=0;
    for(i=1;i<=n;i++)
      if(a[i]!=b[i] && fa(i)==i)
        c[++p]=i;      
    printf("%d\n",p+(q>0));
    for(i=1;i<=n;i++)
      if(a[i]!=b[i] && fa(i)==i)
        {
         for(j=x[i],k=1;j!=i;j=x[j])
           k++;
         printf("%d\n%d",k,i);
         for(j=x[i],k=1;j!=i;j=x[j])
           printf(" %d",j);
         printf("\n");
        }
    if(q)
      {
       printf("%d\n",q);
       for(i=1;i<=q;i++)
         printf("%d ",d[i]);
       printf("\n");
      }      
	return 0;
}