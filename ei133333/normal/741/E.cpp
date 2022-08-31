#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 104857601;


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

struct SuffixArray {
  vector< int > SA;
  const string s;

  SuffixArray(const string &str) : s(str) {
    SA.resize(s.size());
    iota(begin(SA), end(SA), 0);
    sort(begin(SA), end(SA), [&](int a, int b) {
      return s[a] == s[b] ? a > b : s[a] < s[b];
    });
    vector< int > classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
    for(int len = 1; len < s.size(); len <<= 1) {
      for(int i = 0; i < s.size(); i++) {
        if(i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size() && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {
          classes[SA[i]] = classes[SA[i - 1]];
        } else {
          classes[SA[i]] = i;
        }
      }
      iota(begin(cnt), end(cnt), 0);
      copy(begin(SA), end(SA), begin(c));
      for(int i = 0; i < s.size(); i++) {
        int s1 = c[i] - len;
        if(s1 >= 0) SA[cnt[classes[s1]]++] = s1;
      }
      classes.swap(c);
    }
  }

  int operator[](int k) const {
    return SA[k];
  }

  size_t size() const {
    return s.size();
  }

  bool lt_substr(const string &t, int si = 0, int ti = 0) {
    int sn = (int) s.size(), tn = (int) t.size();
    while(si < sn && ti < tn) {
      if(s[si] < t[ti]) return true;
      if(s[si] > t[ti]) return false;
      ++si, ++ti;
    }
    return si >= sn && ti < tn;
  }

  int lower_bound(const string &t) {
    int low = -1, high = (int) SA.size();
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(lt_substr(t, SA[mid])) low = mid;
      else high = mid;
    }
    return high;
  }

  pair< int, int > lower_upper_bound(string &t) {
    int idx = lower_bound(t);
    int low = idx - 1, high = (int) SA.size();
    t.back()++;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(lt_substr(t, SA[mid])) low = mid;
      else high = mid;
    }
    t.back()--;
    return {idx, high};
  }

  void output() {
    for(int i = 0; i < size(); i++) {
      cout << i << ": " << s.substr(SA[i]) << endl;
    }
  }
};

struct LongestCommonPrefixArray {
  const SuffixArray &SA;
  vector< int > LCP, rank;

  LongestCommonPrefixArray(const SuffixArray &SA) : SA(SA), LCP(SA.size()) {
    rank.resize(SA.size());
    for(int i = 0; i < SA.size(); i++) {
      rank[SA[i]] = i;
    }
    for(int i = 0, h = 0; i < SA.size(); i++) {
      if(rank[i] + 1 < SA.size()) {
        for(int j = SA[rank[i] + 1]; max(i, j) + h < SA.size() && SA.s[i + h] == SA.s[j + h]; ++h);
        LCP[rank[i] + 1] = h;
        if(h > 0) --h;
      }
    }
  }

  int operator[](int k) const {
    return LCP[k];
  }

  size_t size() const {
    return LCP.size();
  }

  void output() {
    for(int i = 0; i < size(); i++) {
      cout << i << ": " << LCP[i] << " " << SA.s.substr(SA[i]) << endl;
    }
  }
};

template< typename T >
struct SparseTable {
  vector< vector< T > > st;

  SparseTable() {}

  SparseTable(const vector< T > &v) {
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  inline T rmq(int l, int r) // [l, r)
  {
    int b = 32 - __builtin_clz(r - l) - 1;
    return (min(st[b][l], st[b][r - (1 << b)]));
  }
};


const int B = 64;

int main() {
  string S, T;
  int Q;
  cin >> S >> T >> Q;

  int N = (int) S.size();
  int M = (int) T.size();
  S += T;


  SuffixArray sa(S);
  LongestCommonPrefixArray lcp(sa);
  SparseTable< int > rmq(lcp.LCP);

  vector< int > ord(N + 1);
  iota(begin(ord), end(ord), 0);

  using pi = pair< int, int >;
  auto get_lcp = [&](pi s, pi t) {
    int a = s.first + (s.second * N);
    int b = t.first + (t.second * N);
    if(a == b) return inf;
    a = lcp.rank[a];
    b = lcp.rank[b];
    if(a > b) swap(a, b);
    return rmq.rmq(a + 1, b + 1);
  };


  auto cmp = MFP([&](auto cmp, int a, int b) -> bool {
    if(a > b) return cmp(b, a) ^ 1;

    if(a + M > b) {

      {
        int get = get_lcp(pi(0, true), pi(a, false));
        if(a + get < b) return T[get] < S[a + get];
      }
      {
        int get = get_lcp(pi(b - a, true), pi(0, true));
        if(b - a + get < M) return T[b - a + get] < T[get];
      }
      {
        int get = get_lcp(pi(a, false), pi(a + M - b, true));
        if(a + M - b + get < M) return S[a + get] < T[a + M - b + get];
      }
    } else {
      {
        int get = get_lcp(pi(0, true), pi(a, false));
        if(get < M) return T[get] < S[a + get];
      }
      {
        int get = get_lcp(pi(a, false), pi(a + M, false));
        if(a + M + get < b) return S[a + get] < S[a + M + get];
      }
      {
        int get = get_lcp(pi(b - M, false), pi(0, true));
        if(get < M) return S[b - M + get] < T[get];
      }
    }
    return a < b;
  });

  sort(begin(ord), end(ord), cmp);


  vector< int > rev(ord.size());
  for(int i = 0; i < ord.size(); i++) rev[ord[i]] = i;

  vector< tuple< int, int, int, int, int > > qs[100001];
  for(int i = 0; i < Q; i++) {
    int l, r, k, x, y;
    cin >> l >> r >> k >> x >> y;
    ++r, ++y;
    qs[k].emplace_back(i, l, r, x, y);
  }

  vector< int > ans(Q, -1);
  auto f = [](int a, int b) { return min(a, b); };
  vector< SparseTable< int > > seg;
  for(int i = 1; i < B; i++) {
    if(qs[i].empty()) continue;
    vector< vector< int > > uku(i);
    for(int j = 0; j < rev.size(); j++) {
      uku[j % i].emplace_back(rev[j]);
    }
    for(int j = 0; j < i; j++) {
      seg.emplace_back(uku[j]);
    }
    for(auto &p : qs[i]) {
      int idx, l, r, x, y;
      tie(idx, l, r, x, y) = p;
      int ret = inf;
      for(int k = x; k < y; k++) {
        // [l, r)
        int latte = (l - 1 + i - k) / i;
        int malta = (r - 1 + i - k) / i;
        if(latte < malta) chmin(ret, seg[k].rmq(latte, malta));
      }
      if(ret != inf) ans[idx] = ord[ret];
    }
    seg.clear();
  }

  SparseTable< int > nene(rev);
  for(int i = B; i <= N; i++) {
    for(auto &p : qs[i]) {
      int idx, l, r, x, y;
      tie(idx, l, r, x, y) = p;
      int ret = inf;
      for(int cur = 0; cur < ord.size(); cur += i) {
        int top = max(l, cur + x);
        int bottom = min(r, cur + y);
        if(top < bottom) chmin(ret, nene.rmq(top, bottom));
      }
      if(ret != inf) ans[idx] = ord[ret];
    }
  }

  cout << ans << endl;
}