#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> d(6);
  for (int i = 0; i < 6; i++) {
    cin >> d[i];
  }
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < 6; j++) {
      v.push_back({x - d[j], i});
    }
  }
  sort(v.begin(), v.end());
  vector<int> cnt(n, 0);
  int nonz = 0, j = 0, sol = (int) 2e9;
  for (int i = 0; i < 6 * n; i++) {
    cnt[v[i].second]++;
    nonz += (cnt[v[i].second] == 1);
    while (cnt[v[j].second] > 1) {
      cnt[v[j].second]--;
      j++;
    }
    if (nonz == n) {
      sol = min(sol, v[i].first - v[j].first);
    }
  }
  cout << sol << "\n";
}