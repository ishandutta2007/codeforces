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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<int> dep(n);
  vector<int> par(n, -1);
  vector<int> leaves;
  auto dfs = [&](auto&& self, int v, int p = -1) -> void {
    bool was = false;
    for (int u : graph[v]) {
      if (u != p) {
        par[u] = v;
        dep[u] = dep[v] + 1;
        was = true;
        self(self, u, v);
      }
    }
    if (!was) {
      leaves.push_back(v);
    }
  };
  dfs(dfs, 0);
  sort(leaves.begin(), leaves.end(), [&](int i, int j) {
    return dep[i] > dep[j];
  });
  vector<int> answers;
  vector<bool> used(n);
  for (int i : leaves) {
    int add = 0;
    while (i >= 0 && !used[i]) {
      add++;
      used[i] = true;
      i = par[i];
    }
    answers.push_back(add);
  }
  sort(answers.rbegin(), answers.rend());
  answers.insert(answers.begin(), 0);
  for (int i = 1; i < int(answers.size()); ++i) {
    answers[i] += answers[i - 1];
  }
  while (int(answers.size()) < k + 1) {
    answers.push_back(answers.back());
  }
  ll ans = LLONG_MIN;
  for (int r = 0; r <= k; ++r) {
    ll b = min(n - answers[r], n / 2);
    smax(ans, (n - r - b) * (r - b));
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}