#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
int i, j, k;
typedef long long ll;

int main() {
  int n; cin >> n;
  int m;
  if (n == 1) {
    m = 1;
    cout << m << endl << "1 1" << endl;
  }
  else if (n == 2) {
    m = 2;
    cout << m << endl << "1 1 1 2" << endl;
  } else if (n == 3) {
    m = 2;
    cout << m << endl << "1 1 1 2 2 2" << endl;
  } else if (n == 4) {
    m = 3;
    cout << m << endl << "1 1 1 3 3 1 3 3" << endl;
  }
  else {
      m = n / 2 + 1;
      cout << m << endl;
      for (int i = 0; i < m; i++, n--) {
        cout << "1 " << i + 1 << endl;
      }
      for (int i = 0; i < n; i++) {
        cout << m << " " << i + 2 << endl;
      }
 }
  //f(m) = 2 * (m / 2 - 1)
}