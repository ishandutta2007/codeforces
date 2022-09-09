#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 500000 + 1;
int a[maxn], bit[maxn], dp[maxn];
vector<int> p[maxn];
int get(int u){
  int m = 0;
  for(; u; u -= u & -u) m = max(m, bit[u]);
  return m;
}
void modify(int u, int m){
  for(; u < maxn; u += u & -u) bit[u] = max(bit[u], m);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, ans = 0;
  cin >> n;
  for(int i = 1; i <= n; i += 1){
    cin >> a[i];
    p[a[i]].push_back(i);
  }
  for(int i = 1; i <= n; i += 1)
    if(p[a[i]][0] == i){
      int R = p[a[i]].back();
      modify(R, dp[R] = get(i - 1) + p[a[i]].size());
    }
  map<int, int> mp;
  int s = 0;
  for(int i = n; i >= 0; i -= 1){
    ans = max(ans, s + dp[i]);
    //cout << s << " " << dp[i] << "\n";
    s = max(s, mp[a[i]] += 1);
  }
  cout << n - ans;
  return 0;
}