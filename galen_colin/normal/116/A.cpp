#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;

    int maxcap = 0, cur = 0;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      cur -= a;
      cur += b;
      maxcap = max(maxcap, cur);
    }

    cout << maxcap << endl;
}