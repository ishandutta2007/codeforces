#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    a.push_back(a[0]);
    bool flag1 = true, flag2 = true;
    for (int i = 0; i < n; i++) {
      if ((a[i] + 1) % n != a[i + 1] % n)
        flag1 = false;
      if (a[i] % n != (a[i + 1] + 1) % n)
        flag2 = false;
    }
    if (!flag1 && !flag2)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}