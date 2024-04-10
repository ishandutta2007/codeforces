#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <int> a(26), b(26);
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      a[c - 'a']++;
    }
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      b[c - 'a']++;
    }
    bool flag = true;
    for (int i = 0; i < 26; i++) {
      if (a[i] < b[i])
        flag = false;
      if ((a[i] - b[i]) % k)
        flag = false;
      if (i + 1 < 26)
        a[i + 1] += (a[i] - b[i]);
    }
    if (flag)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}