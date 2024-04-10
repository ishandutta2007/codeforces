#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = 0, boys = 0;
  for (char c : s) {
    if (c == 'M')
      boys++;
    else
      if (boys > 0)
        ans = max(ans + 1, boys);
  }
  cout << ans;
  return 0;
}