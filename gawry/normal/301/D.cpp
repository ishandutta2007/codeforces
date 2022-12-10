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
const int MAX=2*110000;
const int POWER=(1<<18);
int n,m,p[MAX],where[MAX],cnt[2*POWER];
vi add[MAX],q[MAX];
void increase(int pos){
  pos+=POWER;
  while(pos){
    ++cnt[pos];
    pos/=2;
  }
}
int count(int from,int to){
  from+=POWER;
  to+=POWER;
  int ans=cnt[from];
  if(from<to)ans+=cnt[to];
  while(from+1<to){
    if(from%2==0)ans+=cnt[from+1];
    if(to%2)ans+=cnt[to-1];
    from/=2;
    to/=2;
  }
  return ans;
}
int l[MAX],r[MAX],ans[MAX];
main(){
  scanf("%d %d",&n,&m);
  FOR(i,n)scanf("%d",&p[i]),where[p[i]]=i;
  for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=i){
    int a=where[i],b=where[j];
    if(a>b)swap(a,b);
    //printf("%d %d\n",a,b);
    add[b].push_back(a);
  }
  FOR(i,m){
    scanf("%d %d",&l[i],&r[i]);
    --l[i];--r[i];
    q[r[i]].push_back(i);
  }
  FOR(i,n){
    FOR(j,add[i].size())increase(add[i][j]);
    FOR(j,q[i].size()){
      int nr=q[i][j];
      ans[nr]=count(l[nr],r[nr]);
    }
  }
  FOR(i,m)printf("%d\n",ans[i]);
}