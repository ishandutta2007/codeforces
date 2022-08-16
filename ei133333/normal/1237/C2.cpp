#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;


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

int main() {
  int N;
  cin >> N;
  auto A = make_v< int >(N, 3);
  cin >> A;

  vector< int > used(N);


  for(int i = 0; i < 3; i++) {
    for(int v = i + 1; v < 3; v++) {
      map< pair< int, int >, vector< int > > mx;
      for(int j = 0; j < N; j++) {
        if(used[j]) continue;
        mx[{A[j][i], A[j][v]}].emplace_back(j);
      }
      for(auto &p : mx) {
        auto vs = p.second;
        if(vs.size() >= 2) {
          vector< int > uku;
          for(int j = 0; j < 3; j++) {
            if(i == j) continue;
            if(v == j) continue;
            sort(begin(vs), end(vs), [&](int a, int b) {
              vector< int > as, bs;
              for(int k = 0; k < 3; k++) {
                if(i == k) continue;
                if(i == v) continue;
                as.emplace_back(A[a][k]);
                bs.emplace_back(A[b][k]);
              }
              return as < bs;
            });
            break;
          }
          for(int k = 0; k + 1 < vs.size(); k += 2) {
            cout << vs[k] + 1 << " " << vs[k + 1] + 1 << endl;
            used[vs[k]] = true;
            used[vs[k + 1]] = true;
          }
        }
      }
    }

  }

  for(int i = 0; i < 3; i++) {
    map< int, vector< int > > mx;
    for(int j = 0; j < N; j++) {
      if(used[j]) continue;
      mx[A[j][i]].emplace_back(j);
    }
    for(auto &p : mx) {
      auto vs = p.second;
      if(vs.size() >= 2) {
        vector< int > uku;
        for(int j = 0; j < 3; j++) {
          if(i == j) continue;
          for(auto &k : vs) uku.emplace_back(A[k][j]);
          sort(begin(uku), end(uku));
          uku.erase(unique(begin(uku), end(uku)), end(uku));
          sort(begin(vs), end(vs), [&](int a, int b) {
            vector< int > as, bs;
            int mula = 1, mulb = 1;
            for(int k = 0; k < 3; k++) {
              if(i == k) continue;
              as.emplace_back(A[a][k] * mula);
              bs.emplace_back(A[b][k] * mulb);
              if(j == k) {
                auto x = lower_bound(begin(uku), end(uku), A[a][k]) - begin(uku);
                if(x % 2) mula *= -1;
                auto y = lower_bound(begin(uku), end(uku), A[b][k]) - begin(uku);
                if(y % 2) mulb *= -1;
              }
            }
            return as < bs;
          });

          break;
        }
        for(int k = 0; k + 1 < vs.size(); k += 2) {
          cout << vs[k] + 1 << " " << vs[k + 1] + 1 << endl;
          used[vs[k]] = true;
          used[vs[k + 1]] = true;
        }
      }
    }
  }

  vector< int > ord;
  for(int i = 0; i < N; i++) {
    if(used[i]) continue;
    ord.emplace_back(i);
  }
  sort(begin(ord), end(ord), [&](int a, int b) {
    return A[a] < A[b];
  });
  for(int i = 0; i + 1 < ord.size(); i += 2) {
    cout << ord[i] + 1 << " " << ord[i + 1] + 1 << endl;
  }
}