#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair <int, int> pii;
typedef vector <int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vi w(n);
  for (int i = 0; i < n; i++)
    cin >> w[i];
  vi x(m), y(m);
  vector<set<int>> deg(n);
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
    deg[x[i]].insert(i);
    deg[y[i]].insert(i);
  }
  set<pii> s;
  for (int i = 0; i < n; i++)
    s.insert({deg[i].size() - w[i], i});
  vi ans;
  while (!s.empty()) {
    pii cur = *s.begin();
    s.erase(s.begin());
    if (cur.first > 0) {
      cout << "DEAD\n";
      return 0;
    }
    int id = cur.second;
    vi arr;
    for (int tmp : deg[id]) {
      ans.push_back(tmp);
      arr.push_back(tmp);
    }
    for (int i : arr) {
      int val = (id == x[i] ? y[i] : x[i]);
      s.erase({deg[val].size() - w[val], val});
      deg[val].erase(i);
      s.insert({deg[val].size() - w[val], val});
    }
  }
  reverse(ans.begin(), ans.end());
  cout << "ALIVE\n";
  for (int tmp : ans)
    cout << tmp + 1 << ' ';
  return 0;
}