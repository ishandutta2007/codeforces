#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,a[510][510],b[510][510],p;
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        scanf("%d",&b[i][j]);
    for(i=1;i<n;i++)
      for(j=1;j<m;j++)
        if(a[i][j]!=b[i][j])
          a[i][j]^=1,a[i+1][j]^=1,a[i][j+1]^=1,a[i+1][j+1]^=1;
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        if(a[i][j]!=b[i][j])
          p=1;
    if(p)
      printf("no\n");
    else
      printf("yes\n");
    return 0;
}