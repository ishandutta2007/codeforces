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

int n,c[24],ones,N,t[24],deg[24];
void go(int next){
  if(next==N){
    int needs=0;
    for(int i=0;i<N;i++){
      needs+=t[i]-1;
      if(deg[i]+t[i]-1<2||needs>ones)return;
    }
    if(needs==ones){
      throw 0xdead;
    }
  }else{
    for(int i=0;i<next;i++)if(t[i]>t[next]){
      t[i]-=t[next];
      ++deg[i];
      go(next+1);
      t[i]+=t[next];
      --deg[i];
    }
  }
}
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&c[i]);
  sort(c,c+n);
  ones=0;
  for(int i=0;i<n;i++)ones+=c[i]==1;
  if(ones<=n-ones){
    puts("NO");
    return 0;
  }
  if(n==1&&c[0]==1){
    puts("YES");
    return 0;
  }
  N=0;
  for(int i=0;i<n;i++)if(c[i]>1)t[N++]=c[i];
  reverse(t,t+N);
  try{
    go(1);
    printf("NO\n");
  }catch(...){
    printf("YES\n");
  }
  return 0;
}