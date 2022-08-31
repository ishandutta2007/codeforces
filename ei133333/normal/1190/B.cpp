#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 60) - 1;
const int64 infll2 = (1LL << 58) - 1;
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


int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;

  sort(begin(A), end(A));


  map< int, int > mp;
  for(auto &t : A) ++mp[t];
  vector< int > two;
  for(auto &p : mp) {
    if(p.second >= 3) {
      cout << "cslnb" << endl;
      return 0;
    }
    if(p.second == 2) {
      two.emplace_back(p.first);
    }
  }
  if(two.size() >= 2) {
    cout << "cslnb" << endl;
    return 0;
  }

  bool ban = false;

  if(two.size() == 1) {
    if(two[0] == 0) {
      cout << "cslnb" << endl;
      return 0;
    }
    if(mp.count(two[0] - 1)) {
      cout << "cslnb" << endl;
      return 0;
    }
    for(auto &p : A) {
      if(two[0] == p) {
        ban = true;
        --p;
        break;
      }
    }
  }

  int64 space = 0;
  for(int k = 0; k < N; k++) {
    space += A[k] - k;
  }


  if(space % 2 == 0) {
    if(!ban) cout << "cslnb" << endl;
    else cout << "sjfnb" << endl;
  } else {

    if(!ban) cout << "sjfnb" << endl;
    else cout << "cslnb" << endl;
  }

}