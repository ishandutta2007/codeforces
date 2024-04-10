#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  vector <int> lp(100'001), pr;
  for (int i = 2; i <= 100'000; i++) {
    if (!lp[i]) lp[i] = i, pr.push_back(i);
    for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && pr[j] * i <= 100'000; j++)
      lp[pr[j] * i] = pr[j];
  }
  while (t--) {
    int n;
    cin >> n;
    int a = 1 + n;
    while (lp[a] != a)
      a++;
    int b = a + n;
    while (lp[b] != b)
      b++;
    cout << a * b << '\n';
  }
  return 0;
}