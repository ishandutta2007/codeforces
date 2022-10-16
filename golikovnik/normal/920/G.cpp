#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int const MAX = 1e6 + 20;
  vector<int> d(MAX, -1);
  for (int i = 2; i < MAX; ++i) {
    if (d[i] >= 0) {
      continue;
    }
    for (int j = i; j < MAX; j += i) {
      d[j] = i;
    }
  }
  auto fetch_primes = [&](int x) {
    vector<int> result;
    while (x > 1) {
      auto pr = d[x];
      result.push_back(pr);
      while (!(x % pr)) {
        x /= pr;
      }
    }
    return result;
  };
  auto query = [&](vector<int> const& prod, vector<int> const& par, int upto) {
    //  number of y: gcd(p, y) == 1, y <= upto
    int result = 0;
    int k = (int) prod.size();
    for (int i = 0; i < k; ++i) {
      auto nguys = upto / prod[i];
      if (!par[i]) {
        result += nguys;
      } else {
        result -= nguys;
      }
    }
    return result;
  };
  int qs;
  cin >> qs;
  while (qs--) {
    int x, p, k;
    cin >> x >> p >> k;
    auto pr = fetch_primes(p);
    auto msk = (int) (1 << pr.size());
    vector<int> prod(msk), par(msk);
    prod[0] = 1;
    int bt = 0;
    for (int i = 1; i < msk; ++i) {
      if (i == (1 << (bt + 1))) {
        bt++;
      }
      prod[i] = prod[i ^ (1 << bt)] * pr[bt];
      par[i] = par[i ^ (1 << bt)] ^ 1;
    }
    auto upto_x = query(prod, par, x);
    k += upto_x;
    //  y: query(y) >= k, query(y - 1) < k
    int left = 0;
    int right = (int) 1e9;
    while (left + 1 != right) {
      //cerr << left << ' ' << right << '\n';
      int middle = (left + right) / 2;
      int c = query(prod, par, middle);
      //cerr << middle << ' ' << p << ' ' << c << '\n';
      if (c < k) {
        left = middle;
      } else {
        right = middle;
      }
    }
    cout << right << '\n';
  }
  return 0;
}