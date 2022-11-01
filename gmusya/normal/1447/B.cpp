#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int>(m));
    int neg = 0;
    int sum = 0;
    int mi = 1e9;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        neg += (a[i][j] < 0);
        if (abs(a[i][j]) < mi)
          mi = abs(a[i][j]);
        sum += abs(a[i][j]);
      }
    if (neg % 2)
      sum -= 2 * mi;
    cout << sum << '\n';
  }
  return 0;
}