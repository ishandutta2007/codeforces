#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int64 dp[51][51][51];

int main() {
  int64 N, A[51], B[51];
  cin >> N;
  vector< pair< int, int > > vs(N);
  for(int i = 0; i < N; i++) cin >> vs[i].first;
  for(int i = 0; i < N; i++) cin >> vs[i].second;
  sort(begin(vs), end(vs));
  reverse(begin(vs), end(vs));
  for(int i = 0; i < N; i++) tie(A[i], B[i]) = vs[i];
  A[N] = -1;


  int64 low = 0, high = 1000000000000LL;

  auto check = [&](int64 v) {
    vector< int64 > C(N);
    for(int i = 0; i < N; i++) {
      C[i] = A[i] * 1000LL - B[i] * v;
    }
    memset(dp, -1, sizeof(dp));
    function< int64(int, int, int) > rec = [&](int first, int firstsame, int last) {
      int idx = first + firstsame + last;
      if(idx == N) return 0LL;
      if(~dp[first][firstsame][last]) return dp[first][firstsame][last];
      int64 ret = 1LL << 60;
      if(first > last) {
        if(A[idx] != A[idx + 1]) ret = min(ret, rec(first + firstsame, 0, last + 1));
        else ret = min(ret, rec(first, firstsame, last + 1));
      }
      if(A[idx] != A[idx + 1]) ret = min(ret, rec(first + firstsame + 1, 0, last) + C[idx]);
      else ret = min(ret, rec(first, firstsame + 1, last) + C[idx]);
      return dp[first][firstsame][last] = ret;
    };
    return rec(0, 0, 0) <= 0;
  };
  while(high - low > 1) {
    int64 mid = (low + high) / 2;
    if(check(mid)) high = mid;
    else low = mid;
  }
  cout << high << endl;
}