#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector <char> left, right;
  int l = 0, r = (int) s.size() - 1;
  while (l < r) {
    if (s[l] == s[r]) {
      left.push_back(s[l]);
      right.push_back(s[r]);
      l++, r--;
      continue;
    }
    if (s[l + 1] == s[r]) {
      l++;
      continue;
    }
    if (s[l] == s[r - 1]) {
      r--;
      continue;
    }
    l++, r--;
  }
  if (l == r)
    left.push_back(s[l]);
  reverse(right.begin(), right.end());
  for (char c : left)
    cout << c;
  for (char c : right)
    cout << c;
  return 0;
}