#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N, A[1000];
  int K = 0;
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    K += A[i] == 0;
  }
  if(N == 1) {
    if(A[0] == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
  } else if(K == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}