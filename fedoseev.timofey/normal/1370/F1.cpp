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
  //freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <vector <int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    map <vector <int>, pair <int, int>> mem;
    auto ask = [&] (vector <int> a) {
      sort(a.begin(), a.end());
      if (!mem.count(a)) {
        cout << "? " << a.size() << ' ';
        for (int x : a) cout << x + 1 << ' ';
        cout << endl;
        int x, d;
        cin >> x >> d;
        --x;
        mem[a] = {x, d};
      }
      return mem[a];
    };  
    int r = -1, d = -1;
    {
      vector <int> a;
      for (int i = 0; i < n; ++i) {
        a.push_back(i);
      }
      auto pr = ask(a);
      r = pr.first, d = pr.second;
    } 
    vector <int> h(n);
    vector <int> par(n, -1);
    function <void(int, int)> dfs = [&] (int u, int p) {
      par[u] = p;
      for (auto v : g[u]) {
        if (v != p) {
          h[v] = h[u] + 1;
          dfs(v, u);
        }
      }
    };
    dfs(r, -1);
    int id = 0;
    for (int i = 0; i < n; ++i) {
      if (h[i] > h[id]) id = i;
    }
    vector <int> bad(n);
    /*{
      int cur = id;
      while (cur != -1) {
        bad[cur] = 1;
        cur = par[cur];
      }
    }*/
    vector <vector <int>> who(n);
    for (int i = 0; i < n; ++i) {
      if (!bad[i]) {
        who[h[i]].push_back(i);
      }
    }
    int lst = -1;
    for (int i = 0; i < n; ++i) {
      if (!who[i].empty()) {
        lst = i;
      }
    }
    int L = 0, R = lst + 1;
    while (R - L > 1) {
      int M = (L + R) >> 1;
      auto cur = ask(who[M]);
      if (cur.second == d) {
        L = M;
      } else {
        R = M;
      }
    } 
    int first_guy = -1;
    if (L == 0) {
      first_guy = r;
    } else {
      first_guy = ask(who[L]).first;
    }
    int h_second = d - h[first_guy];
    { 
      for (int i = 0; i < n; ++i) {
        who[i].clear();
        bad[i] = 0;
      }
      int cur = first_guy;
      while (cur != -1) {
        bad[cur] = 1;
        cur = par[cur];
      }
    }
    for (int i = 0; i < n; ++i) {
      if (!bad[i]) {
        who[h[i]].push_back(i);
      }
    }
    int second_guy = -1;
    if (h_second > 0) second_guy = ask(who[h_second]).first;
    else second_guy = r;
    cout << "! " << first_guy + 1 << ' ' << second_guy + 1 << endl;
    string res;
    cin >> res;
    if (res == "Incorrect") {
      exit(0);
    }
  }
}