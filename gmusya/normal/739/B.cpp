#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <ll> p(n), w(n);
  for (int i = 1; i < n; i++) {
    cin >> p[i] >> w[i];
    p[i]--;
  }
  vector <int> lg(n + 1);
  for (int i = 2; i <= n; i++)
    lg[i] = lg[i / 2] + 1;
  vector <vector <ll>> binup(lg[n] + 1, vector <ll>(n));
  vector <vector <ll>> bindis(lg[n] + 1, vector <ll>(n));
  for (int i = 0; i < n; i++) {
    binup[0][i] = p[i];
    bindis[0][i] = w[i];
  }
  for (int pow = 1; pow <= lg[n]; pow++)
    for (int i = 0; i < n; i++) {
      binup[pow][i] = binup[pow - 1][binup[pow - 1][i]];
      bindis[pow][i] = bindis[pow - 1][i] + bindis[pow - 1][binup[pow - 1][i]];
    }
  vector <ll> add(n);
  for (int i = 0; i < n; i++) {
    ll v = i;
    for (int j = lg[n]; j >= 0; j--)
      if (bindis[j][v] <= a[i]) {
        a[i] -= bindis[j][v];
        v = binup[j][v];
      }
    add[i]++;
    if (p[v] != v) add[p[v]]--;
  }
  vector <int> deg(n);
  for (int i = 1; i < n; i++)
    deg[p[i]]++;
  queue <int> q;
  for (int i = 0; i < n; i++)
    if (!deg[i])
      q.push(i);
  vector <bool> used(n);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (p[v] == v) continue;
    add[p[v]] += add[v];
    deg[p[v]]--;
    if (!deg[p[v]])
      q.push(p[v]);
  }
  for (auto &now : add)
    cout << now - 1 << ' ';
  return 0;
}