#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int hh, mm;
  double C;
  int64 H, D, N;

  cin >> hh >> mm;
  cin >> H >> D >> C >> N;

  int tt = hh * 60 + mm;
  double ret = 1e30;
  while(tt < 1440) {
    int64 need = (H + N - 1) / N;
    if(tt >= 1200) ret = min(ret, need * C * 0.8);
    else ret = min(ret, need * C);
    H += D;
    ++tt;
  }

  cout << fixed << setprecision(10) << ret << endl;
}