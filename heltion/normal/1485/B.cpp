#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int a[maxn];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q, k;
  cin >> n >> q >> k;
  for(int i = 1; i <= n; i += 1) cin >> a[i];
  for(int l, r; q; q -= 1){
    cin >> l >> r;
    cout << (a[r] - a[l] - r + l) * 2 + (k - a[r]) + (a[l] - 1) << "\n";
  }
  return 0;
}