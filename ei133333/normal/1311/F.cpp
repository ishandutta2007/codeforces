#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;


using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 58) - 1;
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

template< class T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int main() {
  int N;
  cin >> N;
  vector< int > X(N);
  cin >> X;


  vector< int > pos, neg, zero;
  vector< int > D(N);
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    D[i] = x;
    if(x > 0) pos.emplace_back(i);
    else if(x < 0) neg.emplace_back(i);
    else zero.emplace_back(i);
  }


  int64 ret = 0;

  // pos-pos
  {
    vector< int > xs;
    for(int i : pos) xs.emplace_back(D[i]);
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));

    vector< int > ord{pos};
    sort(begin(ord), end(ord), [&](int a, int b) {
      return X[a] < X[b];
    });
    BinaryIndexedTree< int64 > bit1(xs.size()), bit2(xs.size());
    for(int i : ord) {
      int po = lower_bound(begin(xs), end(xs), D[i]) - begin(xs);
      ret += bit1.sum(po) * X[i];
      ret -= bit2.sum(po);
      bit1.add(po, 1);
      bit2.add(po, X[i]);
    }
  }


  // neg-neg
  {
    vector< int > xs;
    for(int i : neg) xs.emplace_back(-D[i]);
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));

    vector< int > ord{neg};
    sort(begin(ord), end(ord), [&](int a, int b) {
      return X[a] > X[b];
    });
    BinaryIndexedTree< int64 > bit1(xs.size()), bit2(xs.size());
    for(int i : ord) {
      int po = lower_bound(begin(xs), end(xs), -D[i]) - begin(xs);
      ret -= bit1.sum(po) * X[i];
      ret += bit2.sum(po);
      bit1.add(po, 1);
      bit2.add(po, X[i]);
    }
  }

  // pos-neg
  {
    vector< int > ord(N);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) {
      return X[a] < X[b];
    });
    int64 a = 0, b = 0;
    for(int i : ord) {
      if(D[i] < 0) {
        a += 1;
        b += X[i];
      } else if(D[i] > 0) {
        ret += a * X[i];
        ret -= b;
      }
    }
  }

  // neg-zero
  {
    vector< int > ord{neg};
    for(auto p : zero) ord.emplace_back(p);
    sort(begin(ord), end(ord), [&](int a, int b) {
      return X[a] < X[b];
    });
    int64 a = 0, b = 0;
    for(int i : ord) {
      if(D[i] == 0) {
        ret += a * X[i];
        ret -= b;
      } else {
        a += 1;
        b += X[i];
      }
    }
  }

  // pos-zero
  {
    vector< int > ord{pos};
    for(auto p : zero) ord.emplace_back(p);
    sort(begin(ord), end(ord), [&](int a, int b) {
      return X[a] > X[b];
    });
    int64 a = 0, b = 0;
    for(int i : ord) {
      if(D[i] == 0) {
        ret -= a * X[i];
        ret += b;
      } else {
        a += 1;
        b += X[i];
      }
    }
  }

  // zero-zero
  {
    vector< int > ord{zero};
    sort(begin(ord), end(ord), [&](int a, int b) {
      return X[a] < X[b];
    });
    int64 a = 0, b = 0;
    for(int i : ord) {
      ret += a * X[i];
      ret -= b;
      a += 1;
      b += X[i];
    }
  }
  cout << ret << endl;
}