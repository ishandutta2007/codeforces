#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> p(n);
  int pos = -1;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (p[i] == m)
      pos = i;
  }
  map <int, int> left, right;
  for (int i = 0; i < n; i++) {
    if (p[i] < m)
      p[i] = -1;
    else if (p[i] == m)
      p[i] = 0;
    else p[i] = 1;
  }
  int s = 0;
  for (int i = pos; i >= 0; i--) {
    s += p[i];
    left[s]++;
  }
  s = 0;
  for (int i = pos; i < n; i++) {
    s += p[i];
    right[s]++;
  }
  long long ans = 0;
  for (auto [val, cnt] : left) {
    if (right.find(-val) != right.end())
      ans += cnt * 1ll * right[-val];
    if (right.find(-val + 1) != right.end())
      ans += cnt * 1ll * right[-val + 1];
  }
  cout << ans;
  return 0;
}