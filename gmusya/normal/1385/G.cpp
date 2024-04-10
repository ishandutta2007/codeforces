#include <iostream>
#include <vector>

using namespace std;

int cnt0, cnt1, timer;

void dfs (int v, vector <int> &colour, vector <int> &comp, vector <vector <pair <int, int>>> &g) {
  if (colour[v] == 0)
    cnt0++;
  else
    cnt1++;
  comp[v] = timer;
  for (auto &now : g[v])
    if (colour[now.first] == -1) {
      colour[now.first] = (colour[v] ^ now.second);
      dfs(now.first, colour, comp, g);
    }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    timer = 0;
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      b[i]--;
    }
    vector <int> cnt(n);
    for (int i = 0; i < n; i++)
      cnt[a[i]]++, cnt[b[i]]++;
    bool tf = true;
    for (int i = 0; i < n; i++)
      if (cnt[i] != 2)
        tf = false;
    if (!tf) {
      cout << -1 << '\n';
      continue;
    }
    vector <int> pos1(n, -1), pos2(n, -1);
    for (int i = 0; i < n; i++) {
      if (pos1[a[i]] == -1)
        pos1[a[i]] = i;
      else
        pos2[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
      if (pos1[b[i]] == -1)
        pos1[b[i]] = i;
      else
        pos2[b[i]] = i;
    }
    vector <vector <pair <int, int>>> g(n);
    for (int i = 0; i < n; i++) {
      if (pos1[i] == pos2[i]) continue;
      int ina_1 = (a[pos1[i]] != i), ina_2 = (a[pos2[i]] != i);
      g[pos1[i]].push_back({pos2[i], ina_1 == ina_2});
      g[pos2[i]].push_back({pos1[i], ina_1 == ina_2});
    }
    vector <int> colour(n, -1), comp(n, -1);
    int ans = 0;
    vector <bool> arr;
    for (int i = 0; i < n; i++)
      if (colour[i] == -1) {
        cnt0 = cnt1 = 0;
        colour[i] = 0;
        dfs(i, colour, comp, g);
        timer++;
        ans += min(cnt0, cnt1);
        arr.push_back((bool)(cnt0 < cnt1));
      }
    for (int i = 0; i < n; i++)
      for (auto &now : g[i])
        if (colour[i] != (colour[now.first] ^ now.second))
          tf = false;
    if (!tf) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++)
      if (arr[comp[i]] ^ colour[i])
        cout << i + 1 << ' ';
    cout << '\n';
  }
  return 0;
}