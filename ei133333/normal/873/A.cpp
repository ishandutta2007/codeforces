#include<bits/stdc++.h>

using namespace std;


int main()
{
  int N, K, X, A[100];

  cin >> N >> K >> X;

  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ret = 0;
  for(int i = 0; i < N - K; i++) {
    ret += A[i];
  }
  cout << ret + K * X << endl;
}