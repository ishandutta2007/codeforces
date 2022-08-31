#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const double PI = acos(-1);

int main() {
  int N, R;

  cin >> N >> R;


  double ok = 0, ng = 1e9;
  auto check = [&](double r) {
    double A = 2 * r;
    double B = R + r;
    double C = R + r;
    double cosA = (B * B + C * C - A * A) / (2 * B * C);
    return acos(cosA) * N <= 2 * PI;
  };


  for(int i = 0; i < 200; i++) {
    double mid = (ok + ng) * 0.5;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  cout << fixed << setprecision(10) << ok << endl;
}