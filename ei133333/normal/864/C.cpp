#include<bits/stdc++.h>

using namespace std;

struct Taplis
{
  void TapTap()
  {
    int A, B, F, K;
    cin >> A >> B >> F >> K;

    int ret = 0;
    int cur = B;
    for(int i = 0; i < K; i++) {
      int need = (i % 2 == 0) ? F : (A - F);
      if(cur < need) {
        cout << -1 << endl;
        return;
      }
      cur -= need;

      int need2 = (i % 2 == 0) ? (A - F) : F;
      if(i + 1 != K) need2 *= 2;

      if(cur < need2) {
        cur = B;
        ++ret;
      }
      if(cur < need2) {
        cout << -1 << endl;
        return;
      }

      cur -= (i % 2 == 0) ? (A - F) : F;
    }

    cout << ret << endl;
  }
};

int main()
{
  Taplis().TapTap();
}