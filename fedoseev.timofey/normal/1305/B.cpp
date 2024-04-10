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
  string s;
  cin >> s;
  deque <pair <char, int>> d;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    d.push_back({s[i], i});
  }
  vector <int> l, r;
  while (!d.empty()) {
    while (!d.empty() && d.front().first == ')') d.pop_front();
    while (!d.empty() && d.back().first == '(') d.pop_back();
    if (!d.empty()) {
      l.push_back(d.front().second);
      r.push_back(d.back().second);
      d.pop_front();
      d.pop_back();
    }
  }
  reverse(r.begin(), r.end());
  if (l.size() + r.size() > 0) {
    cout << "1\n";
    cout << l.size() + r.size() << '\n';
    for (int id : l) cout << id + 1 << ' ';
    for (int id : r) cout << id + 1 << ' ';
  } else {
    cout << "0\n";
  }
}