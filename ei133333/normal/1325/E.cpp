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


template< typename T >
struct edge {
  int to, id;

  edge(int to, T id) : to(to), id(id) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;


int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;


  vector< int > d(1000001, -1);
  vector< int > prime, rev(1000001);
  for(int i = 2; i < d.size(); i++) {
    if(d[i] != -1) continue;
    rev[i] = (int) prime.size();
    prime.emplace_back(i);
    for(int j = i; j < d.size(); j += i) d[j] = i;
  }
  prime.emplace_back(-1);


  WeightedGraph< int > g(prime.size());
  vector< int > deg(prime.size());
  for(int i = 0; i < N; i++) {
    int now = A[i];
    if(now == 1) {
      cout << 1 << endl;
      return 0;
    } else {
      map< int, int > mp;
      while(now > 1) {
        mp[d[now]]++;
        now /= d[now];
      }
      vector< int > tap;
      for(auto &p : mp) {
        if(p.second % 2 == 1) {
          tap.emplace_back(p.first);
        }
      }
      if(tap.empty()) {
        cout << 1 << endl;
        return 0;
      } else if(tap.size() == 1) {
        deg[rev[tap[0]]]++;
      } else if(tap.size() == 2) {
        g[rev[tap[0]]].emplace_back(rev[tap[1]], i);
        g[rev[tap[1]]].emplace_back(rev[tap[0]], i);
      }
    }
  }

  if(set< int >(begin(A), end(A)).size() < N) {
    cout << 2 << endl;
    return 0;
  }
  for(int i = 0; i < deg.size(); i++) {
    if(deg[i] >= 2) {
      cout << 2 << endl;
      return 0;
    }
  }

  for(int i = 0; i + 1 < deg.size(); i++) {
    if(deg[i] % 2 == 1) {
      g[i].emplace_back(deg.size() - 1, N + i);
      g[deg.size() - 1].emplace_back(i, N + i);
    }
  }

  N = deg.size();

  vector< int > ord(deg.size());
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int a, int b) {
    return g[a].size() > g[b].size();
  });
  vector< int > rev2(N);
  for(int i = 0; i < N; i++) {
    rev2[ord[i]] = i;
  }
  for(int i = 0; i < N; i++) {
    sort(begin(g[i]), end(g[i]), [&](auto p, auto q) {
      return rev2[p.to] > rev2[q.to];
    });
  }


  int ret = inf;
  for(int i : ord) {
    if(i > 1000 && i + 1 != deg.size() + 1) continue;
    vector< int > d1(prime.size(), inf), i1(prime.size(), -1);
    vector< int > d2(prime.size(), inf), i2(prime.size(), -1);
    using pi = pair< int, int >;
    queue< pair< int, pair< int, int > > > que;
    for(auto &t : g[i]) {
      if(chmin(d1[t], 1)) i1[t.to] = t.id;
      else if(chmin(d2[t.to], 1)) i2[t.to] = t.id;
    }
    for(int j = 0; j < N; j++) {
      if(~i1[j]) que.emplace(d1[j], make_pair(j, i1[j]));
      if(~i2[j]) que.emplace(d2[j], make_pair(j, i2[j]));
    }
    while(!que.empty()) {
      auto pp = que.front();
      que.pop();
      auto cost = pp.first;
      auto st = pp.second;
      if(cost >= ret) break;
      if(i1[st.first] == st.second) {
        if(cost != d1[st.first]) continue;
      } else if(i2[st.first] == st.second) {
        if(cost != d2[st.first]) continue;
      } else {
        continue;
      }
      for(auto &e : g[st.first]) {
        if(e.to == i) continue;
        auto nxt_cost = 1 + cost;
        if(nxt_cost >= ret) continue;
        if(nxt_cost < d1[e.to]) {
          if(i1[e.to] != st.second) {
            swap(d2[e.to], d1[e.to]);
            swap(i2[e.to], i1[e.to]);
          }
          d1[e.to] = nxt_cost;
          i1[e.to] = st.second;
          que.emplace(d1[e.to], make_pair(e.to, st.second));
        } else if(nxt_cost < d2[e.to]) {
          if(i1[e.to] != st.second) {
            d2[e.to] = nxt_cost;
            i2[e.to] = st.second;
            que.emplace(d2[e.to], make_pair(e.to, st.second));
          }
        }

      }
    }

    for(auto &e : g[i]) {
      if(i1[e.to] == e.id) chmin(ret, d2[e.to] + 1);
      else chmin(ret, d1[e.to] + 1);
    }
    for(int j = 0; j < N; j++) {
      while(g[j].size() && g[j].back() == i) g[j].pop_back();
    }
    g[i].clear();
  }

  if(ret >= inf) cout << -1 << endl;
  else cout << ret << endl;
}