#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, A[100];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int sum = accumulate(A, A + N, 0);

  if(sum != 0) {
    cout << "YES" << endl;
    cout << 1 << endl;
    cout << 1 << " " << N << endl;
    return(0);
  }

  for(int i = 1; i < N; i++) {
    int a = 0, b = 0;
    for(int j = 0; j < i; j++) a += A[j];
    for(int j = i; j < N; j++) b += A[j];
    if(a != 0 && b != 0) {
      cout << "YES" << endl;
      cout << 2 << endl;
      cout << 1 << " " << i << endl;
      cout << i + 1 << " " << N << endl;
      return(0);
    }
  }

  cout << "NO" << endl;
}