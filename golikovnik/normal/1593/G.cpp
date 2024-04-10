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

void solve(int) {
  string s; cin >> s;
  int n = int(s.size());

  struct node {
    int len, first;

    node() : len(0), first(-1) {}

    node(char ch) : len(1) {
      first = (ch == '(' || ch == ')') ? 0 : 1;
    }

    node(int len_, int first_) : len(len_), first(first_) {}

    node operator+(node const& other) const {
      if (len == 0) return other;
      if (other.len == 0) return *this;

      int last = first ^ (len % 2) ^ 1;
      if (last != other.first) {
        return {len + other.len, first};
      }
      if (len == other.len) {
        return {0, -1};
      }
      if (len < other.len) {
        return {other.len - len, other.first ^ (len % 2)};
      }
      return {len - other.len, first};
    }
  };
  int pw = 1;
  while (pw < n) pw *= 2;
  vector<node> tree(2 * pw);
  for (int i = 0; i < n; ++i) {
    tree[pw + i] = node(s[i]);
  }
  for (int i = pw - 1; i > 0; --i) {
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }

  auto Query = [&](int ql, int qr) {
    node resL{}, resR{};
    for (ql += pw, qr += pw; ql < qr; ql /= 2, qr /= 2) {
      if (ql & 1) resL = resL + tree[ql++];
      if (qr & 1) resR = tree[--qr] + resR;
    }
    return resL + resR;
  };

  int q; cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    cout << Query(l, r).len / 2 << '\n';
  }
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}