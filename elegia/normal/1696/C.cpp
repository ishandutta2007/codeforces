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

vector<pair<int, ll>> seq(int n, int m) {
  vector<pair<int, ll>> ret;
  ret.emplace_back(-1, -1);
  while (n--) {
    int x; cin >> x;
    int cnt = 1;
    while (x % m == 0) {
      x /= m; cnt *= m;
    }
    if (x == ret.back().first) ret.back().second += cnt;
    else ret.emplace_back(x, cnt);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  
  int T; cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    auto s1 = seq(n, m);
    cin >> n;
    auto s2 = seq(n, m);
    cout << (s1 == s2 ? "Yes\n" : "No\n");
  }

  return 0;
}