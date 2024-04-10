#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,s=3,t=1,p,a[100001],b[100001];
struct line
{
       int a,b,p;
}x[100001];
inline bool cmp(line a,line b)
{
       return a.a<b.a || a.a==b.a && a.b>b.b;
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
      scanf("%d%d",&x[i].a,&x[i].b),x[i].p=i;
    sort(x+1,x+m+1,cmp);
    for(i=1;i<=m;i++)
      if(x[i].b==1)
        {
         p++;
         a[x[i].p]=p;
         b[x[i].p]=p+1;
        }
      else
        if(s>p+1)
          break;
        else
          {
           a[x[i].p]=s;
           b[x[i].p]=t;
           t++;
           if(t==s-1)
             {
              s++;
              t=1;
             }
          }
    if(i<=m)
      printf("-1\n");
    else
      for(i=1;i<=m;i++)
        printf("%d %d\n",a[i],b[i]);
    return 0;
}