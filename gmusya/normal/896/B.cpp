#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector <int> a(n, -1);
  int cnt = 0;
  while (true) {
    if (cnt == n)
      break;
    int x;
    cin >> x;
    int pos = -1;
    if (2 * x <= c) {
      for (int j = 0; j < n; j++) {
        if (a[j] == -1) {
          cnt++;
          a[j] = x;
          pos = j;
          break;
        }
        if (a[j] > x) {
          a[j] = x;
          pos = j;
          break;
        }
      }
      cout << pos + 1 << endl;
      continue;
    }
    for (int j = n - 1; j >= 0; j--) {
      if (a[j] == -1) {
        cnt++;
        a[j] = x;
        pos = j;
        break;
      }
      if (a[j] < x) {
        a[j] = x;
        pos = j;
        break;
      }
    }
    cout << pos + 1 << endl;
  }
  return 0;
}