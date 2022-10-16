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

  int n; cin >> n;
  struct guy {
    ll a;
    ll b;
    ll t;
  };
  vector<guy> guys(n);
  for (auto& [a, b, t] : guys) {
    cin >> a >> b >> t;
  }
  ll curt = 0;
  set<pair<ll, int>> byAT;
  for (int i = 0; i < n; ++i) {
    byAT.emplace(guys[i].a + guys[i].t, i);
  }
  set<pair<ll, int>> active;
  ll ans = 0;
  vector<int> ordEnter(n);
  iota(ordEnter.begin(), ordEnter.end(), 0);
  sort(ordEnter.begin(), ordEnter.end(), [&](int i, int j) {
    return guys[i].a < guys[j].a;
  });
  vector<int> ordLeave(n);
  iota(ordLeave.begin(), ordLeave.end(), 0);
  sort(ordLeave.begin(), ordLeave.end(), [&](int i, int j) {
    return guys[i].b < guys[j].b;
  });
  int ptrEnter = 0;
  int ptrLeave = 0;
  ll const INF = ll(1.2e18);
  while (true) {
    while (ptrEnter < n && guys[ordEnter[ptrEnter]].a <= curt) {
      int i = ordEnter[ptrEnter++];
      byAT.erase(make_pair(guys[i].a + guys[i].t, i));
      active.emplace(guys[i].t, i);
    }
    while (ptrLeave < n && guys[ordLeave[ptrLeave]].b <= curt) {
      int i = ordLeave[ptrLeave++];
      byAT.erase(make_pair(guys[i].a + guys[i].t, i));
      active.erase(make_pair(guys[i].t, i));
    }
    while (!active.empty()) {
      auto[tt, i] = *active.begin();
      if (curt + tt > guys[i].b) {
        active.erase(active.begin());
      } else {
        break;
      }
    }
    if (active.empty() && byAT.empty()) {
      break;
    }
    ll forgeAT = byAT.empty() ? INF : byAT.begin()->first;
    ll forgeActive = active.empty() ? INF : active.begin()->first + curt;
    if (forgeAT < forgeActive) {
      // cerr << curt << '\n';
      curt = forgeAT;
      ans++;
      continue;
    }
    auto[tt, i] = *active.begin();
    auto can = (min(forgeAT, guys[i].b) - curt) / tt;
    assert(can > 0);
    ans += can;
    curt += can * tt;
    // cerr << curt << ' ' << tt << ' ' << can << '\n';
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}