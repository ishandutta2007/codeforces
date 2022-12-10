#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

const int MAX=110000;
int n,init[MAX],goal[MAX];
vi s[MAX];
bool taken[MAX];
int dfs(int cur,int prev,int x,int y){
  taken[cur]=init[cur]^goal[cur]^x;
  int res=taken[cur];
  FOR(i,s[cur].size())if(s[cur][i]!=prev){
    res+=dfs(s[cur][i],cur,y,x^taken[cur]);
  }
  return res;
}
int main(){
  scanf("%d",&n);
  FOR(i,n-1){
    int x,y;
    scanf("%d %d",&x,&y);
    s[x].push_back(y);
    s[y].push_back(x);
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&init[i]);
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&goal[i]);
  }
  printf("%d\n",dfs(1,0,0,0));
  for(int i=1;i<=n;i++)if(taken[i]){
    printf("%d\n",i);
  }
  return 0;
}