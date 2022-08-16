#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int main() {
  int A, B, C, N;
  cin >> A >> B >> C >> N;
  A -= C;
  B -= C;
  if(A < 0 || B < 0 || A + B + C >= N) {
    cout << -1 << endl;
  } else {
    cout << N - (A + B + C) << endl;
  }
}