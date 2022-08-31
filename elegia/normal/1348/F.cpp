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

const int N = 200010;

int a[N], b[N];
vector<pair<int, int>> ins[N];
int ans[N], res[N];

vector<int> cyc;

bool vis[N];
int prt[N], match[N];
set<int> rem;

bool fl;

void dfs(int i) {
  vis[i] = true;

  while (true) {
    int x;
    {
      auto it = rem.lower_bound(a[i]);
      if (it != rem.end() && *it == ans[i]) ++it;
      if (it == rem.end() || *it > b[i]) break;
      x = match[*it];
    }
    if (vis[x]) {
      while (i != x) {
        cyc.push_back(i);
        i = prt[i];
      }
      cyc.push_back(x);
      reverse(cyc.begin(), cyc.end());
      fl = true;
      return;
    } else {
      prt[x] = i;
      dfs(x);
      if (fl)
        return;
    }

  }

  rem.erase(ans[i]);
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    ins[a[i]].emplace_back(-b[i], i);
  }
  priority_queue<pair<int, int>> q;
  for (int i = 1; i <= n; ++i) {
    for (auto pr : ins[i])
      q.push(pr);
    ans[q.top().second] = i;
    q.pop();
  }
  for (int i = 1; i <= n; ++i) match[ans[i]] = i;
  for (int i = 1; i <= n; ++i) rem.insert(i);
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      dfs(i);
      if (fl)
        break;
    }
  if (!fl) {
    cout << "YES\n" << vector<int>(ans + 1, ans + n + 1) << '\n';
  } else {
    cout << "NO\n" << vector<int>(ans + 1, ans + n + 1) << '\n';
    copy(ans + 1, ans + n + 1, res + 1);
    for (int i = 0; i < cyc.size(); ++i)
      res[cyc[i]] = ans[cyc[(i + 1) % cyc.size()]];
    cout << vector<int>(res + 1, res + n + 1) << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}