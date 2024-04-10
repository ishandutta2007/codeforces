#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll SZ = 262144;
ll* seg = new ll[2*SZ];
ll combine(ll a, ll b) {
  return max(a, b);
}

void update(int p, ll value) {
  for (seg[p += SZ] = value; p > 1; p >>= 1)
    seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {
  ll resL = 0, resR = 0; r++;
  for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
    if (l&1) resL = combine(resL, seg[l++]);
    if (r&1) resR = combine(seg[--r], resR);
  }
  return combine(resL, resR);
}

int main() {
  int n; cin >> n;
  ll v; cin >> v;

  vector<ll> T(n), A(n);
  for (int i = 0; i < n; i++) {
    cin >> T[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<pair<ll,ll>> vs;
  for (int i = 0; i < n; i++) {
    ll t = T[i];
    ll a = A[i];
    if (v * t < abs(a)) {
      continue;
    }
    else {
      ll A = v * t - a;
      ll B = v * t + a;
      vs.push_back({A, B});
    }
  }
  n = (int)vs.size();
  sort(vs.begin(), vs.end());

  map<ll,int> compress;
  set<ll> s;
  for (auto [_, b]: vs) {
    s.insert(b);
  }
  int cnt = 0;
  for (auto b: s) {
    compress[b] = cnt++;
  }
  vector<int> bs;
  for (auto [_, b]: vs) {
    bs.push_back(compress[b]);
  }
  /*
  for (auto b: bs) {
    cout << b << ' ';
  }
  cout << '\n';
  */

  for (int i = 0; i < SZ; i++) update(i, 0);
  int ans = 0;
  for (int b: bs) {
    int q = query(0, b);
    ans = max(ans, q+1);
    int x = max((int)query(b, b), q+1);
    update(b, x);
  }
  cout << ans << '\n';
}