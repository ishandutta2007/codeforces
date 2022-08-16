#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
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
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
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


string answer = "guese";

int ask_char(int i) {
  cout << "? " << 1 << " " << i + 1 << endl;
  char c;
  cin >> c;
  return c - 'a';
}

// [l, r]
int ask_kind(int l, int r) {
  cout << "? " << 2 << " " << l + 1 << " " << r + 1 << endl;
  int k;
  cin >> k;
  return k;
}

int main() {
  int N;
  cin >> N;
  vector< int > first_appear(26, N);

  vector< int > ans(N, -1);
  {
    int t = ask_char(0);
    ans[0] = t;
    first_appear[t] = 0;
    for(int i = 2; i <= 26; i++) {
      int ok = N, ng = -1;
      while(ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if(ask_kind(0, mid) >= i) ok = mid;
        else ng = mid;
      }
      if(ok == N) break;
      t = ask_char(ok);
      first_appear[t] = ok;
      ans[ok] = t;
    }
  }

  for(int i = 0; i < N; i++) {
    if(ans[i] == -1) {
      vector< pair< int, int > > mx;
      for(int j = 0; j < 26; j++) {
        if(first_appear[j] < i) {
          mx.emplace_back(first_appear[j], j);
        }
      }
      sort(mx.begin(), mx.end());
      int ok = 0, ng = mx.size();
      while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if(ask_kind(mx[mid].first, i) == mx.size() - mid) ok = mid;
        else ng = mid;
      }
      ans[i] = mx[ok].second;
    }
    first_appear[ans[i]] = i;
  }

  cout << "! ";
  for(auto &c: ans) cout << (char) (c + 'a');
  cout << endl;
}