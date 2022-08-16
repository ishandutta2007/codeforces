#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in: v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

void beet() {
  int N;
  cin >> N;
  vector< int > T(N), L(N), R(N);
  vector< int > xs;
  for(int i = 0; i < N; i++) {
    cin >> T[i] >> L[i] >> R[i];
    xs.emplace_back(L[i]);
    xs.emplace_back(L[i] - 1);
    xs.emplace_back(R[i]);
    xs.emplace_back(R[i] + 1);
  }
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  int sz = 1;
  while(sz < (int) xs.size()) sz *= 2;
  vector< vector< vector< int > > > seg(2, vector< vector< int > >(2 * sz));
  for(int i = 0; i < N; i++) {
    L[i] = lower_bound(begin(xs), end(xs), L[i]) - begin(xs);
    R[i] = lower_bound(begin(xs), end(xs), R[i]) - begin(xs);
    int l = L[i];
    int r = R[i] + 1;
    int t = T[i];
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if(l & 1) seg[t][l++].emplace_back(i);
      if(r & 1) seg[t][--r].emplace_back(i);
    }
  }
  vector< int > used(N);
  auto seg_used = make_v< int >(2, 2, 2 * sz);
  int ret = 0;
  for(int i = 0; i < N; i++) {
    if(used[i]) continue;
    ++ret;
    queue< int > que;
    que.emplace(i);
    used[i] = 1;
    queue< tuple< int, int > > seg_que[2];
    auto modify = [&](int t, int k) {
      for(auto &p: seg[t][k]) {
        if(!used[p]++) que.emplace(p);
      }
      seg[t][k].clear();
    };
    while(not que.empty() or not seg_que[0].empty() or not seg_que[1].empty()) {
      if(not que.empty()) {
        int j = que.front();
        que.pop();
        int l = L[j];
        int r = R[j] + 1;
        int t = 1 - T[j];
        for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
          if(l & 1) {
            if(!seg_used[0][t][l]++) seg_que[0].emplace(t, l);
            if(!seg_used[1][t][l]++) seg_que[1].emplace(t, l);
            l++;
          }
          if(r & 1) {
            --r;
            if(!seg_used[0][t][r]++) seg_que[0].emplace(t, r);
            if(!seg_used[1][t][r]++) seg_que[1].emplace(t, r);
          }
        }
      } else if(not seg_que[0].empty()) {
        auto[t, k] = seg_que[0].front();
        seg_que[0].pop();
        modify(t, k);
        if(k > 1 and !seg_used[0][t][k / 2]++) seg_que[0].emplace(t, k / 2);
      } else {
        auto[t, k] = seg_que[1].front();
        seg_que[1].pop();
        modify(t, k);
        if(k * 2 + 0 < 2 * sz and !seg_used[1][t][k * 2 + 0]++) seg_que[1].emplace(t, k * 2 + 0);
        if(k * 2 + 1 < 2 * sz and !seg_used[1][t][k * 2 + 1]++) seg_que[1].emplace(t, k * 2 + 1);
      }
    }
  }
  cout << ret << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) beet();
}