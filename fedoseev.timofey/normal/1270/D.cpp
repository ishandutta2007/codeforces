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
#include <cassert>

using namespace std;

typedef long long ll;

pair <int, int> query(vector <int> a) {
  cout << "? ";
  for (int id : a) cout << id + 1 << ' ';
  cout << endl;
  int pos, val;
  cin >> pos >> val;
  --pos;
  return make_pair(pos, val);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  //freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  vector <int> a;
  for (int i = 0; i < k; ++i) a.push_back(i);
  pair <int, int> f = query(a);
  set <int> sm;
  for (int i = 0; i < k; ++i) {
    if (i == f.first) continue;
    vector <int> b;
    for (int j = 0; j < k; ++j) {
      if (j == i) continue;
      b.push_back(j);
    }
    b.push_back(k);
    pair <int, int> s = query(b);
    if (s.first == f.first) {
      sm.insert(i);
    }
  }
  sm.insert(k);
  vector <int> b;
  for (int i = 0; i <= k; ++i) {
    if (i == f.first) continue;
    b.push_back(i);
  }
  int ans;
  pair <int, int> s = query(b);
  if (s.second < f.second) {
    if (sm.count(s.first)) {
      ans = (int)sm.size();
    } else {
      ans = k - (int)sm.size() + 1;
    }
  } else {
    if (sm.count(s.first)) {
      ans = k - (int)sm.size() + 1;
    } else {
      ans = (int)sm.size();
    }
  }
  cout << "! " << ans << endl;
}