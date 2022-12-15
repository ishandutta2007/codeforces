#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int ms = 4e5+5;

int a[ms];
int sc1[ms], sc2[ms];
vector<int> go;
int n;

void solve(int *sc) {
  stack<ii> s;
  int cur = 0;
  s.push({0, 0});
  for(int i = 0; i < n-1; i++) {
    sc[i] = cur;
    // if(i > 0) cout << "SC de " << i << "(" << go[i-1] << ") " << " = " << cur << endl;
    int h = 0;
    while(s.top().first > go[i]) {
      h = max(h+1, s.top().second);
      s.pop();
    }
    cur = max(cur, h + (int) (s.size()));
    s.push({go[i], h+1});
  }
  // cout << "SC de " << n-1 << "(" << go[n-2] << ") " << " = " << cur << endl;
  sc[n-1] = cur;
}

main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int p = 0-1;
  for(int i = 0; i < n; i++) {
    if(a[i] == 1) p = i;
  }
  int i = p;
  for(int j = (i+1)%n; j != i; j = (j+1)%n) {
    go.push_back(a[j]);
  }
  solve(sc1);
  reverse(go.begin(), go.end());
  solve(sc2);
  int ans = 0x3f3f3f3f;
  int best = -1;
  for(int i = 0; i <= n-1; i++) {
    int cur = 1 + max(sc1[i], sc2[n-1-i]);
    if(cur < ans) {
      ans = cur;
      best = i;
    }
  }
  int shifts = (1 + i + best) % n;
  cout << ans << ' ' << shifts << endl;
}