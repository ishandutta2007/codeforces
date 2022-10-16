//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

void solve(int) {
  string s;
  cin >> s;
  int k = 2;
  vector<vector<int>> byVal(26);
  int n = int(s.size());
  for (int i = 0; i < n; ++i) {
    byVal[s[i] - 'a'].push_back(i);
  }

  vector<int> ans;
  auto check = [&](int amt) {
    ans.assign(n, -1);
    auto nval = byVal;
    set<pair<int, int>, greater<>> st;
    for (int i = 0; i < 26; ++i) {
      if (!nval[i].empty()) st.emplace(int(nval[i].size()), i);
    }
    for (int c = 0; c < k; ++c) {
      vector<pair<int, int>> use;
      for (auto x : st) {
        if (int(use.size()) == amt) break;
        use.push_back(x);
      }
      if (int(use.size()) != amt) {
        return false;
      }
      for (auto[v, who] : use) {
        ans[nval[who].back()] = c;
        nval[who].pop_back();
        st.erase({v, who});
        if (v > 1) {
          st.emplace(v - 1, who);
        }
      }
    }
    return true;
  };

  int left = -1;
  int right = n + 1;
  while (left + 1 != right) {
    int mid = (left + right) / 2;
    (check(mid) ? left : right) = mid;
  }
  cout << left << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int _tt = 1; _tt <= tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}