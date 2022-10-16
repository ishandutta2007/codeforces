#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> k;
  string s;
  s.reserve((size_t) 1e6 + 5);
  string cur;
  while (cin >> cur) {
    s += cur;
    s += ' ';
  }
  s.pop_back();

  vector<int> pos;
  int n = (int) s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == '-' || s[i] == ' ') {
      pos.push_back(i);
    }
  }
  int left = 0;
  int right = n;
  while (left + 1 != right) {
    int middle = (left + right) / 2;
    int cur = 0;
    bool fail = false;
    int nlines = 0;
    while (n - cur > middle) {
      //  j : j - cur + 1 <= middle
      //  j <= middle + cur - 1
      auto it = upper_bound(pos.begin(), pos.end(), middle + cur - 1);
      if (it == pos.begin()) {
        fail = true;
        break;
      }
      --it;
      auto j = *it;
      if (j < cur) {
        fail = true;
        break;
      }
      auto dist = j - cur + 1;
      if (dist > middle) {
        fail = true;
        break;
      }
      cur = j + 1;
      ++nlines;
    }
    nlines += cur != n;
    fail |= nlines > k;
    (fail ? left : right) = middle;
  }
  cout << right << '\n';
  return 0;
}