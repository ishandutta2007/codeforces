#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n;
int where[N];
int sol[N];
int acum;
int rl[N];
set<int> lib;
vector<vector<int>> spo;

void check(bool ok) {
  if (!ok) {
    cout << "NO\n";
    exit(0);
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ooo = 0;
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    string s;
    cin >> s;
    if (s == "+") {
      lib.insert(i);
      spo.push_back({1});
      rl[i] = ++ooo;
    } else {
      int value;
      cin >> value;
      where[value] = i;
      spo.push_back({-1, value});
    }
  }
  for (int i = 1; i <= n; i++) {
    auto it = lib.lower_bound(where[i] + 1);
    check(it != lib.begin());
    it--;
    sol[rl[*it]] = i;
    lib.erase(it);
  }
  set<int> cur;
  for (auto &v : spo) {
    if ((int) v.size() == 1) {
      cur.insert(sol[++acum]);
    } else {
      check(!cur.empty());
      check(v[1] == *cur.begin());
      cur.erase(v[1]);
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << sol[i] << " ";
  }
  cout << "\n";

}