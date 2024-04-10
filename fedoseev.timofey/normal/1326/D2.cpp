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
#include <chrono>

using namespace std;

typedef long long ll;

struct num {
  static const int MA = 1e9 + 7, MB = 1e9 + 9;

  int a, b;

  num() : a(0), b(0) {}
  num( int x ) : a(x), b(x) { }
  num( int a, int b ) : a(a), b(b) { }

  num operator + ( const num &x ) const { return num((a + x.a) % MA, (b + x.b) % MB); }
  num operator - ( const num &x ) const { return num((a + MA - x.a) % MA, (b + MB - x.b) % MB); }
  num operator * ( int x ) const { return num(((ll)a * x) % MA, ((ll)b * x) % MB); }
  num operator * ( const num &x ) const { return num(((ll)a * x.a) % MA, ((ll)b * x.b) % MB); }
  bool operator == ( const num &x ) const { return a == x.a && b == x.b; }

  explicit operator ll () const { return (ll)a * MB + b + 1; } // > 0
};

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const num P = 293 + (rnd() % (int)(5e8));

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int len = 0;
    while (len < n - len - 1 && s[len] == s[n - len - 1]) {
      ++len;
    }
    string pref, suf;
    for (int i = 0; i < len; ++i) {
      pref += s[i];
    }
    for (int i = n - 1; i >= n - len; --i) {
      suf += s[i];
    }
    string t;
    for (int i = len; i < n - len; ++i) {
      t += s[i];
    }
    s = t;
    n = s.size();
    vector <num> deg(n + 1);
    vector <num> h(n + 1), rh(n + 1);
    deg[0] = 1;
    for (int i = 0; i < n; ++i) {
      deg[i + 1] = deg[i] * P;
    }
    for (int i = 0; i < n; ++i) {
      h[i + 1] = h[i] * P + s[i];
    }
    for (int i = n - 1; i >= 0; --i) {
      rh[i] = rh[i + 1] * P + s[i];
    }
    auto is_pal = [&] (int l, int r) {
      int len = r - l + 1;
      num h1 = h[l + len] - h[l] * deg[len];
      num h2 = rh[l] - rh[l + len] * deg[len];
      return h1 == h2;
    };  
    int max_pref = 0, max_suf = 0;
    for (int i = 0; i < n; ++i) {
      if (is_pal(0, i) && i + 1 > max_pref + max_suf) {
        max_pref = i + 1;
        max_suf = 0;
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      if (is_pal(i, n - 1) && n - i > max_pref + max_suf) {
        max_pref = 0;
        max_suf = n - i;
      }
    }
    for (int i = 0; i < max_pref; ++i) pref += s[i];
    for (int i = n - 1; i >= n - max_suf; --i) suf += s[i];
    reverse(suf.begin(), suf.end());
    cout << pref << suf << '\n';
  }
}