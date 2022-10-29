#include<bits/stdc++.h>
#define N 105
using namespace std;
int a[N][N],ans[N],vis[N],n,i,j,k;
int main(){
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      scanf("%d",&a[i][j]);
  for (k=1;k<=n;k++){
    for (i=1;i<=n;i++)
      if (!vis[i]){
        for (j=1;j<=n;j++)
          if (a[i][j]>k) break;
        if (j>n) break;
      }
    vis[i]=1;ans[i]=k;
  }for (i=1;i<=n;i++)
    printf("%d ",ans[i]);
}