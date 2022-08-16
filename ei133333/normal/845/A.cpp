#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N, A[200];
  cin >> N;
  for(int i = 0; i < 2 * N; i++) {
    cin >> A[i];
  }
  sort(A, A + 2 * N, greater< int >());
  for(int i = 0; i < N; i++) {
    if(A[i] <= A[N]) {
      cout << "NO" << endl;
      return (0);
    }
  }
  cout << "YES" << endl;
}