#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n;
int where[2 * N];
int ant[2 * N];
int sol[2 * N];
set<int> pluses;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<pair<int, int>> stk;
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    string s;
    cin >> s;
    if (s == "+") {
      pluses.insert(i);
    } else {
      int x;
      cin >> x;
      while (!stk.empty() && x > stk.back().first) {
        stk.pop_back();
      }
      if (stk.empty()) {
        ant[i] = 0;
      } else {
        ant[i] = stk.back().second;
      }
      stk.push_back({x, i});
      where[x] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    auto it = pluses.lower_bound(where[i] + 1);
    if (it == pluses.begin()) {
      cout << "NO\n";
      return 0;
    }
    it--;
    if (*it < ant[where[i]]) {
      cout << "NO\n";
      return 0;
    }
    sol[*it] = i;
    pluses.erase(it);
  }
  cout << "YES\n";
  for (int i = 1; i <= 2 * n; i++) {
    if (sol[i]) {
      cout << sol[i] << " ";
    }
  }
  cout << "\n";
}