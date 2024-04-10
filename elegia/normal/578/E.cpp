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

const int N = 100010;

int n;
int lst[N];
bool vis[N];
char s[N];
vector<pair<int, vector<int>>> g[2];

vector<int> solve(int k) {
  vector<int> ret;
  function<void(int)> dfs = [&](int u) {
    while (!g[u].empty()) {
      int v; vector<int> seq;
      tie(v, seq) = g[u].back();
      g[u].pop_back();
      dfs(v);
      ret.insert(ret.end(), seq.begin(), seq.end());
    }
  };
  dfs(k);
  reverse(ret.begin(), ret.end());
  return ret;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> (s + 1);
  n = strlen(s + 1);
  vector<int> lst0, lst1;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'L') {
      lst1.push_back(i);
      if (lst0.empty())
        lst[i] = 0;
      else {
        lst[i] = lst0.back();
        lst0.pop_back();
      }
    } else {
      lst0.push_back(i);
      if (lst1.empty())
        lst[i] = 0;
      else {
        lst[i] = lst1.back();
        lst1.pop_back();
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  int ans = 0;
  for (int i = n; i; --i) {
    if (vis[i]) continue;
    ++ans;
    vector<int> seq;
    int x = i, ls = i;
    while (x) {
      ls = x;
      seq.push_back(x);
      vis[x] = true;
      x = lst[x];
    }
    g[s[ls] == 'L'].emplace_back(int(s[i] != 'L'), seq);
  }
  --ans;
  vector<int> A, B;
  if (count(s + 1, s + n + 1, 'L') * 2 >= n) {
    A = solve(1);
    B = solve(0);
  } else {
    A = solve(0);
    B = solve(1);
  }
  vector<int> Ans;
  if (A.size() == n)
    Ans = A;
  else if (B.size() == n)
    Ans = B;
  else {
    if (A.back() < B.back()) swap(A, B);
    B.push_back(A.back());
    A.pop_back();
    Ans = A;
    Ans.insert(Ans.begin(), B.begin(), B.end());
  }
  cout << ans << '\n' << Ans << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}