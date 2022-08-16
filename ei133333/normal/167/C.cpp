#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int grundy2(int64 x, int64 y) {
  if(x > y) swap(x, y);
  if(x == 0) return 0;
  auto ret = grundy2(x, y % x);
  if(!ret) return 1;
  int64 t = (y / x) % (x + 1);
  return 1 - t % 2;
}



int main() {
  int T;
  cin >> T;
  while(T--) {
    int64 X, Y;
    cin >> X >> Y;
    if(grundy2(X, Y)) puts("First\n");
    else puts("Second\n");
  }
}