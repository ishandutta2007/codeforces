#include <iostream>
#include <vector>

using namespace std;

typedef pair <int, int> pii;

int main() {
  int n;
  cin >> n;
  vector <int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  vector <int> pos(n);
  for (int i = 0; i < n; i++)
    pos[p[i]] = i;
  vector <pii> ans;
  for (int i = 0; i < n; i++) {
    int left = pos[i];
    int right = i;
    swap(pos[p[left]], pos[p[right]]);
    swap(p[left], p[right]);
    left++, right++;
    if (left == right)
      continue;
    if (2 * abs(left - right) >= n) {
      ans.push_back({left, right});
      continue;
    }
    if (left > right)
      swap(left, right);
    if (left <= n / 2 && right > n / 2) {
      if (1 != right)
        ans.push_back({1, right});
      if (left != n)
        ans.push_back({left, n});
      ans.push_back({1, n});
      if (1 != right)
        ans.push_back({1, right});
      if (left != n)
        ans.push_back({left, n});
      continue;
    }
    if (right <= n / 2) {
      ans.push_back({left, n});
      ans.push_back({right, n});
      ans.push_back({left, n});
    } else {
      ans.push_back({1, left});
      ans.push_back({1, right});
      ans.push_back({1, left});
    }
  }
  cout << ans.size() << '\n';
  for (auto [a, b] : ans)
    cout << a << ' ' << b << '\n';
  return 0;
}