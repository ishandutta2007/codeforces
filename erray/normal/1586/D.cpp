// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Ask = [&](vector<int> a) {
    cout << "? ";
    for (auto e : a) {
      cout << e + 1 << ' ';
    }
    cout << endl;
    int res;
    cin >> res;
    --res;
    return res;
  };

  int lst = n;
  vector<int> p(n, -1);
  for (int i = n - 1; i >= 0; --i) {
    if (p[i] == -1) {
      int j = 1;
      vector<pair<int, int>> add;
      while (j < n) {
        vector<int> ask(n);
        ask[i] = j;
        int x = Ask(ask);
        if (x == -1 || x == i || p[x] != -1) {
          break;
        }
        add.emplace_back(x, j);
        ++j;
      }
      add.emplace_back(i, 0);
      lst -= j;
      for (auto[x, y] : add) {
        p[x] = lst + y;
      }
    }
  }

  cout << "! ";
  for (auto e : p) {
    cout << e + 1 << ' ';
  }
  cout << endl;
}