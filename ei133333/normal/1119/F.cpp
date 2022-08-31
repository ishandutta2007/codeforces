#include<bits/stdc++.h>

using namespace std;using int64 = long long;
const int mod = 1e9 + 7;

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

template< typename T, typename Compare = less< T >, typename RCompare = greater< T > >
struct PrioritySumStructure {

  size_t k;
  T sum;

  priority_queue< T, vector< T >, Compare > in, d_in;
  priority_queue< T, vector< T >, RCompare > out, d_out;

  PrioritySumStructure(int k) : k(k), sum(0) {}

  void modify() {
    while(in.size() - d_in.size() < k && !out.empty()) {
      auto p = out.top();
      out.pop();
      if(!d_out.empty() && p == d_out.top()) {
        d_out.pop();
      } else {
        sum += p;
        in.emplace(p);
      }
    }
    while(in.size() - d_in.size() > k) {
      auto p = in.top();
      in.pop();
      if(!d_in.empty() && p == d_in.top()) {
        d_in.pop();
      } else {
        sum -= p;
        out.emplace(p);
      }
    }
    while(!d_in.empty() && in.top() == d_in.top()) {
      in.pop();
      d_in.pop();
    }
  }

  T query() const {
    return sum;
  }

  void insert(T x) {
    in.emplace(x);
    sum += x;
    modify();
  }

  void erase(T x) {
    assert(size());
    if(!in.empty() && in.top() == x) {
      sum -= x;
      in.pop();
    } else if(!in.empty() && RCompare()(in.top(), x)) {
      sum -= x;
      d_in.emplace(x);
    } else {
      d_out.emplace(x);
    }
    modify();
  }

  void set_k(size_t kk) {
    k = kk;
    modify();
  }

  size_t get_k() const {
    return k;
  }

  size_t size() const {
    return in.size() + out.size() - d_in.size() - d_out.size();
  }
};

template< typename T >
using MaximumSum=PrioritySumStructure< T, greater< T >, less< T > >;

template< typename T >
using MinimumSum=PrioritySumStructure< T, less< T >, greater< T > >;


template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

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

int N, D;
WeightedGraph< int > g;
bool alive[250000];
vector< MinimumSum < int64 > > pri;

pair< int64, int64 > dfs(int idx, int par) {
  alive[idx] = false;
  int64 all = 0;
  vector< int64 > val, val2;
  for(auto &to : g[idx]) {
    if(to == par) {
      continue;
    } else if(alive[to]) {
      auto ret = dfs(to, idx);
      auto cost = min(ret.first, ret.second + to.cost);
      all += cost;
      val.emplace_back(ret.second + to.cost - cost);
    } else {
      break;
    }
  }

  sort(begin(val), end(val));

  int64 res[2] = {infll, infll};
  int deg = g[idx].size();
  if(~par) --deg;

  for(int i = 0; i < 2; i++) {
    int over = deg - D + 1 - i;
    int64 presum = 0;
    for(int j = 0; j <= min(over, (int) val.size()); j++) {
      int rest = over - j;
      if(rest <= pri[idx].size()) {
        pri[idx].set_k(rest);
        chmin(res[i], presum + all + pri[idx].query());
      }
      if(j < val.size()) presum += val[j];
    }
  }
  return {res[0], res[1]};
}


int main() {
  cin >> N;
  g.resize(N);
  for(int i = 1; i < N; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y;
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
  }
  for(int i = 0; i < N; i++) {
    sort(g[i].begin(), g[i].end(), [&](auto p, auto q) {
      return g[p].size() > g[q].size();
    });
  }
  vector< int > uku[250000], kill[250001];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < g[i].size(); j++) uku[j].emplace_back(i);
    kill[g[i].size()].emplace_back(i);
  }
  for(int i = 0; i < N; i++) {
    pri.emplace_back(MinimumSum< int64 >(0));
  }

  for(int i = 0; i < N; i++) {
    for(auto &p : kill[i]) {
      for(auto &to : g[p]) pri[to].insert(to.cost);
    }
    for(auto &p : uku[i]) {
      alive[p] = true;
    }
    D = i;
    int64 all = 0;
    for(auto &p : uku[i]) {
      if(alive[p]) all += dfs(p, -1).second;
    }
    cout << all << " ";
  }
  cout << endl;
}