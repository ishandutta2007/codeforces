#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[101][101][101],LenA,LenB,LenC,ans;
int x,i,j,m,n,p,k,next[101],y,z,X,Y,Z;
struct Node{int x,y,z;}g[101][101][101];
char a[101],b[101],c[101];
int Ans[101];
int main()
{ scanf("%s",&a);
  scanf("%s",&b);
  scanf("%s",&c);
  LenA=strlen(a);
  LenB=strlen(b);
  LenC=strlen(c);
  for (i=LenA;i;i--) a[i]=a[i-1];
  for (i=LenB;i;i--) b[i]=b[i-1];
  for (i=LenC;i;i--) c[i]=c[i-1];
  next[1]=0;
  for (i=2;i<=LenC;i++) {
   while (j&&c[j+1]!=c[i]) j=next[j];
   j+=(c[j+1]==c[i]);
   next[i]=j;
   }
   for (i=1;i<=LenA;i++)
     for (j=1;j<=LenB;j++)
        for (k=0;k<LenC;k++)
    {  
         if (f[i][j][k]<f[i-1][j][k])
          {   f[i][j][k]=f[i-1][j][k];
              g[i][j][k].x=i-1;
              g[i][j][k].y=j;
              g[i][j][k].z=k;
          }
         if (f[i][j][k]<f[i][j-1][k])
         {  f[i][j][k]=f[i][j-1][k];
            g[i][j][k].x=i;
            g[i][j][k].y=j-1;
            g[i][j][k].z=k;
         }
        if (a[i]==b[j])
        {    p=k; while (p&&c[p+1]!=a[i]) p=next[p];
             p+=(c[p+1]==a[i]);
             if (f[i][j][p]<f[i-1][j-1][k]+1)
             {  f[i][j][p]=f[i-1][j-1][k]+1;
                g[i][j][p].x=i-1;
                g[i][j][p].y=j-1;
                g[i][j][p].z=k;
             }
 }
}
 for (i=1;i<LenC;i++) if (f[LenA][LenB][i]>f[LenA][LenB][ans]) ans=i;
 if (f[LenA][LenB][ans]==0) printf("%d\n",ans);
 else {  i=LenA; j=LenB;
         while (i&&j&&f[i][j][ans]>0)
         {     if (g[i][j][ans].x==i-1&&g[i][j][ans].y==j-1)
               Ans[++Ans[0]]=a[i]-'A';
               X=g[i][j][ans].x; Y=g[i][j][ans].y; Z=g[i][j][ans].z;
               i=X; j=Y; ans=Z;
         }
    for (i=Ans[0];i;i--)
      printf("%c",Ans[i]+'A');
  }
}