//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

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

  int const INF = int(1e9);

  int n, k;
  cin >> n >> k;
  struct Seg {
    int any;
    vector<int> mn, mx, dp;
  };
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  vector<Seg> segs;
  for (auto x : a) {
    segs.push_back({x, {0}, {0}, {INF}});
  }
  vector<Seg> nsegs;
  for (int suff = 1; suff <= k; ++suff) {
    auto pref = [&](auto& v) {
      return v.any >> suff;
    };

    nsegs.clear();
    int was = int(segs.size());
    int pw = 1 << (suff - 1);
    for (int i = 0; i < was; ) {
      if (i + 1 < was && pref(segs[i]) == pref(segs[i + 1])) {
        auto& x = segs[i];
        auto& y = segs[i + 1];
        Seg nw{x.any, vector<int>(1 << suff), vector<int>(1 << suff), vector<int>(1 << suff)};
        for (int msk = 0; msk < (1 << (suff - 1)); ++msk) {
          for (int rot = 0; rot < 2; ++rot, swap(x, y)) {
            int id = msk + pw * rot;
            nw.dp[id] = min({x.dp[msk], y.dp[msk], y.mn[msk] + pw - x.mx[msk]});
            nw.mn[id] = x.mn[msk];
            nw.mx[id] = y.mx[msk] + pw;          
          }
        }
        nsegs.push_back(nw);
        i += 2;
      } else {
        auto& x = segs[i];
        auto add = x.any & pw;
        Seg nw{x.any, vector<int>(1 << suff), vector<int>(1 << suff), vector<int>(1 << suff)};
        for (int msk = 0; msk < (1 << (suff - 1)); ++msk) {
          nw.dp[msk] = nw.dp[pw + msk] = x.dp[msk];
          nw.mn[msk] = x.mn[msk] + add;
          nw.mn[pw + msk] = pw ^ nw.mn[msk];
          nw.mx[msk] = x.mx[msk] + add;
          nw.mx[pw + msk] = pw ^ nw.mx[msk];
        }
        nsegs.push_back(nw);
        i++;
      }
    }
    segs.swap(nsegs);
  }
  assert(segs.size() == 1 && int(segs[0].dp.size()) == 1 << k);
  for (auto x : segs[0].dp) cout << x << ' ';
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}