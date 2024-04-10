#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, ans;
vector<int> v[N];
// -1 direct connect
// -2 all okay
// -3 waiting
int go(int now, int prt, int dep){
  bool need=false, cover=false;
  for(int son: v[now]){
    if(son == prt) continue;
    int ret=go(son, now, dep+1);
    if(ret == -2) continue;
    if(ret == -3) need=true;
    else cover=true;
  }
  if(need){
    ans++;
    return -1;
  }
  if(cover or dep<=2) return -2;
  return -3;
}
int main(){
  scanf("%d", &n);
  for(int i=1; i<n; i++){
    int x, y; scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  go(1, 1, 0);
  printf("%d\n", ans);
}