#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
const int MAX=100000;
int n,m;
bool t[101][101],s[101][101],u[101];
main(){
  scanf("%d %d",&n,&m);
  int total=0;
  for(int i=1;i<=n;i++){
    int x,y;
    scanf("%d",&x);
    total+=x;
    while(x--){
      scanf("%d",&y);
      t[i][y]=true;
    }
  }
  if(!total){
    printf("%d\n",n);
  }else{
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=m;k++)s[i][j]|=t[i][k]&&t[j][k];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)s[j][k]|=s[j][i]&&s[i][k];
    int ans=0;
    for(int i=1;i<=n;i++)if(!u[i]){
      ++ans;
      //printf(":%d\n",i);
      for(int j=1;j<=n;j++)u[j]|=s[i][j];
    }
    printf("%d\n",ans-1);
  }
}