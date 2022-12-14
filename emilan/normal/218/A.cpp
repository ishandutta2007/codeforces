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

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n, k; cin >> n >> k;
  int size = 2 * n + 1;
  vector<int> a(size);
  rep(i, size)
    cin >> a[i];
  
  for (int i = 1; i < size && k; i += 2) {
    if (a[i] - 1 > a[i - 1] && a[i] - 1 > a[i + 1])
      a[i]--, k--;
  }

  for (auto& i : a)
    cout << i << ' ';

  return 0;
}