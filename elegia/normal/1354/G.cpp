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
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  auto ask = [&](const vector<int> &x, const vector<int> &y) {
    cout << "? " << x.size() << ' ' << y.size() << '\n' << x << '\n' << y << '\n' << endl;
    string res;
    cin >> res;
    return res == "FIRST" ? 1 : (res == "SECOND" ? -1 : 0);
  };

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> rest(n), stone;
    iota(rest.begin(), rest.end(), 1);
    {
      int one;
      uniform_int_distribution<int> uid(1, n);
      one = uid(rng);
      for (int rep = 0; rep < 30; ++rep) {
        int nxt = uid(rng);
        if (one != nxt && ask({one}, {nxt}) < 0)
          one = nxt;
      }
      stone.push_back(one);
      rest.erase(rest.begin() + (one - 1));
    }
    while (stone.size() < rest.size())
      if (ask(stone, vector<int>(rest.begin(), rest.begin() + stone.size()))) {
        break;
      } else {
        int u = stone.size();
        stone.insert(stone.end(), rest.begin(), rest.begin() + u);
        rest.erase(rest.begin(), rest.begin() + u);
      }
    int l = 1, r = min(stone.size(), rest.size());
    while (l < r) {
      int mid = (l + r) >> 1;
      if (ask(vector<int>(stone.begin(), stone.begin() + mid), vector<int>(rest.begin(), rest.begin() + mid)))
        r = mid;
      else
        l = mid + 1;
    }
    cout << "! " << rest[l - 1] << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}