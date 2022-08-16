#include <bits/stdc++.h>

using namespace std;

using int64 = long long;



int main() {
  int64 H, W;
  cin >> H >> W;
  if(H > W) swap(H, W);

  if(H == 1) {
    if(W <= 3) cout << 0 << endl;
    else if((W - 4) % 6 >= 2) cout << (W + 2) / 6 * 6 << endl;
    else if((W - 4) % 6 == 1) cout << (W + 2) / 6 * 6 - 2 << endl;
    else cout << (W + 2) / 6 * 6 - 4 << endl;
    return 0;
  }

  if(H * W % 2 == 1) {
    cout << H * W - 1 << endl;
    return 0;
  }

  if(H == 2 && W == 2) cout << 0 << endl;
  else if(H == 2 && W == 3) cout << 4 << endl;
  else if(H == 2 && W == 7) cout << 12 << endl;
  else cout << H * W << endl;
}