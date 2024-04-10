#include <cassert>
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

template <class T> void chkMin(T& x, const T& y) {
  if (y < x) x = y;
}

template <class T> void chkMax(T& x, const T& y) {
  if (y > x) x = y;
}

void gg() {
  cout << "IMPOSSIBLE\n";
  exit(0);
}

const int N = 100010;

int n, k, dc;
int l1[N], r1[N], l2[N], r2[N], group[N];
int l[N], r[N], vis[N], disc[N * 4], cnt[N * 4];
int rev[N];
vector<int> addl[N * 4], addr[N * 4], dell[N * 4], delr[N * 4];

vector<int> g[N];

void dfs(int u) {
  group[u] = k;
  if (vis[u] == 1) {
    chkMax(l1[k], l[u]);
    chkMin(r1[k], r[u]);
  } else {
    chkMax(l2[k], l[u]);
    chkMin(r2[k], r[u]);
  }
  for (int v : g[u])
    if (!vis[v]) {
      vis[v] = -vis[u];
      dfs(v);
    } else if (vis[v] == vis[u])
      gg();
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int L, R;
  cin >> L >> R;
  ++R;
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
    ++r[i];
    chkMin(r[i], R);
    if (l[i] >= r[i]) gg();
  }
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      ++k;
      r1[k] = r2[k] = R;
      vis[i] = 1;
      dfs(i);
      if (l1[k] >= r1[k] || l2[k] >= r2[k]) gg();
      disc[++dc] = l1[k];
      disc[++dc] = r1[k];
      disc[++dc] = l2[k];
      disc[++dc] = r2[k];
    }
  }
  disc[++dc] = 0;
  disc[++dc] = R;
  sort(disc + 1, disc + dc + 1);
  dc = unique(disc + 1, disc + dc + 1) - disc - 1;
  for (int i = 1; i <= k; ++i) {
    static int little[4], dl[4];
    little[0] = l1[i]; little[1] = r1[i]; little[2] = l2[i]; little[3] = r2[i];
    sort(little, little + 4);
    for (int j = 0; j < 4; ++j)
      dl[j] = lower_bound(disc + 1, disc + dc + 1, little[j]) - disc;
    for (int j = 0; j < 3; ++j)
      if (little[j] < little[j + 1]) {
        int cl = R, cr = 0;
        if (l1[i] <= little[j] && little[j] < r1[i]) {
          chkMin(cl, l2[i]);
          chkMax(cr, r2[i]);
        }
        if (l2[i] <= little[j] && little[j] < r2[i]) {
          chkMin(cl, l1[i]);
          chkMax(cr, r1[i]);
        }
        if (cl < cr) {
          addl[dl[j]].push_back(cl);
          addr[dl[j]].push_back(cr);
          dell[dl[j + 1]].push_back(cl);
          delr[dl[j + 1]].push_back(cr);
        } else {
          ++cnt[dl[j]];
          --cnt[dl[j + 1]];
        }
      }
    ++cnt[1]; --cnt[dl[0]];
    ++cnt[dl[3]];
  }
  int n1 = -1, n2 = -1;
  multiset<int, greater<int>> lmax;
  multiset<int> rmin;
  lmax.insert(0);
  rmin.insert(R);
  for (int i = 1; i < dc; ++i) {
    cnt[i] += cnt[i - 1];
    for (int al : addl[i])
      lmax.insert(al);
    for (int ar : addr[i])
      rmin.insert(ar);
    for (int dl : dell[i])
      lmax.erase(lmax.find(dl));
    for (int dr : delr[i])
      rmin.erase(rmin.find(dr));
    if (!cnt[i] && *lmax.begin() < *rmin.begin()) {
      int vl1 = *lmax.begin(), vr1 = *rmin.begin() - 1, vl2 = disc[i], vr2 = disc[i + 1] - 1;
      int vall = vl1 + vl2, valr = vr1 + vr2;
      if (max(vall, L) <= min(valr, R - 1)) {
        int goal = max(vall, L);
        n1 = vl1; n2 = goal - n1;
        if (vl2 <= n2 && n2 <= vr2) break;
        n1 = vr1; n2 = goal - n1;
        if (vl2 <= n2 && n2 <= vr2) break;
        n2 = vl2; n1 = goal - n2;
        if (vl1 <= n1 && n1 <= vr1) break;
        n2 = vr2; n1 = goal - n2;
        if (vl1 <= n1 && n1 <= vr1) break;
        assert(false);
      }
    }
  }
  if (n1 == -1)
    gg();
  cout << "POSSIBLE\n" << n1 << ' ' << n2 << '\n';
  for (int i = 1; i <= k; ++i) {
    rev[i] = (n1 < l1[i] || n1 >= r1[i] || n2 < l2[i] || n2 >= r2[i]) ? -1 : 1;
    /*if (rev[i] < 0) {
      assert(n2 >= l1[i] && n2 < r1[i] && n1 >= l2[i] && n1 < r2[i]);
    }*/
  }
  for (int i = 1; i <= n; ++i)
    cout << ((3 - (vis[i] * rev[group[i]])) / 2);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}