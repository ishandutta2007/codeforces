#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N, A[50][50];
  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  bool check = false;
  for(int i = 0; i < N; i++) {
    int ret = 0;
    for(int j = 0; j < N; j++) {
      ret = max(ret, A[i][j]);
      ret = max(ret, A[j][i]);
    }
    if(i > 0) cout << " ";
    if(ret == N - 1 && !check++) cout << N;
    else cout << ret;
  }
  cout << endl;

}