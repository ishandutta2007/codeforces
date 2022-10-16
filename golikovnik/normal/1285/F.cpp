//  Copyright 2022 Nikita Golikov

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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int const N = int(1e5) + 10;
  int n; cin >> n;
  vector<int> a(N);
  ll ans = 0;
  for (int i = 0; i < N; ++i) {
    int x; cin >> x; smax(ans, x); ++a[x];
  }

  vector<int> mu(N);
  mu[1] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 2 * i; j < N; j += i) {
      mu[j] -= mu[i];
    }
  }
  vector<vector<int>> divs(N);
  for (int i = 1; i < N; ++i) {
    if (mu[i] != 0) {
      for (int j = i; j < N; j += i) {
        divs[j].push_back(i);
      }
    }
  }

  vector<int> sum(N);
  auto add = [&](int x, int sign) {
    for (int y : divs[x]) {
      sum[y] += sign;
    }
  };
  auto Remove = [&](int x) {
    add(x, -1);
  };
  auto Add = [&](int x) {
    add(x, 1);
  };
  auto countCoprime = [&](int x) {
    int res = 0;
    for (int y : divs[x]) {
      res += sum[y] * mu[y];
    }
    return res;
  };

  for (int g = 1; g < N; ++g) {
    vector<int> nums;
    for (int x = g; x < N; x += g) {
      if (a[x]) {
        nums.push_back(x / g);
      }
    }
    reverse(nums.begin(), nums.end());
    vector<int> st;
    for (int x : nums) {
      while (countCoprime(x) != 0) {
        int y = st.back(); st.pop_back();
        if (gcd(x, y) == 1) {
          smax(ans, ll(x) * y * g);
        }
        Remove(y);
      }
      Add(x);
      st.push_back(x);
    }
    while (!st.empty()) {
      int y = st.back(); st.pop_back(); Remove(y);
    }
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}