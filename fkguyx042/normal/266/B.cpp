#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,t;
char a[51],b[51];
int main()
{scanf("%d%d",&n,&t);
scanf("%s",&a);
 for (;t--;)
 {   for (i=0;i<n-1;i++)
      if (a[i]=='B'&&a[i+1]=='G')
      {   b[i]='G'; b[i+1]='B'; i++; }
      else b[i]=a[i];
    if (i<=n-1) b[n-1]=a[n-1];
   memcpy(a,b,sizeof(a));
}
printf("%s\n",a);
}