#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

string s;
int pref[1000006];

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  for (int i = 1; i < s.size(); ++i) {
    if (i > 0) pref[i] = pref[i - 1];
    if (s[i] == 'v' && (i > 0 && s[i - 1] == 'v')) pref[i]++;
  }

  long long ans = 0;

  int suf = 0;
  for (int i = s.size() - 2; i >= 0; --i) {
    if (s[i] == 'v' && (i + 1 < s.size() && s[i + 1] == 'v')) ++suf;
    if (s[i] == 'o') ans += 1LL * suf * pref[i];
  }
  cout << ans << endl;
  return 0;
}