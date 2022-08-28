#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>

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

#define fir first
#define sec second

typedef pair<ll, ll> Vec;
typedef __int128 LL;

LL dot(const Vec &a, const Vec &b) { return a.fir * (LL) b.fir + a.sec * (LL) b.sec; }

LL cross(const Vec &a, const Vec &b) { return a.fir * (LL) b.sec - a.sec * (LL) b.fir; }

struct State {
  int tag;
  Vec axis, u, d;

  void ins(const Vec &vec) {
    if (tag == 0) {
      tag = 1;
      axis = u = d = vec;
    } else if (tag == 1) {
      //cerr << axis.x << ' ' << axis.y << ", " << u.x << ' ' << u.y << ", " << d.x << ' ' << d.y << " ins " << vec.x << ' ' << vec.y << '\n';
      LL delta = cross(axis, vec);
      if (delta > 0 && cross(u, vec) > 0) u = vec;
      if (delta < 0 && cross(d, vec) < 0) d = vec;
      if (cross(u, d) > 0)
        tag = 2;
    }
  }
};

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  int n;
  cin >> n;
  vector<pair<int, int>> tim;
  vector<pair<ll, ll>> vec;

  ll u1 = a, v1 = b, w1 = c, u2, v2, w2;
  if (a || b) {
    swap(u1, v1);
    v1 *= -1;
    w1 = 0;
  } else {
    swap(u1, w1);
    w1 *= -1;
    v1 = 0;
  }
  u2 = b * w1 - c * v1;
  v2 = c * u1 - a * w1;
  w2 = a * v1 - b * u1;
  //cerr << u2 << ' ' << v2 << ' ' << w2 << '\n';
  //cerr << (u2 * a + v2 * b + w2 * c) << ' ' << (u2 * u1 + v2 * v1 + w2 * w1) << '\n';


  for (int i = 0; i < n; ++i) {
    cin.ignore();
    char opt;
    cin >> opt;
    if (opt == 'R') {
      int x;
      cin >> x;
      --x;
      tim[x].sec = i - 1;
    } else {
      int x, y, z;
      cin >> x >> y >> z;
      tim.emplace_back(i, n - 1);
      vec.emplace_back(x * u1 + y * v1 + z * w1, x * u2 + y * v2 + z * w2);
    }
  }
  vector<int> ans(n);
  function<void(int, int, const vector<pair<int, int>> &, const vector<pair<ll, ll>> &, State)> dc = [&](int l, int r,
                                                                                                         const vector<pair<int, int>> &tm,
                                                                                                         const vector<Vec> &vc,
                                                                                                         State state) {
    //cerr << "dc " << l << ' ' << r << ' ' << tm.size() << ' ' << vc.size() << '\n';
    vector<pair<int, int>> tl, tr;
    vector<Vec> vl, vr;
    int mid = (l + r) >> 1;
    for (int i = 0; i < tm.size(); ++i) {
      if (tm[i].fir == l && tm[i].sec == r)
        state.ins(vc[i]);
      else if (tm[i].sec <= mid) {
        tl.push_back(tm[i]);
        vl.push_back(vc[i]);
      } else if (tm[i].fir > mid) {
        tr.push_back(tm[i]);
        vr.push_back(vc[i]);
      } else {
        tl.emplace_back(tm[i].fir, mid);
        vl.push_back(vc[i]);
        tr.emplace_back(mid + 1, tm[i].sec);
        vr.push_back(vc[i]);
      }
    }
    if (l == r) {
      if (state.tag == 2)
        ans[l] = 3;
    } else {
      dc(l, mid, tl, vl, state);
      dc(mid + 1, r, tr, vr, state);
    }
  };
  State state = State();
  dc(0, n - 1, tim, vec, state);
  vector<int> sum(n + 1);
  for (int i = 0; i < vec.size(); ++i) {
    ll g = gcd(vec[i].fir, vec[i].sec);
    if (g < 0) g = -g;
    if (g > 0) {
      vec[i].fir /= g;
      vec[i].sec /= g;
    } else {
      ++sum[tim[i].fir];
      --sum[tim[i].sec + 1];
    }
  }
  auto reg = [&](Vec vec) {
    if (vec.fir < 0) {
      vec.fir = -vec.fir;
      vec.sec = -vec.sec;
    } else if (vec.fir == 0 && vec.sec < 0) {
      vec.sec = -vec.sec;
    }
    return vec;
  };
  auto id = [&](const Vec &vec) {
    static map<Vec, int> mp;
    static int cnt = 0;
    auto it = mp.find(vec);
    if (it != mp.end()) return it->second;
    mp.insert(make_pair(vec, cnt++));
    return cnt - 1;
  };
  vector<int> gi(n), sgn(n);
  for (int i = 0; i < vec.size(); ++i) {
    gi[i] = id(reg(vec[i]));
    sgn[i] = reg(vec[i]) == vec[i];
  }
  vector<vector<int>> ins(n + 1), del(n + 1);
  for (int i = 0; i < vec.size(); ++i) {
    ins[tim[i].fir].push_back(gi[i] * 2 + sgn[i]);
    del[tim[i].sec + 1].push_back(gi[i] * 2 + sgn[i]);
  }
  vector<int> cnt(n * 2);
  int pairs = 0;
  for (int i = 0; i < n; ++i) {
    for (int j : ins[i]) {
      if (cnt[j]++ == 0 && cnt[j ^ 1])
        ++pairs;
    }
    for (int j : del[i]) {
      if (--cnt[j] == 0 && cnt[j ^ 1])
        --pairs;
    }
    if (pairs)
      ans[i] = 2;
  }
  for (int i = 1; i < n; ++i) sum[i] += sum[i - 1];
  for (int i = 0; i < n; ++i)
    if (sum[i])
      ans[i] = 1;
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}