#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M, A[1000], B[1000];
  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  auto check = [&](double rest) {
    rest += M;
    for(int i = 0; i < N; i++) {
      rest -= rest / A[i];
      rest -= rest / B[(i + 1) % N];
    }
    return rest >= M;
  };
  double low = 0, high = 1e18;
  if(!check(high)) {
    cout << -1 << endl;
    return 0;
  }
  for(int i = 0; i < 400; i++) {
    double mid = (low + high) * 0.5;
    if(check(mid)) high = mid;
    else low = mid;
  }
  cout << fixed << setprecision(10) << high << endl;
}