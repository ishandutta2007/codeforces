#include <bits/stdc++.h>
using namespace std;

//%:include "utility/defines.h"
//%:include "utility/fast_input.h"
//%:include "utility/output.h"

using ll = long long;
using ld = long double;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(15);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int n, m;
  cin >> n >> m;
  // x in [0, n], y in [0, m]
  auto answer = [n, m](ld x, ld y) -> int {
    cout << "! " << clamp<ld>(x, 0, n-1) << " " << clamp<ld>(y, 0, m-1) << endl;
    //cout << "! " << x << " " << y << endl;
    return 0;
  };

  // just reuse it
  ld area;
  vector<pair<ld, ld>> out;

  // check first row
  cout << "? 4" << nl;
  cout << 0 << " " << 0 << nl;
  cout << n << " " << 0 << nl;
  cout << n << " " << 1 << nl;
  cout << 0 << " " << 1 << nl;
  cout.flush();
  cin >> area;

  if(area) {
    ld offset = 1 - area;
    cout << "? " << 3 << nl;
    cout << 0 << " " << offset << nl;
    cout << n << " " << offset << nl;
    cout << n << " " << 1 + offset << nl;
    cout.flush();
    cin >> area;

    ld idx = area * 2 * n; // in range [1, 2t-1]
    idx = (idx - 1) / 2; // normalize to [0, t-1];
    return answer(idx, offset);
  }

  // zero intersection with first row, find alignment
  out.clear();
  out.emplace_back(0, 0);
  for(int i=0; i<n; i++) {
    if(i % 2 == 0) {
      // go out
      out.emplace_back(i, 1);
      out.emplace_back(i, m);
    } else {
      // go in
      out.emplace_back(i, m);
      out.emplace_back(i, 1);
    }
  }
  if(out.back().second == m) {
    out.emplace_back(n, m);
  }
  out.emplace_back(n, 1);
  out.emplace_back(n, 0);
  reverse(begin(out), end(out));

  cout << "? " << out.size() << nl;
  for(auto [a, b] : out) {
    cout << a << " " << b << nl;
  }
  cout.flush();
  cin >> area;

  // ????
  constexpr ld eps = 1e-13;

  ld offset = min(area, 1 - area);
  if(offset > eps) {
    // got nonzero abs(offset), try it
    out.clear();
    out.emplace_back(0, 0);
    // out.emplace_back(0, 1); // unnecessary
    for(int i=0; i<n; i++) {
      if(i % 2 == 0) {
        // go out
        out.emplace_back(i + offset, 1);
        out.emplace_back(i + offset, m);
      } else {
        // go in
        out.emplace_back(i + offset, m);
        out.emplace_back(i + offset, 1);
      }
    }
    if(out.back().second == m) {
      out.emplace_back(n, m);
    }
    out.emplace_back(n, 1);
    out.emplace_back(n, 0);
    reverse(begin(out), end(out));

    cout << "? " << out.size() << nl;
    for(auto [a, b] : out) {
      cout << a << " " << b << nl;
    }
    cout.flush();
    cin >> area;

    if(min(area, 1 - area) > eps) {
      // guessed wrong
      offset = 1 - offset;
    }
  }

  // correct offset in [0, 1), solve it
  out.clear();
  out.emplace_back(0, 0);
  // out.emplace_back(0, 1); // unnecessary
  for(int i=0; i<n; i++) {
    ld l = (ld)i / n;
    ld r = (ld)(i+1) / n;
    if(i % 2 == 0) {
      // right is in
      out.emplace_back(offset + i + l, 1);
      out.emplace_back(offset + i + r, m);
    } else {
      // left is in
      out.emplace_back(offset + i+1 - l, m);
      out.emplace_back(offset + i+1 - r, 1);
    }
  }
  // out.emplace_back(n, 1); // unnecessary
  out.emplace_back(n, 0);
  reverse(begin(out), end(out));

  cout << "? " << out.size() << nl;
  for(auto [a, b] : out) {
    cout << a << " " << b << nl;
  }
  cout.flush();
  cin >> area;

  if(abs(area - 1) > 1e-9) {
    ld idx = area * 2 * n * (m-1);
    idx = (idx - 1) / 2; // normalize to [0, t)
    int int_part = floor(idx / (m-1));
    ld frac_part = idx - int_part * (m-1);
    int x = n-1 - int_part; // floor
    ld y = (x % 2 == 0 ? m-1 - frac_part : 1 + frac_part);
    return answer(x + offset, y);
  }

  return 0;
}