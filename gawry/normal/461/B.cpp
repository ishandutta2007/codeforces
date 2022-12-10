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
const int MOD=1000000007;
int n,c[MAX],one[MAX],zero[MAX];
vi s[MAX];
void dfs(int x,int y=-1){
  if(c[x]==1){
    one[x]=1;
    zero[x]=0;
    FOR(i,s[x].size()){
      dfs(s[x][i]);
      one[x]=(int64)one[x]*zero[s[x][i]]%MOD;
    }
  }else{
    one[x]=0;
    vector<int> tmp;
    tmp.push_back(1);
    FOR(i,s[x].size()){
      dfs(s[x][i]);
      tmp.push_back((int64)tmp.back()*zero[s[x][i]]%MOD);
    }
    zero[x]=tmp.back();
    int prod=1;
    for(int i=s[x].size()-1;i>=0;i--){
//      printf("%d %d %d\n",i,tmp[i],prod);
      one[x]=(one[x]+(int64)tmp[i]*one[s[x][i]]%MOD*prod)%MOD;
      prod=(int64)prod*zero[s[x][i]]%MOD;
    }
  }
  zero[x]=(zero[x]+one[x])%MOD;
//  printf("%d : %d %d\n",x,zero[x],one[x]);
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<n;i++){
    int p;
    scanf("%d",&p);
    s[p].push_back(i);
  }
  for(int i=0;i<n;i++)scanf("%d",&c[i]);
  dfs(0);
  printf("%d\n",one[0]);
  return 0;
}