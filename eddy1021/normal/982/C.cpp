#include <bits/stdc++.h>
using namespace std;
const int N=101010;
int n, ans;
vector<int> v[N];
int go(int now, int prt){
  int sz=1;
  for(int son: v[now]){
    if(son == prt) continue;
    sz+=go(son, now);
  }
  ans+=(sz&1)^1;
  return sz;
}
int main(){
  scanf("%d", &n);
  for(int i=1; i<n; i++){
    int ui, vi;
    scanf("%d%d", &ui, &vi);
    v[ui].push_back(vi);
    v[vi].push_back(ui);
  }
  if(n&1){
    puts("-1");
    return 0;
  }
  go(1, 1);
  printf("%d\n", ans-1);
}