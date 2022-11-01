#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair <int, int> pii;

bool flag = false;

void solve(string s) {
  int sum = 0;
  for (char c : s)
    sum += c - '0';
  for (char c : s)
    if (c == '0')
      flag = true;
  int n = s.size();
  if (n == 0) {
    if (flag)
      cout << 0;
    else
      cout << -1;
    exit(0);
  }
  if (sum % 3 == 0) {
    cout << s;
    exit(0);
  }
  if (n == 1) {
    if (flag)
      cout << 0;
    else
      cout << -1;
    exit(0);
  }
  pii ans = {n + 1, 0};
  for (int i = 0; i < n; i++)
    if ((sum - (s[i] - '0')) % 3 == 0 && (i || s[i + 1] != '0' || n == 2)) {
      for (int j = 0; j < i; j++)
        cout << s[j];
      for (int j = i + 1; j < n; j++)
        cout << s[j];
      exit(0);
    }
  vector <int> ids;
  for (int i = 1; i < n; i++)
    if ((s[i] - '0') % 3)
      ids.push_back(i);
  if (ids.size() >= 2) {
    for (int i = 0; i < ids[0]; i++)
      cout << s[i];
    for (int i = ids[0] + 1; i < ids[1]; i++)
      cout << s[i];
    for (int i = ids[1] + 1; i < n; i++)
      cout << s[i];
    exit(0);
  }
  string t;
  int it = 1;
  while (it < n && s[it] == '0')
    it++;
  while (it < n)
    t += s[it++];
  solve(t);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  solve(s);
  return 0;
}