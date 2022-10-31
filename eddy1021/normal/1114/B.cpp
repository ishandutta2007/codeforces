#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
int n, m, k, a[N];
int main(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  vector<pair<int, int>> v;
  for(int i=1; i<=n; i++) v.push_back({a[i], i});
  sort(v.begin(), v.end());
  vector<int> cand;
  LL ans=0;
  for(int i=0; i<m*k; i++){
    cand.push_back(v.back().second);
    ans+=v.back().first;
    v.pop_back();
  }
  sort(cand.begin(), cand.end());
  printf("%lld\n", ans);
  for(int i=m-1, j=0; j<k-1; j++, i+=m)
    printf("%d%c", cand[i], " \n"[j+1==k-1]);
}