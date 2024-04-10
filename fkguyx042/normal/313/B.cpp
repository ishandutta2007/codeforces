#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
char c[100005];
int a[100005];
int main()
{ 
  scanf("%s",&c);
scanf("%d",&m);n=strlen(c);  for (i=0;i<n;i++)

   if (c[i]==c[i+1]) a[i+1]=a[i]+1;
   else a[i+1]=a[i];
   for (;m--;)
   {  scanf("%d%d",&p,&k);
      printf("%d\n",a[k-1]-a[p-1]);
  }
}