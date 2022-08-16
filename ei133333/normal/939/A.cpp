#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, A[5000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    --A[i];
  }
  for(int i = 0; i < N; i++) {
    int to = A[i];
    int toto = A[to];
    int tototo = A[toto];
    if(i == tototo) {
      cout << "YES" << endl;
      return(0);
    }
  }
  cout << "NO" << endl;
}