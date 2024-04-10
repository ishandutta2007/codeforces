#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
int i, j, k;
typedef long long ll;

int main() {
  int x, y, z; cin >> x >> y >> z;
  if (z >= abs(x - y) && z) cout << "?";
  else {
    if (x > y) cout << "+";
    else if (x == y) cout << "0";
    else cout << "-";
  }
  cout << endl;
}