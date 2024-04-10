#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,Case1,Case2;
long long ans=-(long long)1e15,sum;
long long sqr(int x) { return 1ll*x*x;} 
int main()
{scanf("%d%d",&n,&m);
if (!n) { printf("%I64d\n",-sqr(m));  for (i=1;i<=m;i++) printf("x"); }
else if (!m) {  printf("%I64d\n",sqr(n)); for (i=1;i<=n;i++) printf("o"); }
else {
  for (i=1;i<=n;i++) {
    if (i-1>0&&i-1<=m)
  {      sum=0;
         sum=(i-1)+sqr(n-i+1);
         k=m/(i-1);
         p=m%(i-1);
         sum-=1ll*(i-1-p)*sqr(k)+1ll*p*sqr(k+1);
         if (sum>ans)
         { ans=sum;
           Case1=i;
           Case2=i-1;
         }
         //ans=max(ans,sum);
  }
   if (i<=m)
  {   sum=0;
      sum=(i-1)+sqr(n-i+1);
      k=m/i;
      p=m%i;
      sum-=1ll*(i-p)*sqr(k)+1ll*p*sqr(k+1);
       if (sum>ans)
         { ans=sum;
           Case1=i;
           Case2=i;
         }
  }
  if (i+1<=m)
  {  sum=0;
     sum=(i-1)+sqr(n-i+1);
     k=m/(i+1);
     p=m%(i+1);
     sum-=1ll*(i+1-p)*sqr(k)+1ll*p*sqr(k+1);
       if (sum>ans)
         { ans=sum;
           Case1=i;
           Case2=i+1;
         }
}
}
printf("%I64d\n",ans);
if (Case1==Case2+1)
 { p=Case2-m%Case2;k=m/Case2;  for (i=1;i<Case1;i++)
      {  printf("o");   for (j=1;j<=k;j++) printf("x");
            if (i>p) printf("x");
     }
   for (i=1;i<=n-Case1+1;i++) printf("o");
}
else if (Case1==Case2)
{   p=Case2-m%Case2;k=m/Case2; 
       for (i=1;i<=Case1;i++)
       {    for (j=1;j<=k;j++) printf("x");
            if (i>p) printf("x");
            printf("o");
            if (i==Case1) for (j=1;j<=n-Case1;j++) printf("o");
    }
}
else { p=Case2-m%Case2;k=m/Case2; 
       for (i=1;i<=Case1;i++)
       {    for (j=1;j<=k;j++) printf("x");
            if (i>p) printf("x");
            printf("o");
            if (i==Case1) for (j=1;j<=n-Case1;j++) printf("o");
    }
      for (i=1;i<=k;i++) printf("x");
      if (p!=Case2) printf("x");
}
}
}