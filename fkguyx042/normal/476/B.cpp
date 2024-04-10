#include<cstdio>
#include<cstring>
#define s 11
using namespace std;
char a[15],b[15];
int z,l,o,i,j,oo;
double f[13][25];
int main()
{
 scanf("%s%s",a+1,b+1);
 l=strlen(a+1);
 for (i=1;i<=l;i++)if (a[i]=='+')
 o++;else o--;
 for (i=1;i<=l;i++)
 if (b[i]=='+')oo++;
 else if (b[i]=='-')oo--;
 else z++;
 o-=oo;
 f[0][0+s]=1;
 for (i=1;i<=z;i++)
  for (j=-10;j<=10;j++)
   f[i][j+s+1]+=f[i-1][j+s]*0.5,
   f[i][j+s-1]+=f[i-1][j+s]*0.5;
 printf("%.10lf\n",f[z][o+s]);
 return 0;
}