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
const int MAX=300123;
int n,c[MAX];
char s[MAX];
vector<int> nbr[MAX];
int child[MAX][26],size[MAX],res[MAX];
void merge(int x,int y){
  for(int i=0;i<26;i++)if(child[y][i]!=-1){
    if(child[x][i]==-1){
      child[x][i]=child[y][i];
    }else{
      merge(child[x][i],child[y][i]);
    }
  }
  size[x]=1;
  for(int i=0;i<26;i++){
    size[x]+=size[child[x][i]];
  }
}
void calc(int x,int parent=-1){
  for(int i=0;i<26;i++){
    child[x][i]=-1;
  }
  for(int i=0;i<nbr[x].size();i++){
    int y=nbr[x][i];
    if(y==parent)continue;
    calc(y,x);
    if(child[x][s[y]-'a']==-1){
      child[x][s[y]-'a']=y;
    }else{
      merge(child[x][s[y]-'a'],y);
    }
  }
  size[x]=1;
  for(int i=0;i<26;i++)if(child[x][i]>-1){
    size[x]+=size[child[x][i]];
  }
  res[x]=c[x]+size[x];
}
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&c[i]);
  }
  scanf(" %s",s);
  for(int i=1;i<n;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    --x;--y;
    nbr[x].push_back(y);
    nbr[y].push_back(x);
  }
  calc(0);
  int best=res[0];
  for(int i=1;i<n;i++){
    best=max(best,res[i]);
  }
  int cnt=0;
  for(int i=0;i<n;i++){
    cnt+=res[i]==best;
  }
  printf("%d\n%d\n",best,cnt);
  return 0;
}