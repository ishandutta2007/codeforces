#include <bits/stdc++.h>

using namespace std;

map <pair <int, int>, int> qr;

int ask(int i, int j) {
  if (i > j) swap(i, j);
  if (qr.count({i, j})) return qr[{i, j}];
  cout << "? " << i + 1 << ' ' << j + 1 << endl;
  char c;
  cin >> c;
  if (c == '<') qr[{i, j}] = i;
  else qr[{i, j}] = j;
  return qr[{i, j}];
}

void solve() {
  qr.clear();
  int n;
  cin >> n;
  set <int> a, b, c;
  for (int i = 0; i < n - 1; ++i) a.insert(i);
  for (int i = 0; i < 2; ++i) b.insert(n - 1 + i);
  for (int i = 0; i < n - 1; ++i) c.insert(2 * n - 1 - i);
  int cnt = 0;
  while (cnt < n) {
    int id1 = *a.begin(), id2 = *b.begin();
    for (int i : a) {
      if (id1 == i) continue;
      if (ask(id1, i) == i) id1 = i;
    }
    for (int i : b) {
      if (id2 == i) continue;
      if (ask(id2, i) == i) id2 = i;
    }
    if (ask(id1, id2) == id2) {
      b.erase(id2);
      if (!c.empty()) {
        b.insert(*c.begin());
        c.erase(c.begin());
      } 
    } else {
      a.erase(id1);
      if (!c.empty()) {
        a.insert(*c.begin());
        c.erase(c.begin());
      }
    }
    ++cnt;
  }
  cout << "!" << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  //freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}