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

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> k(n);
  cin >> k;
  int A = *max_element(k.begin(), k.end());
  vector<int> pf(A + 1), cnt(A + 1);
  vector<vector<int>> primt(A + 1);
  for (int ki : k) ++cnt[ki];
  for (int i = 2; i <= A; ++i) {
    if (!pf[i]) {
      for (int j = i; j <= A; j += i)
        pf[j] = 1;
      for (int j = i; j <= A; ++j) {
        int cur = j / i, cn = 0;
        while (cur) {
          cn += cur;
          cur /= i;
        }
        while (cn--) primt[j].push_back(i);
      }
    }
  }
  for (int i = 0; i <= A; ++i) {
    reverse(primt[i].begin(), primt[i].end());
    //cerr << i << ": " << primt[i] << '\n';
  }
  vector<int> vals;
  vector<int> bdp(A + 1);
  for (int i = 0; i <= A; ++i)
    vals.push_back(i);
  vector<int> centr;
  function<void(vector<int>)> build = [&](const vector<int> &vls) {
    vector<pair<int, int>> ord;
    for (auto i : vls) {
      if (bdp[i] < primt[i].size())
        ord.emplace_back(primt[i][bdp[i]++], i);
    }
    ord.emplace_back(-1, -1);
    int cur = 0;
    for (int j = 1; j < ord.size(); ++j) {
      if (ord[j].first != ord[j - 1].first) {
        int th = 0;
        vector<int> cand;
        for (; cur < j; ++cur) {
          cand.push_back(ord[cur].second);
          th += cnt[ord[cur].second];
        }
        if (th * 2 >= n) {
          centr.push_back(ord[j - 1].first);
          build(cand);
        }
      }
    }
  };
  build(vals);
  ll ans = 0;
  for (int i = 0; i <= A; ++i) {
    int j = 0;
    while (j < min(centr.size(), primt[i].size()) && centr[j] == primt[i][j])
      ++j;
    ans += (centr.size() + primt[i].size() - j * 2) * (ll)cnt[i];
  }
  cout << ans << '\n';
  //cerr << prt << '\n' << sub << '\n';


#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}