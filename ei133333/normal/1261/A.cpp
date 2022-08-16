#include <bits/stdc++.h>

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
  int T;
  cin >> T;
  while(T--) {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;


    vector< int > seq;
    int sum = 0, used = 0;
    for(int i = 0; i < N; i++) {
      int sum2 = sum + 1;
      int zan = N - i - 1;
      if(used + 1 + (zan - sum2) / 2 >= K) {
        sum += 1;
        seq.emplace_back(1);
      } else {
        sum -= 1;
        used += sum == 0;
        seq.emplace_back(-1);
      }
    }

    vector< pair< int, int > > op;
    for(int i = 0; i < N; i++) {
      for(int j = i; j < N; j++) {
        if(seq[i] == 1) {
          if(S[j] == '(') {
            reverse(begin(S) + i, begin(S) + j + 1);
            op.emplace_back(i, j);
            break;
          }
        } else {
          if(S[j] == ')') {
            reverse(begin(S) + i, begin(S) + j + 1);
            op.emplace_back(i, j);
            break;
          }
        }
      }
    }
    cout << op.size() << endl;
    for(auto &p : op) cout << p.first + 1 << " " << p.second + 1 << endl;
  }
}