#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=22;
int n, m;
LL k, a[N][N], ans;
unordered_map<LL,LL> cnt[N];
void go(int i, int j, LL val){
  if(i<0 or j<0 or i>=n or j>=m) return;
  val^=a[i][j];
  if(i+j == m-1){
    cnt[i][val]++;
    return;
  }
  go(i+1, j, val);
  go(i, j+1, val);
}
void go2(int i, int j, LL val){
  if(i<0 or j<0 or i>=n or j>=m) return;
  if(i+j == m-1){
    auto it=cnt[i].find(val^k);
    if(it!=cnt[i].end())
      ans+=it->second;
    return;
  }
  go2(i-1, j, val^a[i][j]);
  go2(i, j-1, val^a[i][j]);
}
int main(){
  scanf("%d%d%lld", &n, &m, &k);
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      scanf("%lld", &a[i][j]);
  go(0, 0, 0);
  go2(n-1, m-1, 0);
  printf("%lld\n", ans);
}