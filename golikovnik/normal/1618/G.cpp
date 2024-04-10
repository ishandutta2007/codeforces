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

struct sum_set {
  multiset<ll> left, right;
  ll sum = 0;

  void insert(ll x) {
    if (right.empty() || x < *right.begin()) {
      left.insert(x);
    } else {
      right.insert(x);
      sum += x;
    }
  }

  ll getsum(ll k) {
    assert(k <= int(size()));
    while (int(right.size()) > k) {
      ll x = *right.begin();
      right.erase(right.begin());
      sum -= x;
      left.insert(x);
    }
    while (int(right.size()) < k) {
      ll x = *left.rbegin();
      left.erase(prev(left.end()));
      sum += x;
      right.insert(x);
    }
    return sum;
  }

  size_t size() const {
    return left.size() + right.size();
  }

  void clear() {
    left.clear();
    right.clear();
  }
};

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> items(n + m);
  for (int i = 0; i < n; ++i) {
    cin >> items[i].first;
    items[i].second = 1;
  }
  for (int i = 0; i < m; ++i) {
    cin >> items[n + i].first;
    items[n + i].second = 0;
  }
  sort(items.begin(), items.end());
  n += m;
  vector<pair<int, int>> qs(q);
  for (int i = 0; i < q; ++i) {
    cin >> qs[i].first;
    qs[i].second = i;
  }
  sort(qs.begin(), qs.end());
  vector<ll> ans(q);

  vector<pair<int, int>> diffs(n - 1);
  for (int i = 1; i < n; ++i) {
    diffs[i - 1] = make_pair(items[i].first - items[i - 1].first, i - 1);
  }
  sort(diffs.begin(), diffs.end());

  vector<int> dsu(n);
  vector<sum_set> elems(n);
  vector<int> cnt(n);
  ll curans = 0;
  for (int i = 0; i < n; ++i) {
    dsu[i] = i;
    elems[i].insert(items[i].first);
    if (items[i].second) {
      ++cnt[i];
      curans += items[i].first;      
    }
  }
  auto find = [&](auto&& self, int v) -> int {
    return dsu[v] == v ? v : dsu[v] = self(self, dsu[v]);
  };

  int ptr = 0;

  auto get = [&](int v) {
    return elems[v].getsum(cnt[v]);
  };

  auto activate = [&](int i) {
    int u = find(find, i);
    int v = find(find, i + 1);
    assert(u != v);
    if (elems[u].size() > elems[v].size()) {
      swap(u, v);
    }
    curans -= get(u);
    curans -= get(v);
    for (int val : elems[u].left) {
      elems[v].insert(val);
    }
    for (int val : elems[u].right) {
      elems[v].insert(val);
    }
    elems[u].clear();
    cnt[v] += cnt[u];
    dsu[u] = v;
    curans += get(v);
  };

  for (auto[k, qi] : qs) {
    while (ptr < n - 1 && diffs[ptr].first <= k) {
      activate(diffs[ptr++].second);
    }
    ans[qi] = curans;
  }

  for (auto x : ans) cout << x << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}