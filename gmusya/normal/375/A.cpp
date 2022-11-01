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
  int n = (int) s.size();
  vector <int> cnt(10);
  for (int i = 0; i < n; i++)
    cnt[s[i] - '0']++;
  vector <int> p10(n + 1);
  p10[0] = 1;
  for (int i = 1; i <= n; i++)
    p10[i] = p10[i - 1] * 10 % 7;
  cnt[1]--, cnt[6]--, cnt[8]--, cnt[9]--;
  int res = 0, pos = n - 1;
  for (int i = 1; i <= 9; i++) {
    while (cnt[i]--) {
      cout << i;
      res = (res + p10[pos] * i) % 7;
      pos--;
    }
  }
  vector <int> p = {1, 6, 8, 9};
  do {
    if ((res + p10[pos] * p[0] + p10[pos - 1] * p[1] + p10[pos - 2] * p[2] + p10[pos - 3] * p[3]) % 7 == 0)
      break;
  } while (next_permutation(p.begin(), p.end()));
  for (auto &now : p)
    cout << now;
  while (cnt[0]--)
    cout << 0;
  return 0;
}