#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, A[100];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int xx = *max_element(A, A + N);
  int ret = 0;
  for(int i = 0; i < N; i++) {
    ret += xx - A[i];
  }
  cout << ret << endl;

}