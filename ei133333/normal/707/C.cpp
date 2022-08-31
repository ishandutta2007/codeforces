#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N;
  cin >> N;

  if(N <= 2) {
    cout << -1 << endl;
  } else if(N % 2 == 1) {
    cout << (N * N - 1) / 2 << " " << (N * N + 1) / 2 << endl;
  } else {
    N /= 2;
    cout << N * N - 1 << " " << N * N + 1 << endl;
  }
}