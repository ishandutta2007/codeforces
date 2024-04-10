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
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
#include <functional>
          
using namespace std;
        
typedef long long ll;
 
const int N = 82;
 
int w[N][N];
 
vector <pair <int, int>> best[N][N];
bool used[N];
 
const int Inf = 1e9 + 7;
 
int n, k;
 
vector <int> have = {0};
int ans = Inf;
 
void gen() {
  if ((int)have.size() == k / 2) {
    int cur = 0;
    for (int i = 0; i < (int)have.size(); ++i) {
      int a = have[i];
      int b = have[(i + 1) % (int)have.size()];
      int cost = Inf;
      for (auto p : best[a][b]) {
        if (!used[p.second]) {
          cost = min(cost, p.first);
          break;
        }
      }
      cur += cost;
      cur = min(cur, Inf);
    }
    ans = min(ans, cur);
  } else {
    for (int i = 0; i < n; ++i) {
      have.push_back(i);
      bool sf = used[i];
      used[i] = true;
      gen();
      have.pop_back();
      used[i] = sf;
    }
  }
} 
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> w[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int t = 0; t < n; ++t) {
        if (t == i || t == j) continue;
        best[i][j].push_back({w[i][t] + w[t][j], t});
      }
      sort(best[i][j].begin(), best[i][j].end());
      while (best[i][j].size() > 6) best[i][j].pop_back();
    }
  }
  used[0] = true;
  gen();
  cout << ans << '\n';
}