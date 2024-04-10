#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

#define fir first
#define sec second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

ostream &operator<<(ostream &os, const pair<char, int> &unit) {
  return os << unit.first << "^" << unit.second;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), a1(n), a2(n);
  cin >> a;
  int X = *max_element(a.begin(), a.end());
  vector<int> pf(X + 1);
  for (int i = 2; i <= X; ++i) {
    if (!pf[i]) {
      for (int j = i; j <= X; j += i)
        pf[j] = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    int x = a[i], q = pf[x], r = 1;
    while (x % q == 0) {
      x /= q;
      r *= q;
    }
    if (x == 1)
      a1[i] = a2[i] = -1;
    else {
      a1[i] = x;
      a2[i] = r;
    }
  }
  cout << a1 << '\n' << a2 << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}