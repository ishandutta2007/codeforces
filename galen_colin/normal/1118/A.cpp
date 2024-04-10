#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
      ll a, b, c;
      cin >> a >> b >> c;
      ll tot = 0;
      if (a%2==1) {
        a--;
        tot += b;
      }
      if (b*2 > c) {
        tot += c * (a / 2);
      } else {
        tot += b * a;
      }
      cout << tot << endl;
    }
}