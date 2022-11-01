#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, v;
  cin >> n >> v;
  vector <pair <int, int>> a, b;
  for (int i = 0; i < n; i++) {
    int type, p;
    cin >> type >> p;
    if (type == 1)
      a.push_back({p, i});
    else
      b.push_back({p, i});
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  int asz = a.size(), bsz = b.size();
  vector <int> prea(asz), preb(bsz);
  if (asz)
    prea[0] = a[0].first;
  for (int i = 1; i < asz; i++)
    prea[i] = prea[i - 1] + a[i].first;
  if (bsz)
    preb[0] = b[0].first;
  for (int i = 1; i < bsz; i++)
    preb[i] = preb[i - 1] + b[i].first;
  pair <int, pair <int, int>> ans = {-1, {-1, -1}};
  for (int i = 0; i <= min(asz, v); i++) {
    int j = min((v - i) / 2, bsz);
    int sum = (i ? prea[i - 1] : 0) + (j ? preb[j - 1] : 0);
    ans = max(ans, {sum, {i, j}});
  }
  cout << ans.first << '\n';
  for (int i = 0; i < ans.second.first; i++)
    cout << a[i].second + 1 << ' ';
  for (int i = 0; i < ans.second.second; i++)
    cout << b[i].second + 1 << ' ';
  return 0;
}