//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

using real_t = double;
using complex_t = complex<real_t>;
int const BITS = 20;
int const N = 1 << BITS;
auto const PI = acos(-1.0);

int rev[N];
complex_t roots[N];

void precalc() {
  for (int i = 1; i < N; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (BITS - 1));
  }
  for (int k = 1; k < N; k *= 2) {
    auto const root = polar<real_t>(1, PI / k);
    roots[k] = 1;
    for (int i = 1; i < k; ++i) {
      roots[k + i] = i & 1 ? roots[(k + i) >> 1] * root : roots[(k + i) >> 1];
    }
  }
}

void fft(vector<complex_t>& a) {
  int n = (int) a.size();
  int lg = __builtin_ctz(n);
  for (int i = 0; i < n; ++i) {
    int j = rev[i] >> (BITS - lg);
    if (i < j) swap(a[i], a[j]);
  }
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; ++j) {
        auto u = a[i + j];
        auto v = a[i + j + k] * roots[j + k];
        a[i + j] = u + v;
        a[i + j + k] = u - v;
      }
    }
  }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
  int need = max(1, (int) a.size() + (int) b.size() - 1);
  int pw = 1;
  while (pw < need) pw *= 2;
  vector<complex_t> fa(pw), fb(pw);
  for (int i = 0; i < (int) a.size(); ++i) fa[i] = a[i];
  for (int i = 0; i < (int) b.size(); ++i) fb[i] = b[i];
  fft(fa); fft(fb);
  for (int i = 0; i < pw; ++i) fa[i] *= fb[i];
  fft(fa);
  reverse(fa.begin() + 1, fa.end());
  auto inv_pw = (real_t) 1 / pw;
  vector<int> ans(need);
  for (int i = 0; i < need; ++i) ans[i] = (int) round(fa[i].real() * inv_pw);
  return ans;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  precalc();

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, X, Y;
  cin >> n >> X >> Y;
  vector<int> a(n + 1);
  for (auto& c : a) cin >> c;
  vector<int> pa(X + 1), rpa(X + 1);
  for (auto x : a) {
    pa[x] = 1;
    rpa[X - x] = 1;
  }
  auto can = multiply(pa, rpa);
  int const MAX = (int) 1e6 + 1;
  vector<int> ans(MAX, -1);
  auto Can = [&](int i) {
    //  2 * (y + diff) = i
    if (i % 2) return false;
    i /= 2;
    i -= Y;
    return i > 0 && (X + i < (int) can.size()) && can[X + i];
  };
  for (int i = 1; i < MAX; ++i) {
    if (!Can(i)) continue;
    for (int j = i; j < MAX; j += i) smax(ans[j], i);
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << ans[x] << ' ';
  }
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}