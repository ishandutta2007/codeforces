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

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> b(m), col(m, -1);
    cin >> b;
    int tot = 0, rep = 0;
    vector<pair<int, int>> prs;
    while (tot < m) {
      vector<int> dst(m);
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
          if (col[i] != -1)
            dst[j] += abs(i - j);
      int sz = 0;
      for (int i = 0; i < m; ++i)
        if (col[i] == -1 && dst[i] == b[i]) {
          col[i] = rep;
          ++tot;
          ++sz;
        }
      prs.emplace_back(sz, rep);
      ++rep;
    }
    vector<pair<int, char>> str(26);
    for (char c : s) ++str[c - 'a'].first;
    for (int i = 0; i < 26; ++i) str[i].second = i + 'a';
    reverse(str.begin(), str.end());
    vector<char> mp(rep);
    int ptr = 0;
    for (int i = 0; i < rep; ++i) {
      while (prs[i].first > str[ptr].first) ++ptr;
      mp[prs[i].second] = str[ptr++].second;
    }
    string ans;
    for (int i = 0; i < m; ++i)
      ans.push_back(mp[col[i]]);
    cout << ans << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}