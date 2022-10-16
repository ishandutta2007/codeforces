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

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<int> L(n), R(n);
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] < a[i]) {
      L[i] = L[i - 1];
    } else {
      L[i] = i;
    }
  }
  R[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] > a[i + 1]) {
      R[i] = R[i + 1];
    } else {
      R[i] = i;
    }
  }

  vector<int> upL(n), upR(n);
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] > a[i]) {
      upL[i] = upL[i - 1] + 1;
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    if (a[i + 1] > a[i]) {
      upR[i] = upR[i + 1] + 1;
    }
  }
  vector<int> pref(n), suff(n);
  pref[0] = max(upL[0], upR[0]);
  for (int i = 1; i < n; ++i) {
    pref[i] = max({pref[i - 1], upL[i], upR[i]});
  }
  suff[n - 1] = max(upL[n - 1], upR[n - 1]);
  for (int i = n - 2; i >= 0; --i) {
    suff[i] = max({suff[i + 1], upL[i], upR[i]});
  }

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    auto l = L[i];
    auto r = R[i];
    int he = 0;
    if (l > 0) {
      smax(he, pref[l - 1]);
    }
    if (r < n - 1) {
      smax(he, suff[r + 1]);
    }
    if (max(r - i, i - l) <= he) {
      continue;
    }
    if (l < i) {
      int hisPos = l + (1 - (i - l) % 2);
      if (i - hisPos >= r - i) {
        continue;
      }
      if (hisPos == l) {
        if (upL[l] >= r - i) {
          continue;
        }
      } else {
        if (upL[l] >= max(i - l, r - i)) {
          continue;
        }
      }
    }
    if (r > i) {
      int hisPos = r - (1 - (r - i) % 2);
      if (hisPos - i >= i - l) {
        continue;
      }
      if (hisPos == r) {
        if (upR[r] >= i - l) {
          continue;
        }
      } else {
        if (upR[r] >= max(r - i, i - l)) {
          continue;
        }
      }
    }
    ans++;
  }

  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}