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

  int sum, limit; cin >> sum >> limit;
  vector<int> bits;
  for (int i = 0; sum >> i; i++) {
    bits.pb((sum >> i) & 1);
  }

  vector<int> ans;
  bool ok = true;
  for (int i = sz(bits) - 1; i >= 0; i--) {
    int cur;
    for (int j = 0; bits[i] && (cur = (j * 2 + 1) << i) <= limit; j++) {
      ans.pb(cur);
      bits[i]--;
    }

    if (bits[i]) {
      if (i)
        bits[i - 1] += bits[i] * 2;
      else
        ok = false;
    }
  }

  if (!ok)
    cout << -1;
  else {
    cout << sz(ans) << '\n';
    for (auto& i : ans)
      cout << i << ' ';
  }

  return 0;
}