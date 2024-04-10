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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(n, -1);
    vector <int> used(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      if (!used[a[i]]) {
        used[a[i]] = 1;
        b[i] = a[i];
        ++ans;
      }
    }
    vector <int> have;
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        have.push_back(i);
      }
    }
    int pos1 = -1, pos2 = -1;
    for (int i = 0; i < n; ++i) {
      if (b[i] == -1) {
        b[i] = have.back();
        have.pop_back();
        if (pos1 == -1) {
          pos1 = i;
        } else if (pos2 == -1) {
          pos2 = i;
        }
      }
    }
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      if (b[i] == i) {
        bad = true;
      }
    }
    if (bad && pos2 == -1) {
      //for (int i = 0; i < n; ++i) cout << b[i] + 1 << ' ';
      //cout << endl;
      int id = -1;
      for (int i = 0; i < n; ++i) if (b[i] == i) id = i;
      //cout << id + 1 << ' ' << a[id] << endl;
      int who = -1;
      for (int i = 0; i < n; ++i) {
        if (b[i] == a[id]) {
          who = i;
        }
      }
      //cout << id + 1 << ' ' << who + 1 << ' ' << endl;
      b[who] = id;
      b[id] = a[id];
    } else {
      for (int i = 0; i < n; ++i) {
        if (b[i] == i) {
          assert(pos1 != -1);
          if (pos1 != i) {
            swap(b[i], b[pos1]);
          } else {
            assert(pos2 != -1);
            swap(b[i], b[pos2]);
          }
        }
      } 
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
      cout << b[i] + 1 << ' ';
    }
    cout << '\n';
  }
}