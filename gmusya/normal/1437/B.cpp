#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans0 = 0, ans1 = 0;
    for (int i = 0; i + 1 < n; i++) {
      if (s[i] == '0' && s[i + 1] == '0')
        ans0++;
      if (s[i] == '1' && s[i + 1] == '1')
        ans1++;
    }
    cout << max(ans0, ans1) << '\n';
  }
  return 0;
}