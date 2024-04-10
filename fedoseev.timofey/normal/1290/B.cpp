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
  
using namespace std;

typedef long long ll;

bool ok(string a, string b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  return a == b;
}

bool check(string s) {
  bool fnd = false;
  string t = s;
  sort(t.begin(), t.end());
  do {
    bool fl = true;
    for (int sz = 1; sz < (int)s.size(); ++sz) {
      if (ok(s.substr(0, sz), t.substr(0, sz))) {
        fl = false;
      }
    }
    if (fl) {
      fnd = true;
      cout << t << endl;
    }
  } while (next_permutation(t.begin(), t.end()));
  return fnd;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = s.size();
  vector <vector <int>> cnt(26, vector <int> (n + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) {
      cnt[j][i + 1] += cnt[j][i];
    }
    ++cnt[s[i] - 'a'][i + 1];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int have = 0;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i][r + 1] - cnt[i][l] > 0) ++have;
    }
    if (have >= 3) {
      cout << "Yes\n";
    } else if (have == 2) {
      if (s[l] != s[r]) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    } else {
      if (l == r) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
}