#include <iostream>
#include <vector>
#include <algorithm>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <pii> c(n);
    for (int i = 0; i < n; i++)
      cin >> c[i].fi;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      c[u].second++;
      c[v].second++;
    }
    sort(c.begin(), c.end());
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      sum += c[i].first;
      c[i].second--;
    }
    int cnt = 0;
    vector <ll> ans;
    ans.push_back(sum);
    for (int i = n - 1; i >= 0; i--) {
      while (c[i].second) {
        c[i].second--;
        sum += c[i].first;
        ans.push_back(sum);
      }
    }
    for (auto &now : ans)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}