#include <bits/stdc++.h>
using namespace std;

int qnt[300];

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  for(int i = 0; i < n; i++) {
    qnt[s[i]-'A']++;
  }
  int ans = qnt[0];
  for(int i = 1; i < k; i++) {
    ans = min(ans, qnt[i]);
  }
  ans = ans * k;
  for(int i = k; i < 26; i++) ans += qnt[i];
  cout << ans << endl;
  return 0;
}