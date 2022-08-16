#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int MOD = 1e9 + 7;

int main()
{
  int64 N, K, A[100000], B[100000];

  cin >> N >> K;

  int64 mask = 1LL;
  for(int i = 0; i < K; i++) mask *= 10LL;

  for(int i = 0; i < N / K; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < N / K; i++) {
    cin >> B[i];
    B[i] *= mask / 10LL;
  }

  int64 ret = 1;
  for(int i = 0; i < N / K; i++) {
    int64 ALL = (mask - 1) / A[i] + 1;
    int64 Lazy;
    if(B[i] == 0) {
      Lazy = (mask / 10LL - 1) / A[i] + 1;
    } else {
      int64 Top = (B[i] + mask / 10LL - 1) / A[i] + 1;
      int64 Tail = (B[i] - 1) / A[i] + 1;
      Lazy = Top - Tail;
    }
    (ret *= ALL - Lazy) %= MOD;
  }
  cout << ret << endl;

}