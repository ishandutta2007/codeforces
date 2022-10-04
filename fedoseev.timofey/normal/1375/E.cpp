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

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  mt19937 rnd(123);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i]; 
    }
    vector <int> st = a;
    vector <vector <int>> have(n, vector <int> (n));
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[i] > a[j]) {
          --have[i][j];
        }
      }
    }
    vector <pair <int, int>> ans;
    vector <int> p(n);

    vector <int> who(n);
    vector <int> where(n);
    for (int i = 0; i < n; ++i) who[i] = i;
    for (int i = 0; i < n; ++i) where[i] = i;

    for (int i = 0; i < n; ++i) {
      int id = n - i - 1;

      vector <int> gs;
      for (int j = id - 1; j >= 0; --j) {
        if (a[j] >= a[id]) gs.push_back(j);
      }
      sort(gs.begin(), gs.end(), [&] (int f, int s) {
        return a[f] < a[s] || (a[f] == a[s] && who[f] < who[s]);
      });
      for (int i : gs) {
        if (have[i][id] < 0) {
          ans.push_back({i, id});
          ++have[i][id];
          swap(a[i], a[id]);
          swap(where[who[i]], where[who[id]]);
          swap(who[i], who[id]);
        }
      }
    }   
    bool bad = false;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (have[i][j] > 0) {
          bad = true;
        }
        if (have[i][j] < 0) {
          if (a[i] != a[j]) {
            bad = true;
          } else {
            ans.push_back({i, j});
          }
        }
      }
    }
    
    /*if (!is_sorted(a.begin(), a.end()) || bad) {
      cout << n << '\n';
      for (int i = 0; i < n; ++i) cout << st[i] << ' ';
      return 0;
    }*/
    cout << ans.size() << '\n';
    for (auto p : ans) {
      cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
  }
}