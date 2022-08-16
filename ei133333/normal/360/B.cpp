#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int INF = 1 << 30;

int main()
{
  int N, K, A[2000];

  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto check = [&](int64 v)
  {
    vector< int > dp(N);
    for(int i = 0; i < N; i++) dp[i] = i;
    for(int i = 0; i < N; i++) {
      for(int k = i - 1; k >= 0; k--) {
        int x = A[i], y = A[k];
        if(x > y) swap(x, y);
        int64 elements = i - k;
        int64 need = (y - x + elements - 1) / elements;
        if(need > v) continue;
        dp[i] = min(dp[i], dp[k] + (i - k - 1));
      }
      if(dp[i] + (N - i - 1) <= K) return (true);
    }
    return (false);
  };
  int64 ok = 1LL << 32, ng = -1;
  while(ok - ng > 1) {
    int64 mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
}