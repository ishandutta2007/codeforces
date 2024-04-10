#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, m, a[N], b[N], clr[N];
vector<int> v[N];
void go(int now, int nclr){
  clr[now]=nclr;
  for(auto nxt: v[now]){
    if(clr[nxt]){
      if(clr[now] == clr[nxt]){
        puts("NO");
        exit(0);
      }
      continue;
    }
    go(nxt, 3-nclr);
  }
}
int main(){
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; i++){
    scanf("%d%d", &a[i], &b[i]);
    v[a[i]].push_back(b[i]);
    v[b[i]].push_back(a[i]);
  }
  for(int i=1; i<=n; i++){
    if(clr[i]) continue;
    go(i, 1);
  }
  puts("YES");
  for(int i=0; i<m; i++)
    printf("%c", "01"[clr[a[i]] == 1]);
  puts("");
}