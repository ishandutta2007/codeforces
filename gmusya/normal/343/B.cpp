#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if ((i % 2) ^ (s[i] == '-'))
      cnt0++;
    else
      cnt1++;
  }
  if (cnt0 == cnt1)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}