#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[102][102];
int n,m,i,j,p,k,flag;
bool check(int l,int r,int l1,int r1,int c)
 { int i,j;  for (i=r;i<=r1;i++)
       if (a[l-1][i]==c||a[l1+1][i]==c) return true;
     for (i=l;i<=l1;i++)
       if (a[i][r-1]==c||a[i][r1+1]==c) return true;
       for (i=l;i<=l1;i++)
        for (j=r;j<=r1;j++) if (a[i][j]>0) return true;
        return false;
}
void doit(int l,int r)
 {  int i,j,k,l1;int f[27]; memset(f,0,sizeof(f));
     if (a[l-1][r]==1||a[l][r-1]==1||a[l+1][r]==1||a[l][r+1]==1)
  {    f[a[l-1][r]]++; f[a[l+1][r]]++; f[a[l][r-1]]++;f[a[l][r+1]]++;
      for (l1=2;f[l1]!=0;l1++);
       if (l1==2)  { for (i=2;i+l-1<=n&&i+r-1<=m&&a[l-1][r+i-1]&&!check(l,r,l+i-1,r+i-1,2);i++);
          i--;  for (j=l;j<=l+i-1;j++)
              for (k=r;k<=r+i-1;k++)
               a[j][k]=2;} else
        a[l][r]=l1;
        return;}
  else {  for (i=2;i<=min(n-l+1,m-r+1);i++)
            if (check(l,r,l+i-1,r+i-1,1)) break;
            i--;
            for (j=l;j<=l+i-1;j++)
              for (k=r;k<=r+i-1;k++)
               a[j][k]=1;
               }
}
int main()
 { scanf("%d%d",&n,&m);
     for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
       if (a[i][j]==0) 
       doit(i,j);
      for (i=1;i<=n;i++)
        { for (j=1;j<=m;j++)
          printf("%c",(char)(a[i][j]+65-1));
          printf("\n");
          }
}