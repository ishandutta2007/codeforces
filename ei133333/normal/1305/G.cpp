#include <bits/stdc++.h>

using namespace std;


using int64 = long long;
const int mod = 1000003;

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

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

template< typename T, typename F >
T boruvka(int N, F f) {
  vector< int > rev(N), belong(N);
  UnionFind uf(N);
  T ret = T();
  while(uf.size(0) != N) {
    int ptr = 0;
    for(int i = 0; i < N; i++) {
      if(uf.find(i) == i) {
        belong[i] = ptr++;
        rev[belong[i]] = i;
      }
    }
    for(int i = 0; i < N; i++) {
      belong[i] = belong[uf.find(i)];
    }
    auto v = f(ptr, belong);
    bool update = false;
    for(int i = 0; i < ptr; i++) {
      if(~v[i].second && uf.unite(rev[i], rev[v[i].second])) {
        ret += v[i].first;
        update = true;
      }
    }
    if(!update) break;//return -1; // notice!!
  }
  return ret;
}


int main() {
  int N;
  cin >> N;
  vector< int > A(N);

  cin >> A;
  A.emplace_back(0);
  ++N;
  sort(A.begin(), A.end());

  int64 ret = 0;
  for(auto &t : A) ret += t;


  const int INF = 1 << 30;
  const int mask = (1 << 18) - 1;


  using pi = pair< int, int >;
  using pii = pair< pi, pi >;
  auto f1 = [](pii a, const pii &b) {
    for(auto p : {b.first, b.second}) {
      if(a.first.second == p.second) {
        a.first.first = max(a.first.first, p.first);
      } else if(a.second.second == p.second) {
        a.second.first = max(a.second.first, p.first);
        if(a.first < a.second) swap(a.first, a.second);
      } else {
        if(p > a.first) {
          a.second = a.first;
          a.first = p;
        } else if(p > a.second) {
          a.second = p;
        }
      }
    }
    return a;
  };

  auto f = [&](int sz, vector< int > belong) {
    vector< pii > dp(1 << 18, pii(pi(-inf, -1), pi(-inf, -1)));
    vector< pair< int, int > > ret(sz, {-inf, -1});
    for(int i = 0; i < N; i++) {
      dp[A[i]] = f1(dp[A[i]], pii(pi(A[i], belong[i]), pi(-inf, -1)));
    }
    for(int i = 0; i <= mask; i++) {
      for(int j = 17; j >= 0; j--) {
        if((~i >> j) & 1) dp[i ^ (1 << j)] = f1(dp[i ^ (1 << j)], dp[i]);
      }
    }
    for(int i = 0; i < N; i++) {
      if(belong[i] != dp[A[i] ^ mask].first.second) chmax(ret[belong[i]], pi(dp[A[i] ^ mask].first.first + A[i], dp[A[i] ^ mask].first.second));
      if(belong[i] != dp[A[i] ^ mask].second.second) chmax(ret[belong[i]], pi(dp[A[i] ^ mask].second.first + A[i], dp[A[i] ^ mask].second.second));
    }
    return ret;
  };
  cout << boruvka< int64 >(N, f) - ret << endl;
}