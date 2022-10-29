#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[11];
char c[101];
int main()
{scanf("%d",&n);
 scanf("%s",&c);
 for (i=0;i<strlen(c);i++)
   if (c[i]=='2') a[2]++;
   else if (c[i]=='3') a[3]++; 
   else if (c[i]=='4') a[3]++,a[2]++,a[2]++;
   else if (c[i]=='5') a[5]++;
   else if (c[i]=='6') a[5]++,a[3]++;
   else if (c[i]=='7') a[7]++;
   else if (c[i]=='8') a[7]++,a[2]++,a[2]++,a[2]++;
   else if (c[i]=='9') a[7]++,a[3]++,a[3]++,a[2]++;
for (i=9;i>=2;i--) for (j=1;j<=a[i];j++) printf("%d",i);
}