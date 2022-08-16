#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

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
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  bool add = false;
  bool sub = false;
  bool mul = false;
  string S;
  cin >> S;
  for(auto &c : S) {
    if(c == '+') add = true;
    if(c == '-') sub = true;
    if(c == '*') mul = true;
  }

  if(!mul) {
    if(add) {
      cout << A[0];
      for(int i = 1; i < N; i++) cout << '+' << A[i];
      cout << "\n";
    } else {
      cout << A[0];
      for(int i = 1; i < N; i++) cout << '-' << A[i];
      cout << "\n";
    }
    return 0;
  }


  if(add) {
    vector< char > ans1;
    vector< int > ans2;
    deque< int > cur;

    auto solve = [&]() {
      // 1
      if(cur.empty()) return;

      while(cur.size() and cur[0] == 1) {
        ans1.emplace_back('+');
        ans2.emplace_back(1);
        cur.pop_front();
      }
      int tail = 0;
      while(cur.size() and cur.back() == 1) {
        cur.pop_back();
        ++tail;
      }
      if(!cur.empty()) {
        vector< int > beg;
        for(int i = 0; i < cur.size(); i++) {
          if(cur[i] == 1) {
            if(beg.empty() || cur[i - 1] != 1) {
              beg.emplace_back(i);
            }
          } else {
            if(beg.empty() || cur[i - 1] == 1) {
              beg.emplace_back(i);
            }
          }
        }
        beg.emplace_back(cur.size());

        int64 all = 1;
        vector< int64 > sup;
        for(int i = 0; i + 1 < beg.size(); i++) {
          int64 beet = 1;
          for(int j = beg[i]; j < beg[i + 1]; j++) {
            all *= cur[j];
            beet *= cur[j];
            chmin(all, inf);
          }
          if(i & 1) sup.emplace_back(beg[i + 1] - beg[i]);
          else sup.emplace_back(beet);
        }
        if(all >= inf) {
          ans1.emplace_back('+');
          ans2.emplace_back(cur[0]);
          for(int i = 1; i < cur.size(); i++) {
            ans1.emplace_back('*');
            ans2.emplace_back(cur[i]);
          }
        } else {
          auto dp = vector< int64 >(beg.size(), -infll);
          auto pre = vector< int >(beg.size(), -1);
          dp[0] = 0;
          for(int i = 0; i + 1 < beg.size(); i++) {
            if(i % 2 == 0) {
              int64 beet = 1;
              for(int j = i + 1; j < beg.size(); j++) {
                if(j % 2 == 1) {
                  beet *= sup[j - 1];
                  if(chmax(dp[j], dp[i] + beet)) {
                    pre[j] = i;
                  }
                }
              }
            } else {
              if(chmax(dp[i + 1], dp[i] + sup[i])) {
                pre[i + 1] = i;
              }
            }
          }
          int now = (int) beg.size() - 1;
          vector< int > divs;
          divs.emplace_back(now);
          while(now != 0) {
            now = pre[now];
            divs.emplace_back(now);
          }
          reverse(begin(divs), end(divs));
          for(int i = 0; i + 1 < divs.size(); i++) {
            if(divs[i] % 2 == 1) {
              for(int j = beg[divs[i]]; j < beg[divs[i + 1]]; j++) {
                ans1.emplace_back('+');
                ans2.emplace_back(cur[j]);
              }
            } else {
              for(int j = beg[divs[i]]; j < beg[divs[i + 1]]; j++) {
                ans1.emplace_back(j == beg[divs[i]] ? '+' : '*');
                ans2.emplace_back(cur[j]);
              }
            }
          }
        }
      }
      cur.clear();
      while(tail--) {
        ans1.emplace_back('+');
        ans2.emplace_back(1);
      }
    };
    for(auto &a : A) {
      if(a == 0) {
        solve();
        ans1.emplace_back('+');
        ans2.emplace_back(0);
      } else {
        cur.emplace_back(a);
      }
    }
    if(cur.size()) solve();
    cout << ans2[0];
    for(int i = 1; i < N; i++) cout << ans1[i] << ans2[i];
    cout << "\n";
  } else if(sub) {
    cout << A[0];
    for(int i = 1; i < N; i++) {
      if(A[i] == 0) cout << '-';
      else cout << '*';
      cout << A[i];
    }
    cout << "\n";
  } else {
    cout << A[0];
    for(int i = 1; i < N; i++) cout << '*' << A[i];
    cout << "\n";
  }
}