#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
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
  for(T &in : v) is >> in;
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
  for(auto &e : t) fill_v(e, v);
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

struct MergingSegmentTree {
  static const int LG = 18;
  static const int SEG = 1 << LG;
  static const int OP = SEG;
  static const int SZ = OP * LG + 1;

  int tail;
  vector< int64 > chl, chr, sz, sum, opt;

  MergingSegmentTree() : tail(1), chl(SZ), chr(SZ), sz(SZ), sum(SZ), opt(SZ) {}

  int build(int val, int l = 0, int r = SEG) {
    int k = tail++;
    sz[k] = 1;
    sum[k] = val;
    opt[k] = 0;
    if(l + 1 == r)return k;
    int m = (l + r) >> 1;
    if(val < m)chl[k] = build(val, l, m);
    else chr[k] = build(val, m, r);
    return k;
  }

  int merge(int t1, int t2, int l = 0, int r = SEG) {
    if(t1 && t2); else return t1 ^ t2;
    sum[t1] += sum[t2];
    sz[t1] += sz[t2];
    if(l + 1 == r) {
      opt[t1] = sz[t1] * (sz[t1] - 1) / 2 * l;
      return t1;
    }
    int m = (l + r) >> 1;

    chl[t1] = merge(chl[t1], chl[t2], l, m);
    chr[t1] = merge(chr[t1], chr[t2], m, r);
    opt[t1] = opt[chl[t1]] + sz[chr[t1]] * sum[chl[t1]] + opt[chr[t1]];
    return t1;
  }
};

int main() {
  map< int, int > mp;
  MergingSegmentTree seg;
  int N;
  cin >> N;
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    int k = seg.build(b);

    auto it = mp.lower_bound(a + 1);
    if(it != begin(mp)) {
      --it;
      if(it->first + seg.sz[it->second] >= a) {
        ret -= 1LL * b * (a - it->first);
        ret -= seg.opt[it->second];
        seg.merge(it->second, k);
        tie(a, k) = *it;
        ret += seg.opt[k];
      } else {
        mp[a] = k;
      }
    } else {
      mp[a] = k;
    }

    it = mp.lower_bound(a + 1);

    while(it != end(mp)) {
      if(a + seg.sz[k] >= it->first) {
        ret -= seg.sum[it->second] * (it->first - a);
        ret -= seg.opt[k];
        ret -= seg.opt[it->second];
        seg.merge(k, it->second);
        ret += seg.opt[k];
        it = mp.erase(it);
      } else {
        break;
      }
    }
    cout << ret << "\n";
  }
}