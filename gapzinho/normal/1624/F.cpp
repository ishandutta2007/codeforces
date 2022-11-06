#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int ms = 1e6+5;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;

ii arr[ms];

int qry(int u) {
  cout << "+ " << u << endl;
  int x;
  cin >> x;
  return x;
}

void solve() {
  int n;
  cin >> n;
  int lo = 1, hi = n-1;
  int cur = 0;
  while(hi > lo) {
    int mi = (lo+hi+1)/2;
    if(mi % n == 0) mi++;
    int k = n-(mi%n);
    lo += k;
    hi += k;
    mi += k;
    int x = qry(k);
    if(x >= mi/n) lo = mi;
    else hi = mi-1;
  }
  cout << "! " << lo << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); //
  }
  return 0;
}