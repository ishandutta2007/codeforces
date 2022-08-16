#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 La, Ra, Ta, Lb, Rb, Tb;
  cin >> La >> Ra >> Ta >> Lb >> Rb >> Tb;
  if(make_pair(La, Ra) > make_pair(Lb, Rb)) {
    swap(La, Lb);
    swap(Ra, Rb);
    swap(Ta, Tb);
  }
  ++Ra, ++Rb;
  auto beet = __gcd(Ta, Tb);
  // La+beet  Lb
  auto it = (Lb - La) / beet;
  int64 ret = 0;
  for(int64 x = it; x <= it + 1; x++) {
    int64 L = max(La + beet * x, Lb);
    int64 R = min(Ra + beet * x, Rb);
    ret = max(ret, R - L);
  }
  cout << ret << endl;
}