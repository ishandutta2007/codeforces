#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N, K, A[100000];

  cin >> N >> K;

  int beet = numeric_limits< int >::max();
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    beet = min(beet, A[i]);
  }


  for(int i = 0; i < N; i++) {
    A[i] -= beet;
  }

  int64 ret = 0LL;
  for(int i = 0; i < N; i++) {
    if(A[i] % K != 0) {
      cout << -1 << endl;
      return (0);
    }
    ret += A[i] / K;
  }

  cout << ret << endl;
}