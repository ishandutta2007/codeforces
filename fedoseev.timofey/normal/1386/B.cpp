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
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
#define double long double

const int eps = 1e5;
const double pi = acos(-1);
 
const int N = 1e5 + 7;
 
vector <pair <ll, ll>> who[4 * N];
vector <double> an[4 * N];
 
void add(int ql, int qr, ll f, ll s, double ang, int l, int r, int v) {
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) {
    who[v].push_back({f, s});
    an[v].push_back(ang);
  } else {
    int m = (l + r) >> 1;
    add(ql, qr, f, s, ang, l, m, 2 * v + 1);
    add(ql, qr, f, s, ang, m + 1, r, 2 * v + 2);
  }
} 
 
int ans[N];
multiset <ll> have;
 
int cur_ans = 4;
int cnt = 0;
const ll M = 1e15;
 
void rec(int l, int r, int v) {
  int last_ans = cur_ans;
  for (int i = 0; i < (int)who[v].size(); ++i) {
    auto p = who[v][i];
    ll a = an[v][i] * M;
    if (p.first == 0 && p.second == 0) {
      ++cnt;
    } else {
      have.insert(a);
      ll b = *prev(have.upper_bound(a + (ll)(pi * M) + eps));
 
      if (abs(b - (a + pi * M)) < eps) cur_ans = min(cur_ans, 2);
 
      ll c;
      if (abs(b - a) < eps) {
        c = a;
      } else {
        c = *prev(have.upper_bound(b + pi * M));
      }
      double d = *have.lower_bound(a - pi * M - eps);
      if (abs(d - (a - pi * M)) < eps) cur_ans = min(cur_ans, 2);
      double e;
      if (abs(d - a) < eps) {
        e = a;
      } else {
        e = *have.lower_bound(d - pi * M);
      }
      if (cur_ans > 3 && cnt == 0) {
        if (a - c + 2 * pi * M < pi * M) {
          cur_ans = 3;
        }
      } 
      if (cur_ans > 3 && cnt == 0) {             
        if (e - a + 2 * pi * M < pi * M) {
          cur_ans = 3;
        }
      }
      if (cur_ans > 3 && cnt == 0) {
        if (d - b + 2 * pi * M < pi * M) {
          cur_ans = 3;
        }
      }
    }
  }
  if (l == r) {
    if (cnt > 0) ans[l] = 1;
    else if (cur_ans != 4) ans[l] = cur_ans;
    else ans[l] = 0;
  } else {
    int m = (l + r) >> 1;
    rec(l, m, 2 * v + 1);
    rec(m + 1, r, 2 * v + 2);
  }
  cur_ans = last_ans;
  for (int i = 0; i < (int)who[v].size(); ++i) {
    auto p = who[v][i];
    if (p.first == 0 && p.second == 0) --cnt;
    else {
      have.erase(have.find(an[v][i] * M));
    }
  }
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int aa, bb, cc;
  cin >> aa >> bb >> cc;
  int id = -1;
  if (aa != 0) {
    id = 0;
  } else if (bb != 0) {
    id = 1;
  } else {
    id = 2;
  }
  if (id == 1) {
    swap(aa, bb);
  }
  if (id == 2) {
    swap(aa, cc);
  }
 
  int n;
  cin >> n;
  vector <ll> f, s;
  vector <int> st;
  vector <int> en;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if (c == 'A') {
      int a, b, c;
      cin >> a >> b >> c;
      if (id == 1) swap(a, b);
      if (id == 2) swap(a, c);
      f.push_back((ll)b * aa - (ll)bb * a);
      s.push_back((ll)cc * a - (ll)c * aa);
      st.push_back(i);
      en.push_back(n - 1);
    } else {
      int p;
      cin >> p;
      --p;
      en[p] = i - 1; 
    }
  }
  for (int i = 0; i < (int)f.size(); ++i) {
    double ang = 0;
    if (f[i] != 0 || s[i] != 0) ang = atan2((double)f[i], s[i]);
    add(st[i], en[i], f[i], s[i], ang, 0, n - 1, 0);
  }
  rec(0, n - 1, 0);
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << '\n';
  }
}