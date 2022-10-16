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
  vector<string> a(n);
  for (auto& s : a) cin >> s;
  a.insert(a.begin(), "blue");
  ++n;
  int pw = 1;
  while (pw < n) pw *= 2;
  struct node {
    pair<int, string> val[2];

    node() {
      for (int i = 0; i < 2; ++i) {
        val[i] = make_pair(i, "");
      }
    }

    node(string const& s) {
      for (int i = 0; i < 2; ++i) {
        if (s == "lock") {
          val[i] = make_pair(1, "");
        } else if (s == "unlock") {
          val[i] = make_pair(0, "");
        } else if (i == 0) {
          val[i] = make_pair(0, s);
        } else {
          val[i] = make_pair(1, "");
        }
      }
    }

    node operator+(node const& other) const {
      node res;
      for (int start : {0, 1}) {
        auto[lockedLeft, colorLeft] = val[start];
        auto[lockedRight, colorRight] = other.val[lockedLeft];
        res.val[start] = make_pair(lockedRight, colorRight.empty() ? colorLeft : colorRight);
      }
      return res;
    }
  };
  vector<node> tree(2 * pw);
  for (int i = 0; i < n; ++i) {
    tree[pw + i] = node(a[i]);
  }
  for (int i = pw - 1; i > 0; --i) {
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
  auto Get = [&] {
    return tree[1].val[0].second;
  };
  cout << Get() << '\n';
//  int q;
//  cin >> q;
//  while (q--) {
//    int id;
//    string s;
//    cin >> id >> s;
//    for (tree[id += pw] = node(s); id /= 2; ) {
//      tree[id] = tree[2 * id] + tree[2 * id + 1];
//    }
//    cout << Get() << '\n';
//  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}