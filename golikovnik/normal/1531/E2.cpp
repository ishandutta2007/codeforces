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

string s;

vector<int> solve(int& from, int n) {
  if (n == 1) {
    return {0};
  }
  int left = n / 2;
  int right = n - left;
  auto vL = solve(from, left);
  auto vR = solve(from, right);
  vector<int> ans;
  int posL = 0;
  int posR = 0;
  while (posL < left && posR < right) {
    if (from == int(s.size())) {
      throw runtime_error("bad");
    }
    auto who = s[from++] - '0';
    if (who == 0) {
      ans.push_back(vL[posL++]);
    } else {
      ans.push_back(left + vR[posR++]);
    }
  }
  while (posL < left) {
    ans.push_back(vL[posL++]);
  }
  while (posR < right) {
    ans.push_back(left + vR[posR++]);
  }
  return ans;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  for (int n = 1; n <= 1000; ++n) {
    int cur = 0;
    try {
      auto res = solve(cur, n);
      if (cur == int(s.size())) {
        vector<int> invRes(n);
        for (int i = 0; i < n; ++i) {
          invRes[res[i]] = i;
        }
        cout << n << '\n';
        for (auto x : invRes) {
          cout << x + 1 << ' ';
        }
        cout << '\n';
        return 0;
      }
    } catch (exception const&) {
      while (true) {
        cout << "here\n";
      }
    }
  }
  assert(false);

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}