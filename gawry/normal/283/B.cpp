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
const int MAX=2*2*100123;
int n,a[MAX];
typedef pair<int,int> p2;
vector<p2> incoming[MAX];
int64 term[MAX],middle[MAX];
void dfs1(int x,int64 sum){
  term[x]=sum;
  for(int i=0;i<incoming[x].size();i++)dfs1(incoming[x][i].first,sum+incoming[x][i].second);
}
void dfs2(int x,int64 sum){
  middle[x]=sum;
  for(int i=0;i<incoming[x].size();i++)dfs2(incoming[x][i].first,sum+incoming[x][i].second);
}
main(){
  scanf("%d",&n);
  for(int i=2;i<=n;i++)scanf("%d",&a[i]);
  for(int x=2;x<=n;x++){
    int y=x+a[x];
    if(y<=0||y>n){
      incoming[0].push_back(p2(x,a[x]));
    }else{
      incoming[n+y].push_back(p2(x,a[x]));
    }
    y=x-a[x];
    if(y<=0||y>n){
      incoming[0].push_back(p2(n+x,a[x]));
    }else{
      incoming[y].push_back(p2(n+x,a[x]));
    }
  }
  memset(term,-1,sizeof(term));
  dfs1(0,0);
  memset(middle,-1,sizeof(middle));
  dfs2(n+1,0);
  for(a[1]=1;a[1]<n;a[1]++){
    if(term[n+1+a[1]]>-1){
      printf("%I64d\n",term[n+1+a[1]]+a[1]);
    }else {
      int x=n+1+a[1];
      if(middle[x]>-1&&term[n+1]>-1){
        printf("%I64d\n",term[n+1]+middle[x]+a[1]);
      }else{
        puts("-1");
      }
    }
  }
}