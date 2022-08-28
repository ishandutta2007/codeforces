#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <tuple>
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

const int P = 1000000007, LIM = 1e7;

int mul(int x, int y) {
  return min(x * (ll)y, (ll)LIM);
}

int mpow(int x, int k) {
    int ret = 1;
    while (k) {
        if (k & 1)
            ret = ret * (ll)x % P;
        x = x * (ll)x % P;
        k >>= 1;
    }
    return ret;
}

int pw(int x, int k) {
  int ret = 1;
    while (k) {
        if (k & 1)
            ret = mul(ret, x);
        x = mul(x, x);
        k >>= 1;
    }
    return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;
    vector<int> k(n);
    cin >> k;
    if (p == 1) {
      cout << (n % 2) << '\n';
      continue;
    }
    sort(k.begin(), k.end(), greater<int>());
    int cur = k[0], u = 0, v = 0;
    for (int val : k) {
      int x = pw(p, cur - val), y = mpow(p, cur - val);
      u = mul(x, u);
      v = v * (ll)y % P;
      if (u) {
        --u;
        if (v-- == 0)
          v = P - 1;
      } else {
        ++u;
        if (++v == P)
          v = 0;
      }
      cur = val;
    }
    //cerr << "GU " << u * pw(p, k.back()) << ' ' << v << '\n';
    v = v * (ll)mpow(p, k.back()) % P;
    cout << v << '\n';
  }


  return 0;
}