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

const int N = 1010, D = 55, P = 1000000007;

int n, d, cnt, root;
int trie[N * D][10], fail[N * D];
int dp[D][N * D];
char s[N], x[D], y[D];
int digits[D];

void add(int& x, int y) {
  if ((x += y) >= P) x -= P;
}

int calc(char* str) {
  int ret = 0;
  for (int i = 0; i < d; ++i)
    digits[i] = str[i] - '0';
  int o = root;
  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < digits[i]; ++j)
      add(ret, dp[d - i - 1][trie[o][j]]);
    o = trie[o][digits[i]];
  }
  add(ret, dp[0][o]);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s >> x >> y;
  n = strlen(s);
  d = strlen(x);

  root = ++cnt;
  for (int i = 0; i + d / 2 - 1 < n; ++i) {
    int o = root;
    for (int j = 0; j < d / 2; ++j) {
      if (!trie[o][s[i + j] - '0'])
        trie[o][s[i + j] - '0'] = ++cnt;
      o = trie[o][s[i + j] - '0'];
    }
    dp[0][o] = 1;
  }
  queue<int> q;
  for (int i = 0; i < 10; ++i)
    if (trie[root][i]) {
      fail[trie[root][i]] = root;
      q.push(trie[root][i]);
    } else
      trie[root][i] = root;
  while (!q.empty()) {
    int o = q.front(); q.pop();
    for (int i = 0; i < 10; ++i)
      if (trie[o][i]) {
        fail[trie[o][i]] = trie[fail[o]][i];
        q.push(trie[o][i]);
      } else
        trie[o][i] = trie[fail[o]][i];
  }
  for (int i = 1; i <= cnt; ++i)
    if (dp[0][i])
      fill(trie[i], trie[i] + 10, i);
  for (int i = 1; i < d; ++i)
    for (int j = 1; j <= cnt; ++j)
      for (int k = 0; k < 10; ++k)
        add(dp[i][j], dp[i - 1][trie[j][k]]);

  int i = d - 1;
  while (x[i] == '0') x[i--] = '9';
  --x[i];
  cout << (calc(y) - calc(x) + P) % P << '\n';

  return 0;
}