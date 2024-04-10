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
  int n;
  cin >> n;
  vector <int> nxt(n, -1);
  auto ask = [&] (vector <int> a) {
    cout << "? ";
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << endl;
    int id;
    cin >> id;
    --id;
    return id;
  };
  for (int i = n - 1; i > 0; --i) {
    vector <int> a(n, 2);
    a[i] = 1;
    int id = ask(a);
    if (id != -1 && id < i) {
      nxt[id] = i;
    }
    a.assign(n, 1);
    a[i] = 2;
    id = ask(a);
    if (id != -1 && id < i) {
      nxt[i] = id;
    }
  }
  vector <int> have(n, 0);
  for (int i = 0; i < n; ++i) {
    if (nxt[i] != -1) {
      have[nxt[i]] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!have[i]) {
      vector <int> p(n);
      int x = 0;
      int cur = i;
      while (cur != -1) {
        p[cur] = ++x;
        cur = nxt[cur];
      }
      cout << "! ";
      for (int j = 0; j < n; ++j) {
        cout << p[j] << ' ';
      }
      cout << endl;
      exit(0);
    }
  }
}