#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
  return (a.first + a.second) > (b.first + b.second);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  multiset <pair <int, int>> pos;
  vector <pair <int, int>> neg;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (b >= 0)
      pos.insert({a, b});
    else
      neg.push_back({a, b});
  }
  int ans = 0;
  for (auto &now : pos) {
    if (now.first <= r) {
      r += now.second;
      ans++;
    }
  }
  vector <int> dp(r + 1);
  sort(neg.begin(), neg.end(), cmp);
  dp[r] = ans;
  for (int i = 0; i < neg.size(); i++) {
    vector <int> newdp = dp;
    for (int j = neg[i].first; j <= r; j++)
      if (j + neg[i].second >= 0)
        newdp[j + neg[i].second] = max(newdp[j + neg[i].second], dp[j] + 1);
    swap(newdp, dp);
  }
  int answer = 0;
  for (int i = 0; i <= r; i++)
    answer = max(answer, dp[i]);
  if (answer == n)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}