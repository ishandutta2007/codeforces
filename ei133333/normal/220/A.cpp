#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;

  cin >> N;
  vector< int > A(N), B(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    B[i] = A[i];
  }
  sort(begin(B), end(B));
  int ret = 0;
  for(int i = 0; i < N; i++) {
    ret += A[i] != B[i];
  }
  if(ret > 2) cout << "NO" << endl;
  else cout << "YES" << endl;
}