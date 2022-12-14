#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#define debug(x) cerr << #x << ": <" << (x) << ">\n"
#else
#define debug(x)
#endif
}

#define dotc()  int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)   (int)x.size()
#define eb      emplace_back
#define pb      push_back
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi      first
#define se      second
#define mod     1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  dotc() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    
    set<int> p;
    while (m--) {
      int b; cin >> b;
      p.insert(b);
    }
    
    bool ok = true;
    for (int i = 0; i < n && ok; i++)
      for (int j = 1; j < n - i; j++)
        if (a[j - 1] > a[j]) {
          if (!p.count(j)) {
            ok = false;
            break;
          }
          swap(a[j - 1], a[j]);
        }
    
    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}