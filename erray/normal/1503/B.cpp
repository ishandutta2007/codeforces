// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  array<vector<pair<int, int>>, 2> add;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      add[(i + j) % 2].emplace_back(i, j);  
    }
  }
  int move_c = n * n;
  while (move_c--) {
    auto Add = [&](int from, int col) {
      assert(add[from].size());
      auto[x, y] = add[from].back();
      add[from].pop_back(); 
      cout << col << ' ' << x + 1 << ' ' << y + 1 << endl;
    };
    
    int col;
    cin >> col;
    if (col == 1) {
      if (add[1].empty()) {
        Add(0, 3);  
      } else {
        Add(1, 2);
      }
    } else if (col == 2) {
      if (add[0].empty()) {
        Add(1, 3);
      } else {
        Add(0, 1);
      }
    } else {
      if (add[0].empty()) {
        Add(1, 2);
      } else {
        Add(0, 1);
      }      
    }
  }
}