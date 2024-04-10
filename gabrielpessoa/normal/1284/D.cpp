#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
typedef pair<int, int> ii;
 
const int ms = 2e6+5;
const int inf = 1e18;
const int mod = 998244353;
const int qnt = 10;

vector<pair<int, int>> v[2];

int h[ms][qnt];
// mt19937_64 se LL
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> get(int x) {
  sort(v[x].begin(), v[x].end());
  vector<int> curH(qnt, 0);
  vector<int> act(qnt, 0);
  for(auto e : v[x]) {
    for(int i = 0; i < qnt; i++) {
      if (e.second < 0) {
        curH[i] += h[-e.second][i] * act[i];
        act[i] += h[-e.second][i];
      } else {
        act[i] -= h[e.second][i];
      }
    }
  }
  return curH;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int cur = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < qnt; j++) {
      h[i][j] = rng();
    }
    for(int j = 0; j < 2; j++) {
      int s, e;
      cin >> s >> e;
      v[j].emplace_back(s, -i);
      v[j].emplace_back(e, i);
    }
  }
  if(get(0) == get(1)) cout << "YES\n";
  else cout << "NO\n";
}