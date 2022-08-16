#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

int main() {
  int N, A, D, T[100000], V[100000];
  cin >> N >> A >> D;
  for(int i = 0; i < N; i++) {
    cin >> T[i] >> V[i];
  }
  double ret = 0.0;
  for(int i = 0; i < N; i++) {
    double X = 1.0 * V[i] * V[i] / 2.0 / A;
    double add = 0;
    if(X <= D) {
      // X = A t^2 / 2
      // 2X/A = t^2
      add += T[i];
      add += sqrt(2.0 * X / A);
      add += (D - X) / V[i];
    } else {
      add += T[i];
      add += sqrt(2.0 * D / A);
    }
    ret = max(ret, add);
    cout << fixed << setprecision(10) << ret << endl;
  }
}