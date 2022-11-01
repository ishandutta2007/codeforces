#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int cnt0a = 0, cnt1a = 0, cnt0b = 0, cnt1b = 0;
  int n = (int) s.size();
  ll odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      if (s[i] == 'a') {
        cnt1a++;
        odd += cnt1a;
        even += cnt0a;
      } else {
        cnt1b++;
        odd += cnt1b;
        even += cnt0b;
      }
    } else {
      if (s[i] == 'a') {
        cnt0a++;
        odd += cnt0a;
        even += cnt1a;
      } else {
        cnt0b++;
        odd += cnt0b;
        even += cnt1b;
      }
    }
  }
  cout << even << ' ' << odd;
  return 0;
}