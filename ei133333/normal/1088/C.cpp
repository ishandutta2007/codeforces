#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[100000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  int64 preadd = 0;
  cout << N + 1 << endl;
  for(int i = N - 1; i >= 0; i--) {
    int64 mod = ((N + i) - ((A[i] + preadd) % N)) % N;
    if(mod == 0) mod += N;
    cout << "1 " << i + 1 << " " << mod << endl;
    (preadd += mod) %= N;
  }
  cout << "2 " << N << " " << N << endl;
}