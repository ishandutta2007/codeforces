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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  map<pair<int, int>, char> mp;
  int cntSame = 0;
  int cntBi = 0;

  auto addEdge = [&](int u, int v, char ch) {
    if (mp.count(make_pair(v, u))) {
      auto rev = mp[make_pair(v, u)];
      cntBi++;
      if (ch == rev) cntSame++;
    }
    mp[make_pair(u, v)] = ch;
  };
  auto deleteEdge = [&](int u, int v) {
    auto ch = mp[make_pair(u, v)];
    if (mp.count(make_pair(v, u))) {
      auto rev = mp[make_pair(v, u)];
      cntBi--;
      if (ch == rev) cntSame--;
    }
    mp.erase(make_pair(u, v));
  };

  while (m--) {
    char ch;
    cin >> ch;
    if (ch == '?') {
      int k;
      cin >> k;
      if (k % 2 == 0) {
        cout << (cntSame ? "YES" : "NO") << '\n';
      } else {
        cout << (cntBi ? "YES" : "NO") << '\n';
      }
    } else {
      int u, v;
      cin >> u >> v;
      --u, --v;
      if (ch == '+') {
        char c;
        cin >> c;
        addEdge(u, v, c);
      } else {
        deleteEdge(u, v);
      }
    }
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}