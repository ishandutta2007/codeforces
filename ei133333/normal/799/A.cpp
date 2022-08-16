#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, T, K, D;
  cin >> N >> T >> K >> D;

  int64 normal = (N + K - 1) / K * T;

  int64 hard = 0;
  priority_queue< int64, vector< int64 >, greater< int64 > > que;
  que.push(0);
  que.push(D);

  while(N > 0) {
    int64 p = que.top();
    que.pop();
    N -= K;
    hard = p + T;
    que.push(p + T);
  }
  if(normal <= hard) cout << "NO" << endl;
  else cout << "YES" << endl;
}