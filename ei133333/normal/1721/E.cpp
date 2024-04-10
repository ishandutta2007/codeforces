#include<bits/stdc++.h>

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
  for (int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for (T &in: v) is >> in;
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
  for (auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint: F {
  explicit FixPoint(F &&f): F(forward< F >(f)) {}

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
 * @brief Z Algorithm
 * @see https://heno239.hatenablog.com/entry/2020/07/07/140651
 * @docs docs/z-algorithm.md
 */
template < typename T = char >
struct ZAlgorithm {
private:
  vector< T > s;
  vector< int > deleted;
  vector< vector< int > > delete_hist;
  vector< int > z;
  queue< int > cur;

public:
  ZAlgorithm(): delete_hist{{}} {}

  template < typename S >
  ZAlgorithm(const S &s): ZAlgorithm() {
    for (auto &c: s) add(c);
  }

  void add(const T &c) {
    s.emplace_back(c);
    delete_hist.emplace_back();
    deleted.emplace_back(0);
    z.emplace_back(0);
    z[0]++;

    int len = (int)s.size();
    if (len == 1) return;
    if (s[0] == c)
      cur.emplace(len - 1);
    else
      deleted[len - 1] = 1;

    auto set = [&](int t, int len) {
      deleted[t] = 1;
      delete_hist[len].emplace_back(t);
      z[t] = len - t - 1;
    };

    while (not cur.empty()) {
      int t = cur.front();
      if (deleted[t]) {
        cur.pop();
      } else if (s[len - t - 1] == s.back()) {
        break;
      } else {
        set(t, len);
        cur.pop();
      }
    }

    if (not cur.empty()) {
      int t = cur.front();
      for (auto &p: delete_hist[len - t]) {
        set(p + t, len);
      }
    }
  }

  int get(int k) const {
    return deleted[k] ? z[k] : (int)s.size() - k;
  }

  int operator[](int k) const {
    return get(k);
  }

  vector< int > get() {
    vector< int > ret(s.size());
    for (int i = 0; i < (int)s.size(); i++) {
      ret[i] = get(i);
    }
    return ret;
  }
};


int main() {
  string S;
  cin >> S;
  int N = (int) S.size();
  int Q;
  cin >> Q;
  ZAlgorithm z(S);
  map< string, int > mp;
  for(int i = 1; i < N; i++) {
    if(z[i] == N - i) {
      string t;
      for(int j = 0, k = 0; j < 10; j++) {
        if(z[i] + j < N) {
          t += S[z[i] + j];
          chmax(mp[t], z[i] + j + 1);
        } else {
          t += t[k++];
          chmax(mp[t], z[i] + j + 1);
        }
      }
    }
  }


  string t;
  map< string, int > mp2;
  for(int j = 0, k = 0; j < 10; j++) {
    if(j < N) {
      t += S[j];
      chmax(mp2[t], j + 1);
    } else {
      t += t[k++];
      chmax(mp2[t], j + 1);
    }
  }

  while(Q--) {
    string x;
    cin >> x;
    int M = (int) x.size();
    vector< int > ans(M);
    {
      string y;
      for (int j = 0; j < M; j++) {
        y += x[j];
        auto f = mp.find(y);
        if (f != mp.end()) {
          chmax(ans[j], f->second);
        }
      }
    }

    for (int i = 0; i < M; i++) {
      string y;
      for (int j = i; j < M; j++) {
        y += x[j];
        auto f = mp2.find(y);
        if (f != mp2.end()) {
          chmax(ans[j], f->second);
        }
      }
    }

    cout << ans << endl;
  }
}