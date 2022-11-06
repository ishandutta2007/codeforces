#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifdef flukehn
#include "algo/debug.h"
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int M=32768;
int d[M];
int main(){
#ifdef flukehn
  freopen("A.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  memset(d,-1,sizeof d);
  d[0]=0;
  queue<int> q;
  q.push(0);
  while(!q.empty()) {
    int x=q.front();
    q.pop();
    auto S=[&](int y){
      if(d[y]<0) {
        d[y]=d[x]+1;
        q.push(y);
      }
    };
    S((x-1+M)%M);
    if(x%2==0) {
      S(x/2+M/2);
      S(x/2);
    }
  }
  int n;
  cin>>n;
  For(i,0,n){
    int x;
    cin>>x;
    cout<<d[x]<<" \n"[i+1==n];
  }
}