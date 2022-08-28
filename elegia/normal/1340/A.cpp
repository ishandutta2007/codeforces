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
    int n;
    cin >> n;
    vector<int> a(n), pos = a; cin >> a;
    for (int i = 0; i < n; ++i) pos[--a[i]] = i;
    multiset<int, greater<int>> hp;
    map<int, int> val;
    for (int i = 0; i < n; ++i) val.insert(make_pair(i, 1));
    for (int i = 0; i < n; ++i) hp.insert(1);
    bool fl = true;
    for (int i : pos) {
      if (val[i] != *hp.begin()) {
        fl = false;
        break;
      }
      int x = *hp.begin();
      hp.erase(hp.begin());
      auto it = val.upper_bound(i);
      if (it != val.end()) {
        hp.erase(hp.find(it->second));
        hp.insert(it->second += x);
      }
      val.erase(i);
    }
    cout << (fl ? "Yes\n" : "No\n");
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}