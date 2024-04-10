#include <bits/stdc++.h>
using namespace std;
const int N=505050;
inline int getint(){
  int x=0; char c=getchar();
  while(c<'0' or c>'9') c=getchar();
  while(c>='0' and c<='9') x=x*10+c-'0', c=getchar();
  return x;
}
typedef vector<int> basis;
int n, c[N], q, ql[N], qr[N];
vector<int> qid[N];
basis bit[N];
inline int lb(int x){
  return x&(-x);
}
void add_ele(basis& b, int val){
  for(auto j: b)
    val=min(val, val^j);
  if(val) b.push_back(val);
}
void add(int at, int val){
  for(int i=at; i<=n; i+=lb(i))
    add_ele(bit[i], val);
}
int query(int at){
  basis cand;
  for(int i=at; i; i-=lb(i)){
    for(auto j: bit[i])
      add_ele(cand, j);
  }
  int ret=0;
  for(auto i: cand) ret=max(ret, ret^i);
  return ret;
}
int ans[N];
int main(){
  n=getint();
  for(int i=1; i<=n; i++) c[i]=getint();
  q=getint();
  for(int i=0; i<q; i++){
    ql[i]=getint();
    qr[i]=getint();
    qid[ql[i]].push_back(i);
  }
  for(int i=n; i>=1; i--){
    add(i, c[i]);
    for(auto qq: qid[i])
      ans[qq]=query(qr[qq]);
  }
  for(int i=0; i<q; i++) printf("%d\n", ans[i]);
}