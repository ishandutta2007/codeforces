#include <iostream>
#include <set>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n - 1);
  vector <int> deg(n + 1);
  for (int i = 0; i + 1 < n; i++) {
    cin >> a[i];
    deg[a[i]]++;
  }
  set <int> s;
  for (int i = 1; i <= n; i++)
    if (!deg[i])
      s.insert(i);
  vector <pii> ans;
  for (int i = n - 2; i >= 0; i--) {
    ans.push_back({a[i], *s.begin()});
    deg[a[i]]--;
    s.erase(s.begin());
    if (!deg[a[i]])
      s.insert(a[i]);
  }
  cout << *s.begin() << '\n';
  for (auto &now : ans)
    cout << now.fi << ' ' << now.se << '\n';
  return 0;
}