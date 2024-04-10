#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using BS = array<ull, 16>;

inline void clr(BS& x) {
  for (int i=0; i<16; ++i) {
    x[i] = 0;
  }
}

inline void toggle(BS& x, int idx) {
  x[idx/64] ^= ((ull) 1)<<(idx&(63));
}

inline BS Xor(const BS& x, const BS& y) {
  BS ret;
  for (int i=0; i<16; ++i) {
    ret[i] = x[i]^y[i];
  }
  return ret;
}

BS ls[35];
BS day[1010];
int ans[1010];

#ifdef LOCAL
const int SPLIT = 1;
#else
const int SPLIT = 10;
#endif

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  memset(ans, 0x3f3f3f3f, sizeof ans);
  int n, s, d;
  cin >> n >> s >> d;
  for (int i=0; i<s; ++i) {
    clr(ls[i]);
    int ci;
    cin >> ci;
    for (int j=0; j<ci; ++j) {
      int x;
      cin >> x;
      --x;
      toggle(ls[i], x);
    }
  }
  for (int i=1; i<=d; ++i) {
    clr(day[i]);
    int ci;
    cin >> ci;
    for (int j=0; j<ci; ++j) {
      int x;
      cin >> x;
      --x;
      toggle(day[i], x);
    }
  }
  vector<tuple<BS, int, int>> days;
  vector<pair<BS, int>> rem;
  if (SPLIT >= s) {
    BS r;
    clr(r);
    rem.push_back({r, 0});
  } else {
    rem.resize(1<<(s-SPLIT));
    for (int i=0; i<(1<<(s-SPLIT)); ++i) {
      clr(rem[i].first);
      rem[i].second = 0;
      for (int j=SPLIT; j<s; ++j) {
        if (i&(1<<(j-SPLIT))) {
          rem[i].first = Xor(rem[i].first, ls[j]);
          rem[i].second++;
        }
      }
    }
    sort(rem.begin(), rem.end());
  }

  int t = min(SPLIT, s);
  vector<pair<BS, int>> lwb(1<<t);
  for (int i=0; i<(1<<t); ++i) {
    clr(lwb[i].first);
    lwb[i].second = 0;
    for (int j=0; j<t; ++j) {
      if (i&(1<<j)) {
        lwb[i].first = Xor(lwb[i].first, ls[j]);
        lwb[i].second ++;
      }
    }
  }

  days.resize((1<<t)*d);
  for (int i=1; i<=d; ++i) {
    for (int j=0; j<(1<<t); ++j) {
      int idx = (i-1)*(1<<t) + j;
      get<0>(days[idx]) = Xor(lwb[j].first, day[i]);
      get<1>(days[idx]) = i;
      get<2>(days[idx]) = lwb[j].second;
    }
  }
  sort(days.begin(), days.end());

  int j = 0;
  for (int i=0; i<days.size(); ++i) {
    while (j < rem.size() && rem[j].first < get<0>(days[i])) {
      ++j;
    }
    if (rem[j].first == get<0>(days[i])) {
      int dy = get<1>(days[i]);
      int val = get<2>(days[i]) + rem[j].second;
      ans[dy] = min(ans[dy], val);
    }
  }

  for (int i=1; i<=d; ++i) {
    cout << (ans[i] <= s ? ans[i] : -1) << "\n";
  }

  return 0;
}