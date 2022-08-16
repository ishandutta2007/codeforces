#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
int main() {
  int B, K, P[100];
  cin >> B >> K;
  int mul = 0;
  for(int i = 0; i < K; i++) {
    int p;
    cin >> p;
    mul = mul * B;
    mul %= 2;
    mul += p;
    mul %= 2;
  }
  if(mul & 1) puts("odd");
  else puts("even");

}