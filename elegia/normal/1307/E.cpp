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

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

typedef pair<int, int> Pr;

const int N = 5010, P = 1000000007;

int n, m;
int f[N], h[N];
vector<int> pos[N], eat[N];

int norm(int x) { return (x >= P) ? (x - P) : x; }

Pr unite(const Pr& a, const Pr& b) {
  if (a.first != b.first) return max(a, b);
  return make_pair(a.first, norm(a.second + b.second));
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int s;
    cin >> s;
    pos[s].push_back(i);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> f[i] >> h[i];
    eat[f[i]].push_back(h[i]);
  }
  Pr ans(-1, 1);
  for (int i = 1; i <= m; ++i) {
    if (pos[f[i]].size() < h[i]) continue;
    int p = pos[f[i]][h[i] - 1];
    int cur = 1, ws = 1;
    for (int j = 1; j <= n; ++j) {
      int cL = 0, cR = 0, cB = 0;
      for (int h : eat[j]) {
        if (j == f[i] && h == ::h[i]) continue;
        if (pos[j].size() < h) continue;
        bool fL = pos[j][h - 1] < p, fR = pos[j][pos[j].size() - h] > p;
        if (j == f[i]) fL = false;
        if (fL) {
          if (fR)
            ++cB;
          else
            ++cL;
        } else if (fR)
          ++cR;
      }
      if (cL * cR + cL * cB + cR * cB + cB * (cB - 1)) {
        cur += 2;
        ws = ws * (ll)(cL * cR + cL * cB + cR * cB + cB * (cB - 1)) % P;
      } else if (cL + cR + cB) {
        cur += 1;
        ws = ws * (ll)(cL + cR + cB * 2) % P;
      }
    }
//    cerr << i << ": " << cur << ' ' << ws << '\n';
    ans = unite(ans, Pr(cur, ws));
  }
  {
    int p = 0;
    int cur = 0, ws = 1;
    for (int j = 1; j <= n; ++j) {
      int cL = 0, cR = 0, cB = 0;
      for (int h : eat[j]) {
        if (pos[j].size() < h) continue;
        bool fL = pos[j][h - 1] < p, fR = pos[j][pos[j].size() - h] > p;
        if (fL) {
          if (fR)
            ++cB;
          else
            ++cL;
        } else if (fR)
          ++cR;
      }
      if (cL * cR + cL * cB + cR * cB + cB * (cB - 1)) {
        cur += 2;
        ws = ws * (ll)(cL * cR + cL * cB + cR * cB + cB * (cB - 1)) % P;
      } else if (cL + cR + cB) {
        cur += 1;
        ws = ws * (ll)(cL + cR + cB * 2) % P;
      }
    }
    ans = unite(ans, Pr(cur, ws));
  }
  cout << ans.first << ' ' << ans.second << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}