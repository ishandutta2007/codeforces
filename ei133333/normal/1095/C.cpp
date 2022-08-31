#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N, K;
  cin >> N >> K;
  vector< int64 > ans;

  for(int i = 0; i < K; i++) {
    int64 best = 0;
    for(int j = 0; j < 31; j++) {
      int64 cur = 1 << j;
      int64 rest = N - cur;
      if(rest < 0) continue;
      if(K - i - 1 > rest) continue;
      best = cur;
    }
    if(best == 0) {
      cout << "NO\n";
      return 0;
    }
    ans.push_back(best);
    N -= best;
  }
  if(N != 0) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for(auto& p : ans) cout << p << " ";
  cout << endl;

}