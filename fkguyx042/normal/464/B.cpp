#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
double eps=1e-6;
int i,j,m,n,p,k;
int a[9][4],b[9][4],c[9][4];
double d[9][9];
double sqr(int x)
{  return (double)1.0*x*x;}
inline bool Check()
{  memset(d,0,sizeof(d)); int i,j;
   for (i=1;i<=8;i++)
     for (j=1;j<=8;j++)
       if(i!=j)
         d[i][j]=sqrt(sqr(b[i][1]-b[j][1])+sqr(b[i][2]-b[j][2])+sqr(b[i][3]-b[j][3]));
   double Len=1e10;
   for (i=2;i<=8;i++) 
     if (d[1][i]<Len) Len=d[1][i];
    for (i=1;i<=8;i++)
    {     int x=0,y=0,z=0;
       for (j=1;j<=8;j++)
         if (i!=j)
         {    if (abs(d[i][j]-Len)<eps) x++;
              if (abs(d[i][j]-Len*sqrt(2.0))<eps) y++;
              if (abs(d[i][j]-sqrt((double)3.0*Len*Len))<eps) z++;
        }
        if (x!=3||y!=3||z!=1) return false;
}
printf("YES\n");
for (i=1;i<=8;i++)
printf("%d %d %d\n",b[i][1],b[i][2],b[i][3]);
return true;
}
int Dfs(int x,int y)
{ if (x==8&&y==4) return Check();
  if (y>=4) return Dfs(x+1,1);
    int i;
  for (i=1;i<=3;i++)
   if (!c[x][i])
   {    b[x][y]=a[x][i];
     c[x][i]=1;
        if (Dfs(x,y+1)) return true;
        c[x][i]=0;
   }
  return false;
}
int main()
{ 
  for (i=1;i<=8;i++)
   for (j=1;j<=3;j++) scanf("%d",&a[i][j]);
   for (i=1;i<=3;i++) b[1][i]=a[1][i];
   if (!Dfs(2,1)) printf("NO\n");
}