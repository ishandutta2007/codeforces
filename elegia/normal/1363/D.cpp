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
  int nol_cl = clock();
#endif

  auto ask = [&](const vector<int> &vec) {
    cout << "? " << vec.size() << ' ' << vec << endl;
    int ret;
    cin >> ret;
    return ret;
  };

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> sts(k);
    for (int i = 0; i < k; ++i) {
      int c;
      cin >> c;
      sts[i].resize(c);
      cin >> sts[i];
    }
    int maxv = 0;
    vector<int> qry;
    for (int i = 1; i <= n; ++i) qry.push_back(i);
    maxv = ask(qry);
    while (qry.size() > 1) {
      vector<int> rest;
      int sz = qry.size() / 2;
      while (sz--) {
        rest.push_back(qry.back());
        qry.pop_back();
      }
      if (maxv == ask(rest))
        swap(rest, qry);
    }
    int pos = qry[0];
    qry.clear();
    for (int i = 1; i <= n; ++i)
      if (i != pos)
        qry.push_back(i);
    vector<int> ans;
    for (int i = 0; i < k; ++i) {
      if (count(sts[i].begin(), sts[i].end(), pos)) {
        qry.clear();
        set<int> st;
        for (int x : sts[i]) st.insert(x);
        for (int j = 1; j <= n; ++j)
          if (!st.count(j))
            qry.push_back(j);
        ans.push_back(ask(qry));
      } else
        ans.push_back(maxv);
    }
    cout << "! " << ans << endl;
    string goodjob;
    cin >> goodjob;
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}