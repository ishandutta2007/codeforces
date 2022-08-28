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

char s[111];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    cin >> s;
    int m = strlen(s);
    for (int i = 0; i < m; ++i)
      if (s[i] == '0') {
        swap(s[i], s[m - 1]);
        break;
      }
    if (s[m - 1] != '0') {
      cout << ("cyan\n");
    } else {
      bool f1 = false;
      int x = 0;
      for (int i = 0; i < m - 1; ++i) {
        x += s[i] - '0';
        if (!((s[i] - '0') & 1))
          f1 = true;
      }
      if (f1 && x % 3 == 0)
        cout << ("red\n");
      else
        cout << ("cyan\n");
    }
  }

  return 0;
}