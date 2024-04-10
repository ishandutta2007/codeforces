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
    int n00, n01, n11;
    cin >> n00 >> n01 >> n11;
    string ans;
    if (n00 && n11) {
      ans.push_back('0');
      while (n00--) ans.push_back('0');
      ans.push_back('1');
      --n01;
      while (n11--) ans.push_back('1');
      char cur = '1';
      while (n01--) {
        cur = (cur == '0') ? '1' : '0';
        ans.push_back(cur);
      }
    } else if (n00) {
      ans.push_back('0');
      while (n00--) ans.push_back('0');
      char cur = '0';
      while (n01--) {
        cur = (cur == '0') ? '1' : '0';
        ans.push_back(cur);
      }
    } else {
      ans.push_back('1');
      while (n11--) ans.push_back('1');
      char cur = '1';
      while (n01--) {
        cur = (cur == '0') ? '1' : '0';
        ans.push_back(cur);
      }
    }
    cout << ans << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}