//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

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
  string s; cin >> s;
  vector<int> first(26, -1);
  int n = int(s.size());
  string order;
  for (int i = n - 1; i >= 0; --i) {
    if (first[s[i] - 'a'] < 0) {
      order.push_back(s[i]);
    }
    first[s[i] - 'a'] = i;
  }
  reverse(order.begin(), order.end());
  int left = *max_element(first.begin(), first.end());
  int right = n;

  auto Get = [&](int mid) {
    array<int, 26> cnt{};
    for (int i = 0; i < mid; ++i) {
      cnt[s[i] - 'a']++;
    }
    int clen = mid;
    int len = mid;
    for (char ch : order) {
      clen -= cnt[ch - 'a'];
      len += clen;
    }
    return len;
  };
  while (left + 1 != right) {
    int mid = (left + right) / 2;
    if (Get(mid) < n) {
      left = mid;
    } else {
      right = mid;
    }
  }
  if (Get(right) == n) {
    string result;
    auto check = s.substr(0, right);
    auto cur = check;
    result += cur;
    for (auto ch : order) {
      string ncur;
      for (auto chh : cur) if (chh != ch) {
        ncur.push_back(chh);
      }
      result += ncur;
      cur = ncur;
    }
    if (result == s) {
      cout << check << ' ' << order << '\n';  
    } else {
      cout << -1 << '\n';
    }
  } else {
    cout << -1 << '\n';
  }
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}