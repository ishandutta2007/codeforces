#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  vector <ll> ra = a, rb = b;
  ll sum = 0, mi = 1e9;
  for (int i = 0; i < n; i++) {
    sum += (a[i] - b[i]);
    mi = min(mi, sum);
  }
  vector <bool> ans(n);
  if (mi >= 0)
    ans[0] = true;
  for (int i = 1; i < n; i++) {
    mi -= (a[i - 1] - b[i - 1]);
    if (mi >= 0)
      ans[i] = true;
  }
  a.push_back(a[0]);
  sum = 0, mi = 1e9;
  for (int i = n; i >= 1; i--) {
    sum += (a[i] - b[i - 1]);
    mi = min(mi, sum);
  }
  if (mi >= 0)
    ans[0] = true;
  for (int i = n - 1; i >= 1; i--) {
    mi -= (a[i + 1] - b[i]);
    if (mi >= 0)
      ans[i] = true;
  }
  vector <int> answer;
  for (int i = 0; i < n; i++)
    if (ans[i])
      answer.push_back(i + 1);
  cout << answer.size() << '\n';
  for (auto &now : answer)
    cout << now << ' ';
  return 0;
}