#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAXN 111111

using namespace std;

int K[3],T[3],N,NN[3];
int tm[MAXN];

priority_queue< pair<long long,int> > pq;

int main(int argc, char *argv[]){
  scanf("%d%d%d%d%d%d",K,K+1,K+2,T,T+1,T+2);
  scanf("%d",&N);
  int i,a;
  FOR(i,N){ scanf("%d",tm+i); pq.push(make_pair(-tm[i],0)); }
  long long res=0,t;
  N=0;
  while(!pq.empty()){
    t=-pq.top().first;
    a=pq.top().second;
    pq.pop();
    if(a==3) res=max(res,t-tm[N++]);
    else{
      if(K[a]){
        K[a]--;
        pq.push(make_pair(-(t+T[a]),a+1));
      }
      else NN[a]++;
    }
    if(a){
      if(NN[a-1]){
        NN[a-1]--;
        pq.push(make_pair(-(t+T[a-1]),a));
      }
      else K[a-1]++;
    }
  }
  cout << res << endl;
  return 0;
}