#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
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

string beet(string S) {
  int N = (int) S.size();
  vector< int > C(26);
  for(auto &c : S) C[c - 'a']++;


  for(int i = 0; i < 26; i++) {
    if(C[i] == 1) {
      string T;
      T += (char) (i + 'a');
      C[i]--;
      for(int j = 0; j < 26; j++) {
        while(C[j] > 0) {
          --C[j];
          T += (char) (j + 'a');
        }
      }
      return T;
    }
  }

  for(auto c : C) {
    if(c == N) {
      return S;
    }
  }


  vector< int > occur;
  for(int i = 0; i < 26; i++) {
    if(C[i]) occur.emplace_back(i);
  }

  string ans = "~";


  // 23
  // f=1(1)
  // abaaaaac+sorted
  // ^ ^^^^^
  if(occur.size() >= 3) {
    auto D{C};
    string X;
    X += (char) (occur[0] + 'a');
    X += (char) (occur[1] + 'a');
    D[occur[0]]--;
    D[occur[1]]--;
    while(D[occur[0]] > 0) {
      D[occur[0]]--;
      X += (char) (occur[0] + 'a');
    }
    D[occur[2]]--;
    X += (char) (occur[2] + 'a');
    for(int j = 0; j < 26; j++) {
      while(D[j] > 0) {
        D[j]--;
        X += (char) (j + 'a');
      }
    }
    chmin(ans, X);
  }

  // f=1 a(2)
  // aabababacacaccccc
  // ^^ ^ ^ ^ ^ ^
  {
    auto D{C};
    string X;
    X += (char) (occur[0] + 'a');
    D[occur[0]]--;

    bool f = false;
    while(X.size() < N) {
      if(f) {
        //a
        bool ok = false;
        for(int j : occur) {
          if(occur[0] == j) {
            continue;
          }
          if(D[j] > 0) {
            D[j]--;
            X += (char) (j + 'a');
            ok = true;
            break;
          }
        }
        if(not ok) {
          X.clear();
          break;
        }
      } else {
        //
        for(int j : occur) {
          if(D[j] > 0) {
            D[j]--;
            X += (char) (j + 'a');
            break;
          }
        }
      }
      f ^= 1;
    }
    if(X.size() == N) {
      chmin(ans, X);
    }
  }


  {
    auto D{C};
    string X;
    X += (char) (occur[0] + 'a');
    D[occur[0]]--;
    while(D[occur[1]] > 0) {
      D[occur[1]]--;
      X += (char) (occur[1] + 'a');
    }
    for(int j : occur) {
      while(D[j] > 0) {
        D[j]--;
        X += (char) (j + 'a');
      }
    }
    chmin(ans, X);
  }
  return ans;
}


int main() {

  int T;
  cin >> T;
  while(T--) {
    string X;
    cin >> X;
    cout << beet(X) << "\n";
  }
}