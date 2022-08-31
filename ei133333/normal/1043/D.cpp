#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int _base = 1e9 + 7;

template< unsigned mod >
struct RollingHash {
  vector< unsigned > hashed, power;

  inline unsigned mul(unsigned a, unsigned b) const {
    unsigned long long x = (unsigned long long) a * b;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
    return m;
  }

  RollingHash(const vector< int > &s, unsigned base = 10007) {
    int sz = (int) s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
    }
  }

  unsigned get(int l, int r) const {
    unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
    if(ret >= mod) ret -= mod;
    return ret;
  }

  unsigned connect(unsigned h1, int h2, int h2len) const {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if(ret >= mod) ret -= mod;
    return ret;
  }

  int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return (low);
  }
};

using RH1 = RollingHash< 1000000007 >;
using RH2 = RollingHash< 1000000007 >;


int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  vector< int > A[10], pos[10];
  vector< pair< RH1, RH2 > > roll;
  for(int i = 0; i < M; i++) {
    A[i].resize(N), pos[i].resize(N);
    for(int j = 0; j < N; j++) {
      scanf("%d", &A[i][j]);
      --A[i][j];
      pos[i][A[i][j]] = j;
    }
    roll.emplace_back(RH1(A[i]), RH2(A[i]));
  }
  int64 ret = 0;

  for(int i = 0; i < N; i++) {
    int ok = N - i;
    for(int j = 1; j < M; j++) {
      ok = min(ok, N - pos[j][A[0][i]]);
    }
    for(int j = 1; j < M; j++) {
      ok = min(ok, min(roll[0].first.LCP(roll[j].first, i, i + ok, pos[j][A[0][i]], pos[j][A[0][i]] + ok), roll[0].second.LCP(roll[j].second, i, i + ok, pos[j][A[0][i]], pos[j][A[0][i]] + ok)));
    }
    ret += ok;
  }
  cout << ret << endl;
}