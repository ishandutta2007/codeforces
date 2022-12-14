#include <bits/stdc++.h>
using namespace std;

void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif
}

using   ll        = long long;
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

int main() {
  ioThings();

  int n, f; cin >> n >> f;
  ll cnt = 0;
  vector<int> bonus;
  for (int i = 0; i < n; i++) {
    int k, l; cin >> k >> l;
    cnt += min(k, l);
    if (k && k < l)
      bonus.pb(min(2 * k, l) - k);
  }

  sort(rall(bonus));
  int size = min(f, sz(bonus));
  for (int i = 0; i < size; i++)
    cnt += bonus[i];
  
  cout << cnt;

  return 0;
}