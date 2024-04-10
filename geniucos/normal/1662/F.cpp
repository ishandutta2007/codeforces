#include <bits/stdc++.h>

#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;

using namespace std;

struct segment_tree {
  struct data {
    int ipp = -1e6, i = -1, jmp = 1e6, j = -1;
  };
  data combine(data dl, data dr) {
    return { max(dl.ipp, dr.ipp), dl.ipp > dr.ipp ? dl.i : dr.i, min(dl.jmp, dr.jmp), dl.jmp < dr.jmp ? dl.j : dr.j };
  }
  int n, h;
  vector<data> t;
  segment_tree(int n = 0): n(n), h(32 - __builtin_clz(n)), t(2 * n) {}
  void build(int x) {
    while (x >>= 1)
      t[x] = combine(t[x << 1], t[x << 1 | 1]);
  }
  void setValue(int i, data d) {
    i += n;
    t[i] = d;
    build(i);
  }
  data query(int l, int r) {
    l += n, r += n;
    data dl = data(), dr = data();
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        dl = combine(dl, t[l++]);
      if (r & 1)
        dr = combine(t[--r], dr);
    }
    return combine(dl, dr);
  }
};

int t, n, a, b, d[200100], cp[200100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> t;
  while (t--) {
    cin >> n >> a >> b, a--, b--;
    segment_tree st(n);
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      cp[i] = p;
      st.setValue(i, { i + p, i, i - p, i });
    }
    queue<int> q({a});
    d[a] = 0;
    st.setValue(a, segment_tree::data());
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      segment_tree::data qd;
      while ((qd = st.query(max(0, i - cp[i]), i)).ipp >= i) {
        d[qd.i] = d[i] + 1;
        st.setValue(qd.i, segment_tree::data());
        q.push(qd.i);
      }
      while ((qd = st.query(i + 1, min(n, i + cp[i] + 1))).jmp <= i) {
        d[qd.j] = d[i] + 1;
        st.setValue(qd.j, segment_tree::data());
        q.push(qd.j);
      }
    }
    cout << d[b] << "\n";
  }
}