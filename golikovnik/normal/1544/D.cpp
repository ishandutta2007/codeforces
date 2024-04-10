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

#ifdef GOLIKOV
mt19937_64 rng(566);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}

void solve(int) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
    --x;
  }
  set st(a.begin(), a.end());
  cout << st.size() << '\n';
  if (int(st.size()) == n) {
    for (auto x : a) cout << x + 1 << ' ';
    cout << '\n';
    return;
  }
  if (int(st.size()) == n - 1) {
    vector<int> cnt(n);
    for (auto x : a) cnt[x]++;
    int left = min_element(cnt.begin(), cnt.end()) - cnt.begin();
    int repeat = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    for (int i = 0; i < n; ++i) {
      if (i != left && a[i] == repeat) {
        a[i] = left;
        break;
      }
    }
    for (auto x : a) cout << x + 1 << ' ';
    cout << '\n';
    return;
  }
  vector<int> ans(n, -1);
  vector<bool> used(n);
  for (int i = 0; i < n; ++i) {
    if (used[a[i]]) continue;
    ans[i] = a[i];
    used[a[i]] = true;
  }
  vector<int> ins;
  for (int i = 0; i < n; ++i) if (!st.count(i)) ins.push_back(i);
  while (true) {
    shuffle(ins.begin(), ins.end(), rng);
    auto res = ans;
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
      if (res[i] < 0) res[i] = ins[ptr++];
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) ok &= res[i] != i;
    if (ok) {
      for (auto x : res) cout << x + 1 << ' ';
      cout << '\n';
      return;
    }
  }
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