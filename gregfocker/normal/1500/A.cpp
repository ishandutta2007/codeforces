#include <bits/stdc++.h>

using namespace std;

mt19937 rng((long long) (new char));
const int N = (int) 2e5 + 7;
const int E = (int) 5e6 + 7;
int n;
pair<int, int> a[N];
vector<pair<int, int>> who[E];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ///freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  shuffle(a + 1, a + n + 1, rng);
  n = min(n, 10000);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int sum = a[i].first + a[j].first;
      for (auto &it : who[sum]) {
        if (it.first != i && it.first != j && it.second != i && it.second != j) {
          cout << "YES\n";
          cout << a[i].second << " " << a[j].second << " " << a[it.first].second << " " << a[it.second].second << "\n";
          return 0;
        }
      }
      who[sum].push_back({i, j});
    }
  }
  cout << "NO\n";
}