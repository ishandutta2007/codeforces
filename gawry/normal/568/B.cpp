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
int n;
const long long MOD=1000000000+7;
const int MAX=4010;
long long choose[MAX][MAX],res[MAX][2];
int main(){
  for(int i=0;i<MAX;i++){
    choose[i][0]=1;
    for(int j=0;j<i;j++){
      choose[i][j+1]=(choose[i-1][j]+choose[i-1][j+1])%MOD;
    }
  }
  scanf("%d",&n);
  res[0][0]=1;
  res[0][1]=0;
  for(int i=1;i<=n;i++){
    res[i][0]=res[i-1][0];
    res[i][1]=(res[i-1][0]+res[i-1][1]*2)%MOD;
    for(int j=0;j<=1;j++){
      long long tmp=0;
      for(int k=2;k<=i;k++){
        tmp+=res[i-k][j]*choose[i-1][k-1];
        tmp%=MOD;
      }
      res[i][j]=(res[i][j]+tmp)%MOD;
    }
  }
  printf("%d\n",(int)res[n][1]);
  return 0;
}