#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int ms = 1e6+5;

int n;
int a[ms];


void solve() {
  int n1, n2;
  cin >> n1;
  int g1 = 0, g2 = 0;
  while(n1--) {
    int x;
    cin >> x;
    g1 = max(x, g1);
  }
  cin >> n2;
  while(n2--) {
    int x;
    cin >> x;
    g2 = max(x, g2);
  }
  if(g1 > g2) {
    cout << "Alice\nAlice\n";
  } else if(g2 > g1) {
    cout << "Bob\nBob\n";
  } else {
    cout << "Alice\nBob\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}