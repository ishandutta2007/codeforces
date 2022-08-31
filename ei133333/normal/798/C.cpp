#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, A[100000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  if(N == 1) {
    if(A[0] == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << 0 << endl;
    }
    return (0);
  }

  int64 gcd = A[0];
  for(int i = 1; i < N; i++) gcd = __gcd(gcd, A[i]);

  cout << "YES" << endl;
  if(gcd >= 2) {
    cout << 0 << endl;
    return (0);
  }

  int ret = 0;
  for(int i = 1; i < N; i++) {
    if(A[i - 1] % 2 != 0 || A[i] % 2 != 0) {
      if(A[i - 1] % 2 == 0) continue;
      while(A[i - 1] % 2 != 0 || A[i] % 2 != 0) {
        int64 st = A[i - 1] - A[i];
        int64 gt = A[i - 1] + A[i];
        A[i - 1] = st;
        A[i] = gt;
        ++ret;
      }
    }
  }

  for(int i = N - 1; i > 0; i--) {
    if(A[i - 1] % 2 != 0 || A[i] % 2 != 0) {
      if(A[i] % 2 == 0 && i != 1) continue;
      while(A[i - 1] % 2 != 0 || A[i] % 2 != 0) {
        int64 st = A[i - 1] - A[i];
        int64 gt = A[i - 1] + A[i];
        A[i - 1] = st;
        A[i] = gt;
        ++ret;
      }
    }
  }
  cout << ret << endl;
}