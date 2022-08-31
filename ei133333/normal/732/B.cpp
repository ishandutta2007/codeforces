#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K, A[500];

  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ret = 0;
  for(int i = 1; i < N; i++) {
    int get = max(0, K - A[i - 1] - A[i]);
    ret += get;
    A[i] += get;
  }

  cout << ret << endl;
  for(int i = 0; i < N; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}