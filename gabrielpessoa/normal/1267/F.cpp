#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int ms = 4e5+5;

int app[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m, ka, kb;
  cin >> n >> m >> ka >> kb;
  vector<int> a(ka), b(kb);
  if(ka + 1 > m || kb + 1 > n) {
    cout << "No\n";
    return 0;
  }
  for(int i = 0; i < ka; i++) cin >> a[i];
  for(int i = 0; i < kb; i++) cin >> b[i];
  for(int i = ka; i < m-1; i++) {
    a.push_back(a[ka-1]);
  }
  for(int i = kb; i < n-1; i++) {
    b.push_back(b[kb-1]);
  }
  cout << "Yes\n";
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  priority_queue<int, vector<int>, greater<int>> q;
  for(int x : a) app[x]++;
  for(int x : b) app[x]++;
  for(int i = 1; i <= n+m; i++) if(app[i] == 0) q.push(i);
  int cur = 0;
  while(cur < (n+m-2)) {
    int x = q.top();
    q.pop();
    int y;
    if(x <= n) {
      y = b[b.size()-1];
      b.pop_back();
    } else {
      y = a[a.size()-1];
      a.pop_back();
    }
    cout << x << ' ' << y << '\n';
    if(!--app[y]) q.push(y);
    cur++;
  }
  int x = q.top();
  q.pop();
  int y = q.top();
  cout << x << ' ' << y << endl;
}