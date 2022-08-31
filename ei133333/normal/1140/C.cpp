#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

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

template< typename T >
struct PrioritySumStructure {
  static const bool INCREASE = false;
  static const bool DECREASE = true;

  bool order;
  int k, sz;
  T sum;
  set< pair< T, int > > add, pend;
  map< int, T > adding, pending;

  PrioritySumStructure(int k, bool order = INCREASE) : k(k), sum(0), sz(0), order(order) {}

  void Sweep() {
    while(sz < k && !pend.empty()) {
      auto p = order ? --pend.end() : pend.begin();
      sum += p->first;
      ++sz;
      add.emplace(*p);
      adding.emplace(p->second, p->first);
      pending.erase(p->second);
      pend.erase(p);
    }
    while(sz > k) {
      auto p = order ? add.begin() : --add.end();
      sum -= p->first;
      --sz;
      pend.emplace(*p);
      pending.emplace(p->second, p->first);
      adding.erase(p->second);
      add.erase(p);
    }
  }

  T getSum() {
    if(sz < k) throw ("get Sum Exception");
    return (sum);
  }

  void addElement(int k, T x) {
    if(adding.count(k) || pending.count(k)) {
      throw ("Add Element Exception");
    }
    ++sz;
    add.emplace(x, k);
    adding[k] = x;
    sum += x;
    Sweep();
  }

  void deleteElement(int k) {
    if(pending.count(k)) {
      pend.erase({pending[k], k});
      pending.erase(k);
    } else if(adding.count(k)) {
      --sz;
      sum -= adding[k];
      add.erase({adding[k], k});
      adding.erase(k);
      Sweep();
    } else {
      throw ("delete Element Exception");
    }
  }

  void incrementSize() {
    ++k;
    Sweep();
  }

  void decrementSize() {
    if(k == 0) throw ("decrement Size Exception");
    --k;
    Sweep();
  }
};


int main() {
  int N, K;
  cin >> N >> K;
  vector< pair< int, int > > X;
  for(int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    X.emplace_back(b, a);
  }
  sort(X.rbegin(), X.rend());
  int64 ret = 0;
  PrioritySumStructure< int64 > que(K, true);
  int t = 0;
  for(auto &p : X) {
    que.addElement(t++, p.second);
    ret = max(ret, que.sum * p.first);
  }
  cout << ret << endl;
}