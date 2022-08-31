#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <stack>
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const int P = 1000000007;

int norm(int x) { return x >= P ? (x - P) : x; }

void add(int& x, int y) { if ((x += y) >= P) x -= P; }

void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, P, x, y);
  return norm(x + P);
}

const int N = 100010;

int Base, pw[N], ipw[N];

struct Node {
  int pl, pr, hl, hr;

  Node() {}

  Node(int t) : pl(t < 0), pr(t > 0), hl(t < 0 ? -t : 0), hr(t > 0 ? t : 0) {}
} ST[1 << 18];

pair<int, int> splitL(int o, int k) {
  if (k == 0)
    return make_pair(0, ST[o].hl);
  if (k == ST[o].pl)
    return make_pair(ST[o].hl, 0);
  if (k <= ST[o << 1].pl) {
    auto pr = splitL(o << 1, k);
    return make_pair(pr.first, (P + ST[o].hl - pr.first) * (ll)ipw[k] % P);
  }
  auto pr = splitL(o << 1 | 1, ST[o << 1 | 1].pl - (ST[o].pl - k));
  return make_pair(norm(P + ST[o].hl - pr.second * (ll)pw[k] % P), pr.second);
}

pair<int, int> splitR(int o, int k) {
  if (k == 0)
    return make_pair(0, ST[o].hr);
  if (k == ST[o].pr)
    return make_pair(ST[o].hr, 0);
  if (k <= ST[o << 1 | 1].pr) {
    auto pr = splitR(o << 1 | 1, k);
    return make_pair(pr.first, (P + ST[o].hr - pr.first) * (ll)ipw[k] % P);
  }
  auto pr = splitR(o << 1, ST[o << 1].pr - (ST[o].pr - k));
  return make_pair(norm(P + ST[o].hr - pr.second * (ll)pw[k] % P), pr.second);
}

void update(int o) {
  if (ST[o << 1].pl == -1 || ST[o << 1 | 1].pl == -1) {
    ST[o].pl = -1;
    return;
  }
  ST[o].pl = ST[o << 1].pl;
  ST[o].hl = ST[o << 1].hl;
  ST[o].pr = ST[o << 1 | 1].pr;
  ST[o].hr = ST[o << 1 | 1].hr;
  if (ST[o << 1].pr <= ST[o << 1 | 1].pl) {
    auto pr = splitL(o << 1 | 1, ST[o << 1].pr);
    if (pr.first != ST[o << 1].hr)
      ST[o].pl = -1;
    else {
      ST[o].pl += ST[o << 1 | 1].pl - ST[o << 1].pr;
      add(ST[o].hl, pr.second * (ll) pw[ST[o << 1].pl] % P);
    }
  } else {
    auto pr = splitR(o << 1, ST[o << 1 | 1].pl);
    if (pr.first != ST[o << 1 | 1].hl)
      ST[o].pl = -1;
    else {
      ST[o].pr += ST[o << 1].pr - ST[o << 1 | 1].pl;
      add(ST[o].hr, pr.second * (ll) pw[ST[o << 1 | 1].pr] % P);
    }
  }
  //cerr << "UPD " << o << ' ' << ST[o].pl << ' ' << ST[o].pr << ' ' << ST[o].hl << ' ' << ST[o].hr << '\n';
}

void build(int o, int osz) {
  if (osz == 1) {
    int t; cin >> t;
    ST[o] = t;
    return;
  }
  build(o << 1, osz >> 1);
  build(o << 1 | 1, (osz + 1) >> 1);
  //cerr << "(" << osz << ") ";
  update(o);
}

void change(int o, int osz, int k, int x) {
  if (osz == 1) {
    ST[o] = x;
    return;
  }
  if (k <= (osz >> 1))
    change(o << 1, osz >> 1, k, x);
  else
    change(o << 1 | 1, (osz + 1) >> 1, k - (osz >> 1), x);
  update(o);
}

int n;
bool fl;
stack<int> stk;
stack<pair<int, int>> remain;

void col(int o, int osz, int l, int r) {
  if (r - l + 1 == osz) {
    if (ST[o].pl == -1)
      fl = false;
    //cerr << "PUS " << o << ' ' << ST[o].pl << ' ' << ST[o].pr << '\n';
    stk.push(o);
    return;
  }
  if (r <= (osz >> 1)) col(o << 1, osz >> 1, l, r);
  else if (l > (osz >> 1)) col(o << 1 | 1, (osz + 1) >> 1, l - (osz >> 1), r - (osz >> 1));
  else {
    col(o << 1, osz >> 1, l, osz >> 1);
    col(o << 1 | 1, (osz + 1) >> 1, 1, r - (osz >> 1));
  }
}

bool query(int l, int r) {
  fl = true;
  while (!stk.empty()) stk.pop();
  while (!remain.empty()) remain.pop();
  col(1, n, l, r);
  //cerr << "FINISH\n";
  if (!fl) return false;
  //cerr << "WORK\n";
  while (!stk.empty()) {
    int o = stk.top(); stk.pop();
    int cur = ST[o].pr, curh = 0;
    while (cur) {
      if (remain.empty()) return false;
      int x = remain.top().first, y = remain.top().second;
      //cerr << "Fight " << ST[o].hr << ' ' << ST[x].hl << '\n';
      if (cur >= y) {
        auto pr = splitR(o, ST[o].pr - cur + y);
        if ((P + pr.first - curh) * (ll)ipw[ST[o].pr - cur] % P != splitL(x, ST[x].pl - y).second)
          return false;
        remain.pop();
        curh = pr.first;
        cur -= y;
      } else {
        if ((P + ST[o].hr - curh) * (ll)ipw[ST[o].pr - cur] % P != norm(P + splitL(x, ST[x].pl - y).second - splitL(x, ST[x].pl - y + cur).second * (ll)pw[cur] % P))
          return false;
        remain.top().second -= cur;
        cur = 0;
      }
    }
    remain.emplace(o, ST[o].pl);
  }
  while (!remain.empty()) {
    if (remain.top().second > 0) return false;
    remain.pop();
  }
  return true;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> n >> k;

  Base = rng() % (P - k * 10) + k * 5;
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * (ll)Base % P;
  ipw[n] = inv(pw[n]);
  for (int i = n; i; --i) ipw[i - 1] = ipw[i] * (ll)Base % P;

  build(1, n);

  int q; cin >> q;
  while (q--) {
    int opt, x, y; cin >> opt >> x >> y;
    if (opt == 1)
      change(1, n, x, y);
    else
      cout << (query(x, y) ? "Yes\n" : "No\n");
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}