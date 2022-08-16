#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, A[2000];

  cin >> N;
  int non = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    if(A[i] > 1) ++non;
  }

  if(non != N) {
    cout << non << endl;
    return(0);
  }

  int cost = 11451419;
  for(int i = 0; i < N; i++) {
    int gcd = A[i];
    for(int j = i; j < N; j++) {
      gcd = __gcd(gcd, A[j]);
      if(gcd == 1) {
        cost = min(cost, j-i+N-1);
      }
    }
  }

  if(cost == 11451419) cost = -1;
  cout << cost << endl;
}