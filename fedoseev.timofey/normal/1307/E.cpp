#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

int mul(int a, int b) {
  return ((ll)a * b) % md;
}

int power(int a, ll b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int inv(int a) {
  return power(a, md - 2);
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <int> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  vector <int> f(m), h(m);
  for (int i = 0; i < m; ++i) cin >> f[i] >> h[i];
  vector <vector <int>> who(n + 1);
  for (int i = 0; i < m; ++i) who[f[i]].push_back(i);
  vector <int> goL(m, n), goR(m, -1);
  for (int i = 0; i < m; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (s[j] == f[i]) ++cnt;
      if (cnt == h[i]) {
        goL[i] = j;
        break;
      }
    }
    cnt = 0;
    for (int j = n - 1; j >= 0; --j) {
      if (s[j] == f[i]) ++cnt;
      if (cnt == h[i]) {
        goR[i] = j;
        break;
      }
    }
  }
  int mx = 0, cnt = 1;
  for (int i = 0; i < m; ++i) {
    if (goL[i] == n) continue;
    int pos = goL[i];
    vector <int> can(m);
    for (int j = 0; j < m; ++j) {
      if (j == i) continue;
      if (goL[j] < pos && goR[j] > pos) can[j] = 2;
      else if (goL[j] < pos) can[j] = 0;
      else if (goR[j] > pos) can[j] = 1;
      else can[j] = -1;
    }
    int have = 1, cur_cnt = 1;
    for (int col = 1; col <= n; ++col) {  
      if (col == f[i]) {
        int cnt_col = 0; 
        for (int id : who[col]) {
          if (can[id] == 2 || can[id] == 1) ++cnt_col;
        }
        if (cnt_col > 0) {
          ++have;
          cur_cnt = mul(cur_cnt, cnt_col);
        }
        continue;
      }
      int cl = 0, cr = 0, cb = 0;
      for (int id : who[col]) {
        if (can[id] == 2) ++cb;
        else if (can[id] == 0) ++cl;
        else if (can[id] == 1) ++cr;
      }
      int cnt_col = 0;
      if (cl) ++cnt_col;
      if (cr) ++cnt_col;
      cnt_col += cb;
      if (cnt_col == 1) {
        have += 1;
        if (cb > 0) {
          cur_cnt = mul(cur_cnt, 2);
        } else {
          cur_cnt = mul(cur_cnt, max(cl, cr));
        }
      } else if (cnt_col > 1) {
        have += 2;
        int ways = 0;
        add(ways, mul(cl, cr));
        add(ways, mul(cl, cb));
        add(ways, mul(cb, cr));
        add(ways, mul(cb, cb - 1));
        cur_cnt = mul(cur_cnt, ways);
      }
    }
    if (have > mx) {
      mx = have;
      cnt = cur_cnt;
    } else if (have == mx && mx > 0) {
      add(cnt, cur_cnt);
    }
  }
  {
    int have = 0, cur_cnt = 1;
    for (int col = 1; col <= n; ++col) {
      int cnt_col = 0;
      for (int id : who[col]) {
        if (goR[id] != -1) ++cnt_col;
      }
      if (cnt_col > 0) {
        ++have;
        cur_cnt = mul(cur_cnt, cnt_col);
      }
    }
    if (have > mx) {
      mx = have;
      cnt = cur_cnt;
    } else if (have == mx && mx > 0) {
      add(cnt, cur_cnt);
    }
  }
  if (mx == 0) cnt = 1;
  cout << mx << ' ' << cnt << '\n';
}