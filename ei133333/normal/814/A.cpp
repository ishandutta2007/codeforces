#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, K, A[100], B[100];
  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < K; i++) cin >> B[i];
  sort(B, B + K);
  int tail = 0;
  for(int i = N - 1; i >= 0; i--) {
    if(A[i] == 0) A[i] = B[tail++];
  }
  if([&]()
  {
    for(int i = 1; i < N; i++)
      if(A[i - 1] > A[i]) return (true);
    return (false);
  }())
    cout << "Yes" << endl;
  else cout << "No" << endl;
}