#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = int(1e6) + 3;
int vals[MOD + 100][12];

int main() {
  for (int i = 0; i <= 11; i++) {
    cout << "?" << ' ' << i << endl << flush;
    cin >> vals[i][0];
    if (vals[i][0] == -1) exit(0);
    for (int j = 0; j < i; j++) {
      vals[i-j-1][j+1] = (vals[i-j][j] - vals[i-j-1][j] + MOD) % MOD;
    }
  }
  assert(vals[0][11] == 0);
  for (int j = 10; j >= 0; j--) {
    for (int i = 1; i < MOD; i++) {
      vals[i][j] = (vals[i-1][j] + vals[i-1][j+1]) % MOD;
    }
  }
  for (int i = 0; i < MOD; i++) {
    if (vals[i][0] == 0) {
      cout << "!" << ' ' << i << endl << flush; exit(0);
    }
  }
  cout << "!" << ' ' << -1 << endl << flush; exit(0);
}