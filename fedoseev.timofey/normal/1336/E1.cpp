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

using namespace std;

typedef long long ll;

const int K = 35;

const int md = 998244353;

int sum(int a, int b) {
  a += b;
  if (a >= md) a -= md;
  if (a < 0) a += md;
  return a;
}

int mul(int a, int b) {
  return ((ll)a * b) % md;
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

const int N = 2e5 + 7;
int p2[N];

void transform(vector <int> &v, int l, int r) { 
  if (r - l == 1) return; 
  int mid = (l + r) >> 1;
  transform(v, l, mid); 
  transform(v, mid, r); 
  for(int i = 0; i < mid - l; i++) {
    int a = v[l + i];
    int b = v[mid + i];
    v[l + i] = sum(a, b);
    v[mid + i] = sum(a, -b);
  }
} 

vector <int> get(vector <int> a, vector <int> b) {
  int n = a.size();
  vector <int> c(n);
  transform(a, 0, n);
  transform(b, 0, n);

  for (int i = 0; i < n; ++i) {
    c[i] = mul(a[i], b[i]);
  }
  transform(c, 0, n);
  int x = power(n, md - 2);
  x = power(n, md - 2);
  for (int i = 0; i < n; ++i) {
    c[i] = mul(c[i], x);
  }
  return c;
  /*for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      c[i ^ j] = sum(c[i ^ j], mul(a[i], b[j]));
    }
  }
  return c;*/
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  p2[0] = 1;
  for (int i = 1; i < N; ++i) p2[i] = mul(p2[i - 1], 2);
  int n, m;
  cin >> n >> m;
  vector <ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector <ll> bs(K, -1);
  int sz = 0;

  for (int j = 0; j < n; ++j) {
    ll mask = a[j];
    for (int b = K - 1; b >= 0; --b) {
      if (!((mask >> b) & 1)) continue;
      if (bs[b] == -1) {
        bs[b] = mask;
        ++sz;
        break;
      }
      mask ^= bs[b];
    }
  }

  int l = m / 2;
  int r = m - l;
  vector <int> go(1 << r, -1);
  for (ll m = 0; m < (1 << r); ++m) {
    ll mask = m << l;
    bool bad = false;
    for (int b = r - 1; b >= 0; --b) {
      if (!((mask >> (b + l)) & 1)) continue;
      if (bs[b + l] == -1) {
        bad = true;
        break;
      }
      mask ^= bs[b + l];
    }
    if (!bad) {
      go[m] = mask;
    }
  }
  vector <ll> good;
  for (ll m = 0; m < (1 << l); ++m) {
    ll mask = m;
    bool bad = false;
    for (int b = l - 1; b >= 0; --b) {
      if (!((mask >> b) & 1)) continue;
      if (bs[b] == -1) {
        bad = true;
        break;
      }
      mask ^= bs[b];
    }
    if (!bad) good.push_back(m);
  }
  vector <int> ans(m + 1);
  

  vector <int> p(1 << l);
  for (auto x : good) p[x] = 1;
  
  for (int len = 0; len <= l; ++len) {
    vector <int> g(1 << l);
    for (ll mask = 0; mask < (1 << l); ++mask) {
      if (__builtin_popcountll(mask) != len) continue;
      ++g[mask];
    }
    vector <int> rs = get(p, g);
    for (ll mask = 0; mask < (1 << r); ++mask) {
      if (go[mask] != -1) {
        int cnt = __builtin_popcountll(mask) + len;
        ans[cnt] = sum(ans[cnt], mul(p2[n - sz], rs[go[mask]]));
      }
    }
  }
  /*
  for (int ms1 = 0; ms1 < (1 << l); ++ms1) {
    for (int ms2 = 0; ms2 < (1 << r); ++ms2) {
      if (go[ms2] != -1 && p[go[ms2] ^ ms1]) {
        int l = __builtin_popcount(ms1) + __builtin_popcount(ms2);
        ans[l] = sum(ans[l], p2[n - sz]);
      }
    }
  }*/
  
  for (int i = 0; i <= m; ++i) {
    cout << ans[i] << ' ';
  }
}