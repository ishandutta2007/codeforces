#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif
}

#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  vector<vi> b(n);
  ll max = 0, idx = 0;
  for (int i = 0; i < n; i++) {
    b[i] = a;
    for (int j = i + 1; j < n; j++) {
      if (b[i][j - 1] < b[i][j])
        b[i][j] = b[i][j - 1];
    }
    
    for (int j = i; j > 0; j--) {
      if (b[i][j - 1] > b[i][j])
        b[i][j - 1] = b[i][j];
    }

    ll cur = accumulate(all(b[i]), 0ll);
    if (cur > max) {
      max = cur;
      idx = i;
    }
  }

  for (int i = 0; i < n; i++)
    cout << (i ? " " : "") << b[idx][i];

  return 0;
}