#include <bits/stdc++.h>

using namespace std;

using ui64 = uint64_t;

template <size_t BITS>
struct basis {
  ui64 a[BITS] = {};
  int size{};
  
  void insert(ui64 x) {
    for (unsigned b = 0; b < BITS; ++b) {
      if (!(x & (1u << b))) {
        continue;
      }
      if (!a[b]) {
        a[b] = x;
        ++size;
        return;
      }
      x ^= a[b];
    }
  }

  bool representable(ui64 x) const {
    for (unsigned b = 0; b < BITS; ++b) {
      if (!(x & (1u << b))) {
        continue;
      }
      if (!a[b]) {
        return false;
      }
      x ^= a[b];
    }
    return true;
  }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  struct query {
    int l;
    int x;
    int i;
  };
  vector<query> qs(q);
  for (int i = 0; i < q; ++i) {
    cin >> qs[i].l >> qs[i].x;
    qs[i].i = i;
  }
  sort(qs.begin(), qs.end(), [](auto x, auto y) {
    return x.l < y.l;
  });

  int const MOD = 1e9 + 7;
  vector<int> pw(n + 1);
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pw[i] = 2 * pw[i - 1];
    if (pw[i] >= MOD) {
      pw[i] -= MOD;
    }
  }
  vector<int> answer(q);
  int qi = 0;
  basis<20> bs;
  for (int i = 0; i < n; ++i) {
    bs.insert(a[i]);
    while (qi < q && qs[qi].l == i + 1) {
      if (bs.representable(qs[qi].x)) {
        answer[qs[qi].i] = pw[i + 1 - bs.size];
      } else {
        answer[qs[qi].i] = 0;
      }
      qi++;
    }
  }
  for (int x : answer) {
    cout << x << '\n';
  }
  return 0;
}