#include <bits/stdc++.h>

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
  string x;
  for(char i = 'a'; i <= 'z'; i++) x += i;
  for(char i = 'A'; i <= 'Z'; i++) x += i;
  for(char i = '0'; i <= '9'; i++) x += i;


  int T;
  cin >> T;
  while(T--) {
    int H, W, K;
    cin >> H >> W >> K;
    vector< string > S(H);
    cin >> S;
    // 

    int sum = 0;
    for(auto &s : S) for(auto &c : s) sum += c == 'R';


    int sz = sum / K;

    int high = sum - sz * K;
    int low = K - high;
    int cnt = 0, used = 0;

    auto ans = make_v< char >(H, W);

    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        int now = j;
        if(i % 2 == 0) now = W - now - 1;


        cnt += S[i][now] == 'R';

        ans[i][now] = x[min(K-1, used)];


        if(low > 0 && sz == cnt) {
          cnt = 0;
          --low;
          used++;
        } else if(high > 0 && sz + 1 == cnt) {
          cnt = 0;
          --high;
          used++;
        }
      }
    }

    for(auto &s : ans) {
      for(auto &c : s) {
        cout << c;
      }
      cout << endl;
    }

  }
}