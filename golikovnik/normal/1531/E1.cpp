//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

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

map<tuple<int, int, int>, pair<bool, vector<int>>> dp;

string s;

vector<int> makeMerge(vector<int> const& vL, vector<int> const& vR, int st) {
  int nl = int(vL.size());
  int nr = int(vR.size());
  vector<int> ans;
  int posL = 0;
  int posR = 0;
  int use = 0;
  while (posL < nl && posR < nr) {
    auto who = s[st + use++] - '0';
    if (who == 0) {
      ans.push_back(vL[posL++]);
    } else {
      ans.push_back(nl + vR[posR++]);
    }
  }
  while (posL < nl) {
    ans.push_back(vL[posL++]);
  }
  while (posR < nr) {
    ans.push_back(nl + vR[posR++]);
  }
  return ans;
}

pair<bool, vector<int>> solve(int l, int r, int n) {
  if (n == 1) {
    if (l == r) {
      return make_pair(true, vector<int>{0});
    }
    return make_pair(false, vector<int>{});
  }
  if (l == r) {
    return make_pair(false, vector<int>{});
  }
  if (dp.count({l, r, n})) {
    return dp[{l, r, n}];
  }
  int left = n / 2;
  int right = n - left;
  int c0 = 0;
  int c1 = 0;
  int whoLast = s[r - 1] - '0';
  for (int merge = 0; c0 <= left && c1 <= right && merge <= r - l; ++merge) {
    if ((whoLast == 0 && c0 == left && c1 < right) || (whoLast == 1 && c0 < left && c1 == right)) {
      for (int sr = 0; sr + merge <= r - l; ++sr) {
        int sl = r - l - sr - merge;
        auto[s1, v1] = solve(l, l + sl, left);
        auto[s2, v2] = solve(l + sl, l + sl + sr, right);
        if (s1 && s2) {
          return dp[{l, r, n}] = make_pair(true, makeMerge(v1, v2, l + sl + sr));
        }
      }
    }
    if (merge != r - l) {
      auto chr = s[r - merge - 1];
      if (chr == '0') c0++; else c1++;
    }
  }
  return dp[{l, r, n}] = make_pair(false, vector<int>{});
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  auto[success, res] = solve(0, int(s.size()), 16);
  assert(success);
  vector<int> invRes(16);
  for (int i = 0; i < 16; ++i) {
    invRes[res[i]] = i;
  }
  cout << 16 << '\n';
  for (auto x : invRes) {
    cout << x + 1 << ' ';
  }
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}