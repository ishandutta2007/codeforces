#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (auto& s : a) {
    cin >> s;
  }
  for (auto& s : b) {
    cin >> s;
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    --x;
    cout << a[x % n] << b[x % m] << '\n';
  }
  return 0;
}