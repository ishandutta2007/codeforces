#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100001];
int sum;
int i,j,s,t,n,s1,sum1;
int main()
 {scanf("%d",&n);
   for (i=1;i<=n;i++) {scanf("%d",&a[i]); sum+=a[i];}
   scanf("%d%d",&s,&t);
     if (s>t)
      { s1=s; s=t;t=s1;}
     for (i=s;i<=t-1;i++)
       sum1+=a[i];
 printf("%d\n",min(sum1,sum-sum1));
 return 0;
}