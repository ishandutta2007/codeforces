/*
 * 
 * 
 * https://www.youtube.com/channel/UCRXsI3FL_kvaVL9zoolBfbQ
 */

#include <bits/stdc++.h>

using namespace std;


using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 58) - 1;
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
  int N, M, K;
  cin >> N >> M >> K;
  vector< int > L(N), R(N);
  vector< int > xs;
  xs.reserve(N + N);
  for(int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
    ++R[i];
    xs.emplace_back(L[i]);
    xs.emplace_back(R[i]);
  }
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  vector< vector< int > > belong(xs.size());
  for(int i = 0; i < N; i++) {
    L[i] = lower_bound(begin(xs), end(xs), L[i]) - begin(xs);
    R[i] = lower_bound(begin(xs), end(xs), R[i]) - begin(xs);
    for(int j = L[i]; j < R[i]; j++) belong[j].emplace_back(i);
  }
  auto dp = make_v< int >(1);
  vector< int > pre;
  vector< int > last(N, -1), num(N, -1);
  vector< int > last2(N, -1);

  for(int i = 0; i < xs.size(); i++) {


    {
      vector< int > mark;
      for(int j : pre) {
        if(binary_search(begin(belong[i]), end(belong[i]), j)) {
          last[j] = i;
          num[j] = mark.size();
          mark.emplace_back(j);
        }
      }
      auto nxt_dp = make_v< int >(1 << mark.size());
      fill_v(nxt_dp, -inf);
      for(int j = 0; j < dp.size(); j++) {
        int bit = 0;
        for(int k = 0; k < pre.size(); k++) {
          if((j >> k) & 1) {
            if(last[pre[k]] != i) continue;
            bit |= 1 << num[pre[k]];
          }
        }
        chmax(nxt_dp[bit], dp[j]);
      }
      nxt_dp.swap(dp);
      pre.swap(mark);
    }


    {
      vector< int > mark;
      int ptr = 0;
      for(int j : pre) {
        int po = lower_bound(begin(belong[i]), end(belong[i]), j) - begin(belong[i]);
        last2[po] = i;
        num[po] = ptr++;
      }


      auto nxt_dp = make_v< int >(1 << belong[i].size());
      fill_v(nxt_dp, -inf);
      for(int j = 0; j < nxt_dp.size(); j++) {
        int bit = 0;
        for(int k = 0; k < belong[i].size(); k++) {
          if((j >> k) & 1) {
            if(last2[k] != i) continue;
            bit |= 1 << num[k];
          }
        }
        chmax(nxt_dp[j], dp[bit]);
      }
      nxt_dp.swap(dp);
      pre.swap(belong[i]);
    }

    if(i + 1) {
      // update_dp
      for(int j = 0; j < dp.size(); j++) {
        int sz = __builtin_popcount(j);
        if(sz == 0) {
          continue;
        } else if(sz % 2 == 1) { // +1
          dp[j] += (xs[i + 1] - xs[i]);
        } else { // +2
        //  dp[j] += (xs[i + 1] - xs[i]) * 2;
        }
      }
    }


  }

  cout << *max_element(begin(dp), end(dp)) << endl;
}