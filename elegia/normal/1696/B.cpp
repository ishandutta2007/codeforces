#include <cmath>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;
using ll = long long;

const int P = 998244353;

int norm(int x) {
  return x >= P ? x - P : x;
}
void add(int& a, int b) {
  if ((a += b) >= P) {
    a -= P;
  }
}
void sub(int& a, int b) {
  if ((a -= b) < 0) {
    a += P;
  }
}
void fam(int& a, int b, int c) {
  a = (a + b * (ull)c) % P;
}
int mpow(int a, int k) {
  if (k == 0) {
    return 1;
  }
  int ret = mpow(a * (ull)a % P, k >> 1);
  if (k & 1) {
    ret = ret * (ull)a % P;
  }
  return ret;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i != n; ++i) cin >> a[i];
    if (count(a.begin(), a.end(), 0) == n) {
      cout << "0\n";
      continue;
    }
    int l = n, r = -1;
    for (int i = 0; i != n; ++i) {
      if (a[i]) {
        l = min(l, i);
        r = i;
      }
    }
    if (count(a.begin() + l, a.begin() + r + 1, 0) == 0) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }

  return 0;
}