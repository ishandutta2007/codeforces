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
const int MAX=100000+1;
int n;
vi s[MAX];
double ans;
void dfs(int x,int y=0,int len=1){
  ans+=1.0/len;
  FOR(i,s[x].size())if(s[x][i]!=y)dfs(s[x][i],x,len+1);
}
main(){
  scanf("%d",&n);
  for(int i=1;i<n;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    s[x].push_back(y);
    s[y].push_back(x);
  }
  dfs(1);
  printf("%.6lf\n",ans);
}