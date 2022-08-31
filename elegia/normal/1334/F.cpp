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

const int N = 500010;
const ll INF = 1e18;

int n, m;
int a[N], p[N], b[N];
vector<int> indx[N];
ll wt[N], sn[N], sum[N], w0[N], w1[N], id[N], fw[N];
ll cmin[N];

void ch(int k, int x) {
  for (; k <= n; k += k & -k)
    fw[k] += x;
}

ll qry(int k) {
  ll ret = 0;
  for (; k; k &= k - 1)
    ret += fw[k];
  return ret;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> p[i];
  cin >> m;
  for (int i = 1; i <= m; ++i) cin >> b[i];

  for (int i = 1; i <= n; ++i) sn[i] = sn[i - 1] + min(p[i], 0);
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + p[i];
  for (int i = 1; i <= n; ++i) indx[a[i]].push_back(i);
  for (int i = 1; i <= m; ++i) id[b[i]] = i;
  for (int i = 1; i <= n; ++i) if (p[i] > 0) ch(i, p[i]);
  for (int i = 1; i < m; ++i) {
    for (int j = b[i - 1] + 1; j <= b[i]; ++j)
      for (int ind : indx[j])
        if (p[ind] > 0)
          ch(ind, -p[ind]);

    for (int ind : indx[b[i]])
      w0[ind] = qry(ind) + sn[ind];
    for (int ind : indx[b[i + 1]])
      w1[ind] = qry(ind - 1) + sn[ind - 1];
  }
  memset(fw, 0, sizeof(fw));
  for (int i = 1; i <= n; ++i)
    if (a[i] > b[m] || p[i] < 0) fw[i] = p[i];
  for (int i = n; i; --i) fw[i] += fw[i + 1];

  fill(cmin + 1, cmin + n, INF);
  ll ans = INF;
  for (int i = 1; i <= n; ++i) {
    if (id[a[i]] == 0) continue;
    ll curdp = INF;
    if (id[a[i]] == 1) {
      curdp = sum[i - 1];
    } else {
      curdp = w1[i] + cmin[id[a[i]] - 1];
    }
    if (id[a[i]] == m) {
      ans = min(ans, curdp + fw[i + 1]);
    } else {
      cmin[id[a[i]]] = min(cmin[id[a[i]]], curdp - w0[i]);
    }
  }
  if (ans >= 1e16) {
    cout << "NO\n";
  } else {
    cout << "YES\n" << ans << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}