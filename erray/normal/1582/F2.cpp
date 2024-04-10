// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  int MAX = *max_element(a.begin(), a.end());
  MAX = 1 << (__lg(MAX) + 1);
  vector<int> first(MAX, MAX - 1);
  vector<vector<int>> push(MAX);
  vector<vector<bool>> can(MAX, vector<bool>(MAX));
  for (int i = 0; i < MAX; ++i) {
    push[i].push_back(i);
    can[i][i] = true;
  }

  debug(MAX);
  first[0] = -1;
  for (int i = 0; i < n; ++i) {
    int x = a[i];    
    for (auto e : push[x]) {
      while (first[e] > x) {
        int add = first[e];
        if (!can[add][e ^ add]) {
          push[add].push_back(e ^ add);
          can[add][e ^ add] = true;
        }
        --first[e];  
      }
    }
    push[x].clear();
  }



  cout << MAX - count(first.begin(), first.end(), MAX - 1) << '\n';
  for (int i = 0; i < MAX; ++i) {
    if (first[i] != MAX - 1) {
      cout << i << ' ';
    }
  }
}