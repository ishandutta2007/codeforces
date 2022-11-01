#include <bits/stdc++.h>

using namespace std;


struct Point {
  int x, y;
};


struct Query {
  int id;
  int l, r;
  int ans = -1; // -1: unanswered (for debugging)
};


const long long INF = 1e18;
const int MAXN = 100000;
const int MAXQ = 100000;
const int MAXV = 300000;
const int BLOCK_SIZE = 500;


int N, Q;
map< pair<int, int>, int> m;
int e[MAXV];
int id_left[MAXN], id_right[MAXN]; // edge number of first and last edge of ith polygon
Query queries[MAXQ];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> N;
  int tot = 0;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    id_left[i] = tot;
    id_right[i] = tot + k - 1;
    vector<Point> p(k);
    for (int j = 0; j < k; j++) {
      cin >> p[j].x >> p[j].y;
    }
    for (int j = 0; j < k; j++) {
      pair<int, int> v = {p[(j + 1) % k].y - p[j].y, p[(j + 1) % k].x - p[j].x};
      int g = __gcd(v.first, v.second);
      g = abs(g);
      v.first /= g;
      v.second /= g;
      if (!m.count(v)) {
        int s = (int) m.size();
        m[v] = s;
      }
      e[tot++] = m[v];
    }
  }
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    Query &q = queries[i];
    q.id = i;
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    q.l = id_left[l];
    q.r = id_right[r];
  }
  sort(queries, queries + Q, [](const Query &a, const Query &b) {
    int ba = a.l / BLOCK_SIZE;
    int bb = b.l / BLOCK_SIZE;
    if (ba != bb) {
      return ba < bb;
    }
    return a.r < b.r;
  });
  int l = 0, r = -1;
  int ans = 0; // distinct elements in range
  vector<int> cnt(m.size(), 0);
  function<void(int)> add = [&](int i) {
    if (cnt[e[i]] == 0) {
      ans++;
    }
    cnt[e[i]]++;
  };
  function<void(int)> remove = [&](int i) {
    cnt[e[i]]--;
    if (cnt[e[i]] == 0) {
      ans--;
    }
  };
  for (int i = 0; i < Q; i++) {
    Query &q = queries[i];
    while (r < q.r) {
      add(++r);
    }
    while (r > q.r) {
      remove(r--);
    }
    while (l > q.l) {
      add(--l);
    }
    while (l < q.l) {
      remove(l++);
    }
    q.ans = ans;
  }
  sort(queries, queries + Q, [](const Query &a, const Query &b) {
    return a.id < b.id;
  });
  for (int i = 0; i < Q; i++) {
    const auto &q = queries[i];
    cout << q.ans << '\n';
  }
  // cerr << "gcd(4, -6) = " << __gcd(4, -6) << '\n';
  // cerr << "gcd(-4, 6) = " << __gcd(-4, 6) << '\n';
  // cerr << "gcd(-4, -6) = " << __gcd(-4, -6) << '\n';


  return 0;
}