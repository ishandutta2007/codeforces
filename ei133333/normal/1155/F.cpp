#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = (int) (1e6 + 3);

const int64 infll = (1LL << 62) - 1;
const int inf = 1 << 25;


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

int N, M;
bool g[14][14];
int ex[1 << 14];
int pop[1 << 14];
int dp[1 << 14];
int dp2[1 << 14][14][14];

int rec_bi(int bit);

int rec_path(int bit, int k, int l) {
  if(pop[bit] <= 1) return 0;
  if(~dp2[bit][k][l]) return dp2[bit][k][l];
  int ret = rec_bi(bit);

  int i = 1<<k;
  int j = (1<<k) ^bit;
  if((j >> l) & 1 && (i >> k) & 1) {
    for(int r = 0; r < N; r++) {
      if((j >> r) & 1 && pop[ex[1 << r] & i] >= 1) {
        chmin(ret, rec_bi(i) + rec_path(j, r, l) + 1);
      }
    }
  }
  return dp2[bit][k][l] = ret;
}

int rec_bi(int bit) {
  if(pop[bit] <= 1) return 0;
  if(~dp[bit]) return dp[bit];
  int ret = inf;
  for(int i = bit; i > 0; i = (i - 1) & bit) { // 1
    int j = i ^bit;
    if(i == bit) continue;
    for(int k = 0; k < N; k++) {
      if((j >> k) & 1 && pop[ex[1 << k] & i]) {
        for(int l = 0; l < k; l++) {
          if((j >> l) & 1 && pop[ex[1 << l] & i]) {
            chmin(ret, rec_bi(i) + rec_path(j, k, l) + 2);
          }
        }
      }
    }
  }
  return dp[bit] = ret;
}


void rec_bi2(int bit);

void rec_path2(int bit, int k, int l) {
  if(pop[bit] <= 1) return;
  int ret = dp2[bit][k][l];
  if(ret == rec_bi(bit)) {
    rec_bi2(bit);
    return;
  }
  int i = 1<<k;
  int j = (1<<k) ^bit;
  if((j >> l) & 1 && (i >> k) & 1) {
    for(int r = 0; r < N; r++) {
      if((j >> r) & 1 && pop[ex[1 << r] & i] >= 1) {
        if(ret == rec_bi(i)+rec_path(j,r,l)+1) {
          cout << r + 1 << " " << k + 1 << endl;
          rec_bi2(i);
          rec_path2(j, r, l);
          return;
        }
      }
    }
  }
}

void rec_bi2(int bit) {
  if(pop[bit] <= 1) return;
  int ret = dp[bit];
  for(int i = bit; i > 0; i = (i - 1) & bit) { // 1
    int j = i ^bit;
    if(i == bit) continue;
    for(int k = 0; k < N; k++) {
      for(int l = 0; l < k; l++) {
        if((j >> k) & 1 && (j >> l) & 1) {
          if(pop[ex[1 << k] & i] && pop[ex[1 << l] & i]) {
            if(rec_bi(i) + rec_path(j, k, l) + 2 == ret) {

              for(int p = 0; p < N; p++) {
                if(g[k][p] && (i >> p) & 1) {
                  cout << k + 1 << " " << p + 1 << endl;
                  break;
                }
              }
              for(int p = 0; p < N; p++) {
                if(g[l][p] && (i >> p) & 1) {
                  cout << l + 1 << " " << p + 1 << endl;
                  break;
                }
              }

              rec_bi2(i);
              rec_path2(j, k, l);
              return;
            }
          }
        }
      }
    }
  }
}

int main() {
  memset(dp, -1, sizeof(dp));
  memset(dp2, -1, sizeof(dp2));

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a][b] = g[b][a] = true;
  }
  for(int i = 0; i < 1 << N; i++) {
    pop[i] = __builtin_popcount(i);
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        if((i >> j) & 1 && g[j][k]) ex[i] |= 1 << k;
      }
    }
  }
  int ret = 0;
  cout << rec_bi((1 << N) - 1) << endl;
  rec_bi2((1 << N) - 1);

}