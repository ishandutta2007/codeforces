#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  vector <vector <int>> c(n, vector <int> (n, -1));
  vector <vector <int>> gr;
  for (int i = 0; i < n; ++i) {
    gr.push_back({i});
  }
  int cnt = 0;
  while ((int)gr.size() > 1) {
    ++cnt;
    vector <vector <int>> ngr;
    for (int i = 0; i < (int)gr.size(); i += k) {
      vector <int> cur;
      for (int j = i; j < min((int)gr.size(), i + k); ++j) {
        for (auto v : gr[j]) {
          cur.push_back(v);
        }
      }
      for (auto u : cur) {
        for (auto v : cur) {
          if (u < v && c[u][v] == -1) {
            c[u][v] = cnt;
          }
        }
      }
      ngr.push_back(cur);
    }
    gr = ngr;
  }
  cout << cnt << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cout << c[i][j] << ' ';
    }
  } 
}