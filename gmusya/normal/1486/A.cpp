#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a[i] < i)
        flag = false;
      if (i != n - 1)
        a[i + 1] += (a[i] - i);
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}