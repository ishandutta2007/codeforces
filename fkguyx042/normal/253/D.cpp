#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int m,n,p,k,sum[4001],A[26][4001];
long long ans;
char c[501][501],C;
int a[501][501];
void Check(int x)
{ int l,r=A[x][0];
   for (l=A[x][0];l;l--)
{   while (l<r&&sum[A[x][r]]-sum[A[x][l]-1]>k) r--;
    ans+=1ll*(r-l);
}
}
void check(int x,int y)
{  int i;
   for (i=0;i<26;i++) A[i][0]=0;
  for (i=1;i<=m;i++)
     sum[i]=sum[i-1]+a[y][i]-a[x-1][i];
  for (i=1;i<=m;i++)
   if (c[x][i]==c[y][i]) A[c[x][i]-'a'][++A[c[x][i]-'a'][0]]=i;
   for (i=0;i<26;i++) Check(i);
}
int main()
{freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
  scanf("%d%d%d",&n,&m,&k);
  for (int i=1;i<=n;i++)
  { C=getchar();
    for (int j=1;j<=m;j++)
     c[i][j]=getchar(),a[i][j]=a[i-1][j]+(c[i][j]=='a');
  }
  for (int i=1;i<=n;i++)
    for (int j=i+1;j<=n;j++)
     check(i,j);
    printf("%I64d\n",ans);
    return 0;
}