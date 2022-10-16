//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

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

using I = __int128;

//  upto 10^36
ostream& operator<<(ostream& out, __int128 x) {
  if (x < 0) {
    out << "-";
    x = -x;
  }
#define ll int64_t
  static constexpr ll BASE = ll(1e18);
  if (x < BASE) {
    return out << ((ll) x);
  }
  return out << (ll) (x / BASE) << setw(18) << setfill('0') << (ll) (x % BASE);
#undef ll
}

//  long long
istream& operator>>(istream& in, __int128& x) {
#define ll int64_t
  ll y; in >> y; x = y;
  return in;
#undef ll
}

void solveTest() {
  int n, m;
  cin >> n >> m;
  vector<I> f(m);
  map<I, vector<int>> fs;
  for (int i = 0; i < n; ++i) {
    I x = 0;
    for (int j = 0; j < m; ++j) {
      I y; cin >> y; x += y * j;
    }
    fs[x].push_back(i);
  }
  assert(fs.size() == 2);
  auto[x1, v1] = *fs.begin();
  auto[x2, v2] = *fs.rbegin();
  assert(v2.size() == 1);
  cout << v2[0] + 1 << ' ' << x2 - x1 << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}