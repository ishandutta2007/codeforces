#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
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


int K;
string S, A, B;
int mark[26];
bool used[26];

bool dfs(int idx, bool low, bool high) {
  if(idx == S.size()) {
    return true;
  }
  if(~mark[S[idx]]) {
    if(!low && mark[S[idx]] < A[idx]) return false;
    if(!high && mark[S[idx]] > B[idx]) return false;
    return dfs(idx + 1, low | (mark[S[idx]] > A[idx]), high | (mark[S[idx]] < B[idx]));
  } else if(high) { //B -> 
    for(int i = K - 1; i >= 0; i--) {
      if(!used[i]) {
        used[i] = true;
        mark[S[idx]] = i;
        if(low || mark[S[idx]] >= A[idx]) {
          auto ret = dfs(idx + 1, low | (mark[S[idx]] > A[idx]), high | (mark[S[idx]] < B[idx]));
          if(ret) return true;
        }
        mark[S[idx]] = -1;
        used[i] = false;
      }
    }
  } else if(low) { // A high -> 
    for(int i = 0; i < K; i++) {
      if(!used[i]) {
        used[i] = true;
        mark[S[idx]] = i;
        if(mark[S[idx]] <= B[idx]) {
          auto ret = dfs(idx + 1, low | (mark[S[idx]] > A[idx]), high | (mark[S[idx]] < B[idx]));
          if(ret) return true;
        }
        mark[S[idx]] = -1;
        used[i] = false;
      }
    }
  } else {
    for(int _ = 0; _ < K; _++) {
      int i = (_ + A[idx] + 1) % K;
      if(!used[i]) {
        used[i] = true;
        mark[S[idx]] = i;
        if(mark[S[idx]] >= A[idx] && mark[S[idx]] <= B[idx]) {
          auto ret = dfs(idx + 1, low | (mark[S[idx]] > A[idx]), high | (mark[S[idx]] < B[idx]));
          if(ret) return true;
        }
        mark[S[idx]] = -1;
        used[i] = false;
      }
    }
  }
  return false;
}


void uku() {
  cin >> K >> S >> A >> B;
  for(auto &c : S) c -= 'a';
  for(auto &c : A) c -= 'a';
  for(auto &c : B) c -= 'a';
  memset(mark, -1, sizeof(mark));
  memset(used, false, sizeof(used));
  if(dfs(0, false, false)) {
    cout << "YES\n";
    int ptr = 0;
    for(int i = 0; i < K; i++) {
      if(mark[i] == -1) {
        while(used[ptr])++ptr;
        cout << (char) ('a' + ptr);
        ++ptr;
      } else {
        cout << (char) ('a' + mark[i]);
      }
    }
    cout << "\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  int T;
  cin >> T;
  while(T--) uku();
}