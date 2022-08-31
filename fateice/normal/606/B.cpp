#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,x,y,a[1000][1000],p,q;
char s[1000000];
int main()
{
    int i,j;
    cin>>n>>m>>x>>y>>s;
    p=strlen(s);
    q=n*m;
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        a[i][j]=1;
    for(i=0;i<p;i++)
      {
       printf("%d ",a[x][y]);
       if(a[x][y]==1)
         {
          q--;
          a[x][y]=0;
         }
       if(s[i]=='L' && y>1)
         y--;
       if(s[i]=='R' && y<m)
         y++;
       if(s[i]=='U' && x>1)
         x--;
       if(s[i]=='D' && x<n)
         x++;
      }
    printf("%d\n",q);
    return 0;
}