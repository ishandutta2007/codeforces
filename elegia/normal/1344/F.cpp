#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
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

typedef bitset<2001> BS;

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string res = ".RYB";
  map<char, int> mp;
  mp['.'] = 0;
  mp['R'] = 1;
  mp['Y'] = 2;
  mp['B'] = 3;
  int n, k;

  cin >> n >> k;

  static BS cur[2];
  vector<BS> basis(n * 2);
  vector<bool> have(n * 2);

  auto ins = [&](BS vec) -> void {
    for (int i = 0; i < n * 2; ++i)
      if (vec[i]) {
        if (have[i])
          vec ^= basis[i];
        else {
          have[i] = true;
          basis[i] = vec;
          return;
        }
      }
    if (vec[n * 2]) {
      cout << "NO\n";
      exit(0);
    }
  };

  for (int i = 0; i < n; ++i) {
    cur[0].set(i << 1);
    cur[1].set(i << 1 | 1);
  }

  while (k--) {
    int m;
    string op;
    cin >> op >> m;
    vector<int> ind(m);
    cin >> ind;
    for (int &k : ind) --k;
    if (op == "mix") {
      char res;
      cin >> res;
      if (res == 'W') res = '.';
      int resv = mp[res];
      BS mask;
      for (int k : ind) {
        mask.set(k << 1);
        mask.set(k << 1 | 1);
      }
      mask.set(n * 2);
      cur[0][n * 2] = (resv & 1);
      cur[1][n * 2] = (resv >> 1) & 1;
      ins(cur[0] & mask);
      ins(cur[1] & mask);
    } else if (op == "RY") {
      for (int k : ind) {
        bool u = cur[0][k << 1], v = cur[1][k << 1];
        cur[0][k << 1] = v; cur[1][k << 1] = u;
        u = cur[0][k << 1 | 1]; v = cur[1][k << 1 | 1];
        cur[0][k << 1 | 1] = v; cur[1][k << 1 | 1] = u;
      }
    } else if (op == "YB") {
      for (int k : ind) {
        if (cur[1][k << 1]) cur[0][k << 1].flip();
        if (cur[1][k << 1 | 1]) cur[0][k << 1 | 1].flip();
      }
    } else {
      for (int k : ind) {
        if (cur[0][k << 1]) cur[1][k << 1].flip();
        if (cur[0][k << 1 | 1]) cur[1][k << 1 | 1].flip();
      }
    }
  }
  cout << "YES\n";
  vector<int> ans(n * 2);
  for (int i = n * 2 - 1; i >= 0; --i)
    if (have[i]) {
      ans[i] = basis[i][n * 2];
      for (int j = i - 1; j >= 0; --j)
        if (basis[j][i])
          basis[j] ^= basis[i];
    }
  for (int i = 0; i < n * 2; i += 2)
    cout << res[ans[i] | (ans[i + 1] << 1)];

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}