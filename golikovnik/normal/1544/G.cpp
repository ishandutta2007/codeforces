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

void solve(int) {
  int len, k;
  cin >> len >> k;

  auto go = [&](string s) -> pair<string, vector<pair<int, int>>> {
    vector<int> segments;
    auto calcSegments = [&] {
      segments = {0};
      for (char ch : s) {
        if (ch == '1') {
          segments.push_back(0);
        } else {
          segments.back()++;
        }
      }
    };
    calcSegments();
    int nseg = int(segments.size());
    vector<pair<int, int>> ops;

    if (k == 0 || nseg <= k) {
      return make_pair(s, ops);
    }

    auto act = [&](int start, bool keepRight) {
      assert(1 <= start && start + k <= nseg);
      int i = accumulate(segments.begin(), segments.begin() + start, 0) + start - 1;
      int j = accumulate(segments.begin(), segments.begin() + start + k - 1, 0) + start + k - 2;
      if (keepRight) {
        i -= segments[start - 1];
      } else {
        j += segments[start + k - 1];
      }
      reverse(s.begin() + i, s.begin() + j + 1);
      ops.emplace_back(i, j);
      calcSegments();
    };

    if (nseg == k + 1) {
      act(1, true);
      auto cs = s;
      auto cops = ops;
      act(1, true);
      return s < cs ? make_pair(s, ops) : make_pair(cs, cops);
    }
    for (int it = 0; it < nseg - k; ++it) {
      act(it + 1, true);
      assert(segments[it] == 0);
    }
    if (k % 2 == 1) {
      for (int it = 0; it < k - 1; ++it) {
        act(nseg - k - 1, true);
        act(nseg - k, true);
      }
    } else {
      for (int it = 0; it < k / 2; ++it) {
        act(nseg - k - 1, false);
        act(nseg - k, true);
        act(nseg - k - 1, true);
        act(nseg - k - 1, true);
      }
    }
    return make_pair(s, ops);
  };

  string s, t;
  cin >> s >> t;
  auto[s_end, s_ops] = go(s);
  auto[t_end, t_ops] = go(t);
  if (s_end != t_end) {
    cout << -1 << '\n';
  } else {
    s_ops.insert(s_ops.end(), t_ops.rbegin(), t_ops.rend());
    assert(s_ops.size() <= 4 * len);
    cout << s_ops.size() << '\n';
    for (auto[i, j] : s_ops) {
      assert(count(s.begin() + i, s.begin() + j + 1, '1') == k);
      reverse(s.begin() + i, s.begin() + j + 1);
      cout << i + 1 << ' ' << j + 1 << '\n';
    }
    assert(s == t);
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