#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define inf 1000000000
using namespace std;
int n,m,a,b,c,d,x[4010][30],y[4010][30],f[4010][4010];
char s[4010],t[4010];
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int i,j,k,l;
	scanf("%d%d%d%d%s%s",&a,&b,&c,&d,&s,&t);
	n=strlen(s);
	m=strlen(t);
	for(i=1;i<=n;i++)
	  {
       for(j=0;j<26;j++)
         x[i][j]=x[i-1][j];
       if(i>1)
         x[i][s[i-2]-'a']=i-1;
      }
    for(i=1;i<=m;i++)
      {
       for(j=0;j<26;j++)
         y[i][j]=y[i-1][j];
       if(i>1)
         y[i][t[i-2]-'a']=i-1;
      }
    for(i=0;i<=n;i++)
      for(j=0;j<=m;j++)
        if(i || j)
          {
           f[i][j]=inf;
           if(j)
             f[i][j]=min(f[i][j],f[i][j-1]+a);
           if(i)
             f[i][j]=min(f[i][j],f[i-1][j]+b);
           if(i && j)
             f[i][j]=min(f[i][j],f[i-1][j-1]+(s[i-1]!=t[j-1])*c);
           if((k=x[i][t[j-1]-'a']) && (l=y[j][s[i-1]-'a']))
             f[i][j]=min(f[i][j],f[k-1][l-1]+d+(i-k-1)*b+(j-l-1)*a);
          }
    printf("%d\n",f[n][m]);
	return 0;
}