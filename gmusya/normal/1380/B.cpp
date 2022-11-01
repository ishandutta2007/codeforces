#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (char c : s) {
      if (c == 'R')
        cnt0++;
      if (c == 'P')
        cnt1++;
      if (c == 'S')
        cnt2++;
    }
    char x;
    if (cnt0 >= cnt1 && cnt0 >= cnt2) {
      x = 'P';
    } else {
      if (cnt1 >= cnt2)
        x = 'S';
      else
        x = 'R';
    }
    for (char c : s)
      cout << x;
    cout << '\n';
  }
  return 0;
}