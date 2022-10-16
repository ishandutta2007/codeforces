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

vector<int> goodFor[16];

bool AOS(int m) {
  return m >> 0 & 1;
}
bool BIT(int m) {
  return m >> 1 & 1;
}
bool BOS(int m) {
  return m >> 2 & 1;
}
bool CIT(int m) {
  return m >> 3 & 1;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  static int const INF = int(1e7);

  int n, q;
  cin >> n >> q;
  string s; cin >> s;
  struct node {
    array<int, 16> score;

    node() {
      score.fill(INF);
      score[0] = 0;
    }

    node operator+(node const& other) const {
      node res{};
      res.score[0] = INF;
      for (int ml = 0; ml < 16; ++ml) {
        for (int mr : goodFor[ml]) {
          smin(res.score[ml | mr], score[ml] + other.score[mr]);
        }
      }
      return res;
    }
  };

  for (int ml = 0; ml < 16; ++ml) {
    for (int mr = 0; mr < 16; ++mr) {
      if (AOS(ml) && BIT(mr)) {
        continue;
      }
      if (BOS(ml) && CIT(mr)) {
        continue;
      }
      goodFor[ml].push_back(mr);
    }
  }

  vector<node> nodes(3);
  for (int t = 0; t < 3; ++t) {
    nodes[t].score.fill(INF);
  }
  nodes[0].score[1] = 0;
  nodes[0].score[0] = 1;
  nodes[2].score[8] = 0;
  nodes[2].score[0] = 1;
  nodes[1].score[4] = 0;
  nodes[1].score[2] = 0;
  nodes[1].score[4 | 2] = 0;
  nodes[1].score[0] = 1;

  int pw = 1;
  while (pw < n) pw *= 2;
  vector<node> tree(2 * pw);
  for (int i = 0; i < n; ++i) {
    tree[pw + i] = nodes[s[i] - 'a'];
  }
  for (int i = pw - 1; i > 0; --i) {
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }

  while (q--) {
    int pos;
    char ch;
    cin >> pos >> ch;
    --pos;
    for (tree[pos += pw] = nodes[ch - 'a']; pos /= 2; ) {
      tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
    }
    cout << *min_element(tree[1].score.begin(), tree[1].score.end()) << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}