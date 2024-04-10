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

int get(const vector<int> &a, const vector<int> &b) {
  int n = a.size();
  vector<int> p(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  vector<int> used(n);
  int timer = 0;
  int best = n;
  do {
    bool bad = false;
    for (int i = 0; i < n; ++i) if (a[p[i]] != b[i]) bad = true;
    if (bad) continue;
    ++timer;
    int cnt = n;
    for (int i = 0; i < n; ++i) {
      if (used[i] == timer) continue;
      --cnt;
      int cur = i;
      while (used[cur] != timer) {
        used[cur] = timer;
        cur = p[cur];
      }
    }
    best = min(best, cnt);
  } while (next_permutation(p.begin(), p.end()));
  return best;
}

vector<int> stupid(const vector<int>& a) {
  int n = a.size();
  int best = 0;
  vector<int> ret = a;
  vector<int> b = a;
  sort(b.begin(), b.end());
  do {
    int cur = get(b, a);
    if (cur > best) {
      best = cur;
      ret = b;
    }
  } while (next_permutation(b.begin(), b.end()));
  return ret;
}

vector<int> smart(const vector<int>& a) {
  int n = a.size(); 
  vector<int> p(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  sort(p.begin(), p.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  int cur = 1;
  int mx = 0;
  for (int i = 1; i < n; ++i) {
    if (a[p[i]] == a[p[i - 1]]) {
      ++cur;
      mx = max(mx, cur);
    } else {
      cur = 1;
    }
  }
  mx = max(mx, cur);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    b[p[(i + mx) % n]] = a[p[i]];
  }
  return b;
}

void stress() {
  int t = 1000;
  mt19937 rnd(123);
  for (int tt = 0; tt < t; ++tt) {
    int n = rnd() % 8 + 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rnd() % n + 1;
    auto st = stupid(a);
    auto sm = smart(a);
    if (get(st, a) != get(sm, a)) {
      cout << n << endl;
      for (auto x : a) cout << x << ' ';
      cout << endl;
      exit(0);
    }
    if ((tt + 1) % 10 == 0) {
      cout << tt << endl;
    }
  }
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  //stress();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (auto x : smart(a)) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}