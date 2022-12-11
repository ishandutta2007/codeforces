#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
 
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;

 
int n, x, y;
int a[100007];
int b[100007];
vector<int> pos[100007];
set<pair<int, int>> se;
int fre;
int free_c;
int stp = 0;
 
int get(int c) {
  if (se.size() == 0) {
    while(1){}
    assert(0);
  }
  //assert(se.size() >= 1);
  auto now = *(--se.end());
  if (now.y == c) {
    if (se.size() < 2) {
      if (fre > 0) {
        --fre;
        return free_c;
      }
    }
    if (se.size() < 2) {
      stp = 1;
      return -1;
    }
    //assert(se.size() >= 2);
    now = *(--(--se.end()));
    se.erase(--(--se.end()));
    if (now.x > 1)
    se.insert({now.x - 1, now.y});
    return now.y;
  } else {
    se.erase(--se.end());
    if (now.x > 1)
    se.insert({now.x - 1, now.y});
    return now.y;
  }
}
 
int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int tt;
  cin >> tt;
  while (tt--) {
    for (int i = 0; i <= n + 1; ++i) pos[i].clear();
    stp = 0;
    se.clear();
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) cin >> a[i], pos[a[i]].pb(i), b[i] = -1;
    for (int i = 0; i < n; ++i) se.insert({pos[a[i]].size(), a[i]});
 
    fre = n - y;
    //int now = ma - fre;
 
    free_c = -1;
    for (int i = 1; i <= n + 1; ++i) if (pos[i].size() == 0) free_c = i;
    assert(free_c != -1);
 
    for (int i = 0; i < x; ++i) {
      auto now = *(--se.end());
      b[pos[now.y].back()] = now.y;
      pos[now.y].pop_back();
      se.erase(--se.end());
      if (now.x > 1)
      se.insert({now.x - 1, now.y});
    }

    int ma = 0;
    vector<int> tt;
    vector<int> ff;
    for (int i = 0; i <= n + 1; ++i) {
      for (auto c : pos[i]) tt.pb(c); //, cout << i << ' ' << c << endl;
      ma = max(ma, (int)pos[i].size());
    }
    ff = tt;

    rotate(tt.begin(), tt.begin() + ma, tt.end());

    for (int i = 0; i < tt.size(); ++i) {
      b[tt[i]] = a[ff[i]];
      if (a[tt[i]] == a[ff[i]]) {
        b[tt[i]] = free_c;
        --fre;
      }
    }

    for (int i = 0; i <= n + 1; ++i) pos[i].clear();

    if (stp || fre < 0) {
      cout << "NO\n";
      continue;
    }

    for (int i = 0; i < tt.size(); ++i) {
      if (b[tt[i]] != free_c && fre > 0) {
        --fre;
        b[tt[i]] = free_c;
      }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      cout << b[i] << ' ';
    }
    cout << "\n";
    
  }
}