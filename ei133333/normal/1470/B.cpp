#include<bits/stdc++.h>

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


/**
 * @brief Union-Find
 * @docs docs/union-find.md
 */
struct UnionFind {
  vector< int > data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) {
    return -data[find(k)];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};


const int MAX_A = 1000000;

int main() {

  vector< vector< int > > odd(MAX_A + 1);
  vector< int > prime(MAX_A + 1);
  for(int i = 2; i <= MAX_A; i++) {
    if(!prime[i]) {
      for(int j = i; j <= MAX_A; j += i) {
        prime[j] = true;
      }
      for(int j = i; j <= MAX_A; j += i) {

        int flag = 0, cur = j;
        while(cur % i == 0) {
          cur /= i;
          flag ^= 1;
        }

        if(flag) {
          odd[j].emplace_back(i);
        }
      }
    }
  }
  UnionFind uf(MAX_A + 1);
  map< vector< int >, int > group;
  for(int i = 1; i <= MAX_A; i++) {
    auto it = group.find(odd[i]);
    if(it == end(group)) {
      group[odd[i]] = i;
    } else {
      uf.unite(i, it->second);
    }
  }

  int base = uf.find(1);

  vector< int > exist(MAX_A + 1);

  int T;
  cin >> T;
  while(T--) {
    int N, Q;
    cin >> N;
    vector< int > A(N);
    cin >> A;

    for(auto &a : A) {
      a = uf.find(a);
      exist[a]++;
    }

    int uku = exist[base];
    exist[base] = 0;

    int first_step = uku;
    int second_step = 0, beet = 0;
    for(auto &a : A) {
      if(exist[a]) {
        chmax(first_step, exist[a]);
        if(exist[a] & 1) {
          chmax(second_step, exist[a]);
        } else {
          beet += exist[a];
        }
        exist[a] = 0;
      }
    }
    chmax(second_step, uku + beet);

    cin >> Q;
    while(Q--) {
      int64 w;
      cin >> w;
      if(w == 0) {
        cout << first_step << "\n";
      } else {
        cout << second_step << "\n";
      }
    }
  }
}