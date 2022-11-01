#include <iostream>

using namespace std;

int len(int x) {
  int cnt = 0;
  while (x) {
    cnt++;
    x /= 10;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << a * 1ll * (len(b + 1) - 1) << '\n';
  }
  return 0;
}