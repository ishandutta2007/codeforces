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
  for(int i = 1; i < N; i++) {
    cout << A[i] + A[i - 1] << " ";
  }
  cout << A[N - 1] << endl;
}