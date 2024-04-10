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

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> cnt(n + 1);
    vector<vector<int>> segs;
    for (int rep = 1; rep < n; ++rep) {
      int l; cin >> l;
      vector<int> s(l); cin >> s;
      segs.push_back(s);
      for (int x : s) ++cnt[x];
    }
    vector<int> ans;
    sort(segs.begin(), segs.end(), [&](const vector<int>& lhs, const vector<int>& rhs) { return lhs.size() < rhs.size(); });
    int m = n;
    while (!segs.empty() && segs.back().size() == m) {
      --m;
      int x = find(cnt.begin(), cnt.end(), 1) - cnt.begin();
      ans.push_back(x);
      for (int y : segs.back())
        --cnt[y];
      segs.pop_back();
    }
    if (m == 1) {
      vector<int> vis(n + 1);
      vis[0] = true;
      for (int x : ans) vis[x] = true;
      ans.push_back(find(vis.begin(), vis.end(), false) - vis.begin());
    } else {
      auto test = [=, &ans](int x) {
        vector<int> cans = ans;
        auto cc = cnt;
        auto sgs = segs;
        vector<int> dst(n + 1), mn(n + 1, n);
        while (!sgs.empty()) {
          if (x == -1) return false;
          int id = -1;
          for (int i = 0; i < sgs.size(); ++i) {
            bool fl = false;
            for (int y : sgs[i])
              if (y == x) {
                fl = true;
                break;
              }
            if (fl) {
              id = i;
              break;
            }
          }
          vector<int> vs(n + 1);
          for (int y : sgs[id]) {
            vs[y] = 1;
            dst[y] = max(dst[y], n - (int) cans.size() - (int) sgs[id].size());
          }
          for (int z = 1; z <= n; ++z) if (!vs[z]) mn[z] = min(mn[z], n - (int)cans.size() - (int)sgs[id].size() - 1);
          cans.push_back(x);
          int nxt = -1;
          for (int y : sgs[id])
            if (--cc[y] == 1 && dst[y] <= n - (int)cans.size() - 1 && mn[y] >= n - (int)cans.size() - 1)
              nxt = y;
          sgs.erase(sgs.begin() + id);
          x = nxt;
          //cerr << cc << " nxt " << x << '\n';
        }
        vector<int> vis(n + 1);
        vis[0] = true;
        for (int y : cans) vis[y] = true;
        cans.push_back(find(vis.begin(), vis.end(), 0) - vis.begin());

        if (dst[cans.back()]) swap(cans.back(), cans[cans.size() - 2]);
        if (dst[cans.back()] > 0) return false;
        ans = cans;
        return true;
      };
      for (int i = 1; i <= n; ++i)
        if (cnt[i] == 1 && test(i))
          break;
    }
    reverse(begin(ans), end(ans));
    cout << ans << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}