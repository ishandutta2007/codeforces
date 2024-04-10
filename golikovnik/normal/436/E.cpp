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

  int n, w; cin >> n >> w;
  struct item { int a, b, id; };
  vector<item> items(n);
  for (int i = 0; i < n; ++i) {
    cin >> items[i].a >> items[i].b;
    items[i].id = i;
  }
  sort(items.begin(), items.end(), [](item x, item y) {
    return x.b < y.b;
  });

  set<pair<int, int>> smallSet, bigSet;
  ll sumSmall = 0;

  auto erase = [&](int val, int id) {
    pair p{val, id};
    if (smallSet.erase(p)) {
      sumSmall -= val;
      return;
    }
    auto r = bigSet.erase(p);
    assert(r);
  };
  auto add = [&](int val, int id) {
    if (bigSet.empty() || val <= bigSet.begin()->first) {
      smallSet.emplace(val, id);
      sumSmall += val;
    } else {
      bigSet.emplace(val, id);
    }
  };
  auto getSum = [&](int amt) {
    while (int(smallSet.size()) > amt) {
      auto it = prev(smallSet.end());
      auto x = *it;
      sumSmall -= x.first;
      smallSet.erase(it);
      bigSet.insert(x);
    }
    while (int(smallSet.size()) < amt) {
      auto it = bigSet.begin();
      auto x = *it;
      sumSmall += x.first;
      bigSet.erase(it);
      smallSet.insert(x);
    }
    return sumSmall;
  };

  for (int i = 0; i < n; ++i) {
    add(items[i].a, i);
  }

  ll ans = LLONG_MAX;
  ll suma = 0;

  if (w <= n) {
    smin(ans, getSum(w));
  }

  for (int i = 0; i < n; ++i) {
    auto x = items[i];
    suma += x.a;
    erase(x.a, i);
    add(x.b - x.a, i);

    int have = i + 1;
    if (have > w) {
      break;
    }
    int need = w - have;
    if (need > n) {
      continue;
    }

    smin(ans, suma + getSum(need));
  }
  cout << ans << '\n';

  smallSet.clear();
  bigSet.clear();
  sumSmall = 0;
  for (int i = 0; i < n; ++i) {
    add(items[i].a, i);
  }
  suma = 0;

  if (w <= n && ans == getSum(w)) {
    vector<int> count(n);

    for (auto it : smallSet) {
      count[items[it.second].id]++;
    }

    for (int v : count) cout << v;
    cout << '\n';
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    auto x = items[i];
    suma += x.a;
    erase(x.a, i);
    add(x.b - x.a, i);

    int have = i + 1;
    if (have > w) {
      break;
    }
    int need = w - have;
    if (need > n) {
      continue;
    }

    if (suma + getSum(need) == ans) {
      vector<int> count(n);

      for (int j = 0; j <= i; ++j) {
        count[items[j].id]++;
      }
      for (auto it : smallSet) {
        count[items[it.second].id]++;
      }

      for (int v : count) cout << v;
      cout << '\n';
      return 0;
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