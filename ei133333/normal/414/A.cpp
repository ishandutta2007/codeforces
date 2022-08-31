#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;

  int sz = N >> 1;

  if(N == 1) {
    if(K == 0) cout << 1 << endl;
    else cout << -1 << endl;
    return (0);
  }

  if(sz > K) {
    cout << -1 << endl;
    return (0);
  }

  int less = K - sz + 1;

  cout << less << " " << less * 2 << " ";
  int sub = less * 2 + 1;
  for(int i = 2; i < N; i++) {
    cout << sub++ << " ";
  }
  cout << endl;
}