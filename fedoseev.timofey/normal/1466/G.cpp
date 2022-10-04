#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

template <typename T>
vector<int> z_function(int n, const T &s) {
  vector<int> z(n, n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}
template <typename T>
vector<int> z_function(const T &s) {
  return z_function((int) s.size(), s);
}

const int md = 1e9 + 7;
 
void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
 
int mul(int a, int b) {
  return ((ll)a * b) % md;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += md;
  return a;
}

int power(int a, ll b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, q;
  cin >> n >> q;
  vector <int> pw(n + 1);
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) pw[i] = mul(pw[i - 1], 2);
  vector <int> ip(n + 1);
  ip[n] = power(pw[n], md - 2);
  for (int i = n - 1; i >= 0; --i) ip[i] = mul(ip[i + 1], 2);
  string s0, t;
  cin >> s0 >> t;
  vector <string> ss(n + 1);
  ss[0] = s0;
  for (int i = 0; i < n; ++i) {
    ss[i + 1] = ss[i] + t[i] + ss[i];
    if (ss[i + 1].size() > (int)1e6) break;
  }
  vector <int> sz(n + 1);
  sz[0] = ss[0].size();
  for (int i = 1; i <= n; ++i) sz[i] = max(sz[i - 1], (int)ss[i].size());

  auto cnt = [&] (string w, string s) {
    vector <int> z = z_function(w + '#' + s);
    int ans = 0;
    for (int i = (int)w.size(); i < (int)z.size(); ++i) if (z[i] == (int)w.size()) ++ans;
    return ans;
  };
  
  auto rev = [&] (string s) {
    reverse(s.begin(), s.end());
    return s;
  };
  vector <vector <int>> suf(n + 1, vector <int> (26));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      suf[i][j] = suf[i + 1][j];
    }
    add(suf[i][t[i] - 'a'], pw[n - i]);
  }
  while (q--) {
    int k; string w;
    cin >> k >> w;
    int l = 0, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (sz[m] < w.size()) l = m;
      else r = m;
    }
    if (r >= k) {
      cout << cnt(w, ss[k]) << '\n';
      continue;
    }
    vector <int> z_pref = z_function(w + '#' + ss[r]);
    vector <int> z_suf = z_function(rev(w) + '#' + rev(ss[r]));
    int ans = 0;
    int zs = z_pref.size();
    for (int i = (int)w.size(); i < zs; ++i) if (z_pref[i] == (int)w.size()) ++ans;
    ans = mul(ans, pw[k - r]);
    for (int ln = 0; ln < (int)w.size(); ++ln) {
      int rln = (int)w.size() - ln - 1;
      if ((ln == 0 || z_pref[zs - ln] == ln) && (rln == 0 || z_suf[zs - rln] == rln)) {
        int id = w[ln] - 'a';
        /*int cur = 0;
        for (int j = r; j < k; ++j) {
          cur = mul(cur, 2);
          if (t[j] - 'a' == id) add(cur, 1);
        }
        add(ans, cur);*/
        int cur = sub(suf[r][id], suf[k][id]);
        cur = mul(cur, ip[n - k + 1]);
        add(ans, cur);
      }
    }
    cout << ans << '\n';
  }
}