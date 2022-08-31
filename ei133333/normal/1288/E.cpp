#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

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

template< class T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k < data.size(); k += k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k > 0; k -= k & -k) data[k] += x;
  }
};

vector< int > get_latte(int N, const vector< int > &A) {
  int M = (int) A.size();
  vector< vector< int > > upd(N);
  for(int i = 0; i < N; i++) upd[i].emplace_back(-1);
  for(int i = 0; i < M; i++) upd[A[i]].emplace_back(i);
  for(int i = 0; i < N; i++) upd[i].emplace_back(M);

  vector< vector< int > > op(M + 1);
  vector< vector< pair< int, int > > > op2(M + 1);

  for(int i = 0; i < N; i++) {
    for(int j = 1; j < upd[i].size(); j++) {
      int l = upd[i][j - 1] + 1;
      int r = upd[i][j];
      if(l == r) continue;

      if(l == 0) {
        op[r].emplace_back(i);
      } else {
        // [l,r)
        op2[r].emplace_back(l, i);
      }
    }
  }

  vector< int > ans(N);
  for(int i = 0; i < N; i++) ans[i] = i;

  {
    BinaryIndexedTree< int > bit(N);
    vector< int > used(N);
    for(int i = 0; i <= M; i++) {
      for(auto &p : op[i]) {
        chmax(ans[p], p + bit.sum(p));
      }
      if(i < M) {
        if(!used[A[i]]) {
          used[A[i]] = true;
          bit.add(A[i], 1);
        }
      }
    }
  }

  {
    vector< int > pre(N, -1);
    BinaryIndexedTree< int > bit(M + 1);
    for(int i = 0; i <= M; i++) {
      for(auto &p : op2[i]) {
        chmax(ans[p.second], bit.sum(p.first));
      }
      if(i < M) {
        if(~pre[A[i]]) bit.add(pre[A[i]], -1);
        pre[A[i]] = i;
        bit.add(i, 1);
      }
    }
  }

  return ans;
}

vector< int > get_malta(int N, const vector< int > &A) {
  vector< int > malta(N, -1);
  for(int i = 0; i < N; i++) malta[i] = i;
  for(auto &a : A) malta[a] = 0;
  return malta;
}


int main() {
  int N, M;
  cin >> N >> M;
  vector< int > A(M);
  cin >> A;
  for(auto &p : A) --p;
  auto latte = get_latte(N, A);
  auto malta = get_malta(N, A);
  for(int i = 0; i < N; i++) {
    cout << malta[i] + 1 << " " << latte[i] + 1 << "\n";
  }
}