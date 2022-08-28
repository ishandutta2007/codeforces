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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

  auto ask = [&](int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int ret;
    cin >> ret;
    return ret;
  };

  int n;
  cin >> n;

  vector<int> indexes(n);
  iota(indexes.begin(), indexes.end(), 1);
  auto last = indexes;

  int mask = (1 << 11) - 1;

  shuffle(indexes.begin(), indexes.end(), rng);

  const int LIM = 6, REP = 20;

  while (indexes.size() > 2) {
    uniform_int_distribution<int> uid(0, indexes.size() - 2);
    last = indexes;
    int x = indexes[uid(rng)];
    vector<pair<int, int>> tmp;
    int tot = 0;
    mask = (1 << 11) - 1;
    bool f = true;
    for (int y : indexes)
      if (x != y) {
        tmp.emplace_back(ask(x, y), y);
        mask &= tmp.back().first;
        if (++tot >= REP && __builtin_popcount(mask) > LIM) {
          f = false;
          break;
        }
      }
    if (!f) {
      shuffle(indexes.begin(), indexes.end(), rng);
      continue;
    }
    indexes.clear();
    for (const auto&[s, y] : tmp)
      if (s == mask)
        indexes.push_back(y);
    indexes.push_back(x);
  }


  vector<int> ans(n, -1);

  int pos0 = -1;
  if (indexes.size() == 1)
    pos0 = indexes[0];
  else {

    vector<int> oth;
    for (int i = 1; i <= n; ++i) if (!count(indexes.begin(), indexes.end(), i)) oth.push_back(i);
    shuffle(oth.begin(), oth.end(), rng);

    for (int x : oth) {
      int u = ask(x, indexes[0]), v = ask(x, indexes[1]);
      if (u != v) {
        pos0 = u < v ? indexes[0] : indexes[1];
        break;
      } else
        ans[x - 1] = u;
    }
  }
  ans[pos0 - 1] = 0;
  for (int i = 0; i < n; ++i)
    if (ans[i] == -1)
      ans[i] = ask(i + 1, pos0);
  cout << "! " << ans << '\n';

  return 0;
}