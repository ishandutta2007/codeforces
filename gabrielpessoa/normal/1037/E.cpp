#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

const int ms = 2e5+5;
const ll mod = 1e9+7;

int n, m, k;
queue<int> remover;
int w[ms];
pair<int, int> e[ms];
set<int> g[ms];
int ans[ms];
int existe[ms];

int main() {
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++) {
    cin >> e[i].first >> e[i].second;
    g[e[i].first].insert(e[i].second);
    g[e[i].second].insert(e[i].first);
    w[e[i].first]++; w[e[i].second]++;
  }
  int cur = n;
  for(int i = 1; i <= n; i++) {
    existe[i] = true;
    if(w[i] < k) {
      existe[i] = false;
      remover.push(i);
      cur--;
    }
  }
  for(int i = m; i >= 1; i--) {
    while(!remover.empty()) {
      int u = remover.front();
      remover.pop();
      for(int v : g[u]) {
        if(existe[v]) {
          w[v]--;
          if(w[v] < k) {
            existe[v] = false;
            cur--;
            remover.push(v);
          }
        }
      }
    }
    ans[i] = cur;
    if(existe[e[i].first] && existe[e[i].second]) {
      w[e[i].first]--; w[e[i].second]--;
      g[e[i].first].erase(e[i].second);
      g[e[i].second].erase(e[i].first);
      //cout << "Dia " << i << " foi removido o " << e[i].first << ' ' << e[i].second << endl;
      if(w[e[i].first] < k) {
        cur--;
        existe[e[i].first] = false;
        remover.push(e[i].first);
        //cout << e[i].first << " foi-se\n";
      }
      if(w[e[i].second] < k) {
        cur--;
        existe[e[i].second] = false;
        remover.push(e[i].second);
       // cout << e[i].second << " foi-se\n";
      }
    }
  }
  for(int i = 1; i <= m; i++) {
    cout << ans[i] << '\n';
  }
}