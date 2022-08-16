#include<bits/stdc++.h>

using namespace std;



int main()
{
  int N, A[100000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  bool sum[100001] = {};
  int reach = N;
  for(int i = 0; i < N; i++) {
    sum[A[i]] = true;
    if(reach == A[i]) {
      while(sum[reach]) {
        cout << reach-- << " ";
      }
    }
    cout << endl;
  }

}