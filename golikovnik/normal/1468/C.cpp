//  Copyright 2020 Nikita Golikov

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

  int q;
  cin >> q;
  vector<bool> used;
  set<pair<int, int>> guys;
  int ptr = 0;
  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int m;
      cin >> m;
      used.push_back(false);
      guys.emplace(-m, (int) used.size() - 1);
    } else if (t == 2) {
      while (used[ptr]) {
        ptr++;
      }
      used[ptr] = true;
      cout << ptr + 1 << ' ';
    } else {
      while (true) {
        auto[val, i] = *guys.begin();
        guys.erase(guys.begin());
        if (!used[i]) {
          used[i] = true;
          cout << i + 1 << ' ';
          break;
        }
      }
    }
  }
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}