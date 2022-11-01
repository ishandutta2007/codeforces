#include <bits/stdc++.h>

using namespace std;

int md;

inline void add(int& a, const int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int inverse(int a) {
  a %= md;
  if (a < 0) {
    a += md;
  }
  int b = md, u = 0, v = 1;
  while (a > 0) {
    int q = b / a;
    b -= q * a;
    swap(a, b);
    u -= q * v;
    swap(u, v);
  }
  assert(b == 1);  // b = gcd(a, md)
  if (u < 0) {
    u += md;
  }
  return u;
}

const int Q = 100005;
const int X = 100005;
const array<int, 9> I = {0, 0, 0, 0, 0, 0, 0, 0, 0};

vector<pair<int, int>> f;
int F;
vector<vector<int>> POW;
vector<int> INV;

class SegTree {
 public:
  struct Node {
    int mu = 1;
    array<int, 9> s = I;
    // vector<int> s = vector<int>(F, 0); // primes that divide `md`
    int sum = 1;

    void apply(int l, int r, int v, const array<int, 9>& add) {
    // void apply(int l, int r, int v, const vector<int>& add) {
      if (v >= 1) {
        sum = mul(sum, v);
        for (int i = 0; i < F; i++) {
          s[i] += add[i];
          sum = mul(sum, POW[i][add[i]]);
        }
        mu = mul(mu, v);
      } else {
        assert(l == r);
        v = ~v;
        mu = mul(mu, INV[v]);
        sum = mu;
        for (int i = 0; i < F; i++) {
          s[i] += add[i];
          assert(s[i] >= 0);
          sum = mul(sum, POW[i][s[i]]);
        }
      }
    }
  };

  Node unite(const Node& a, const Node& b) const {
    Node res;
    res.sum = a.sum;
    add(res.sum, b.sum);
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    tree[x + 1].apply(l, y, tree[x].mu, tree[x].s);
    tree[z].apply(y + 1, r, tree[x].mu, tree[x].s);
    tree[x].mu = 1;
    fill(tree[x].s.begin(), tree[x].s.end(), 0);
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<Node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  Node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    Node res;
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else if (ll > y) {
      res = get(z, y + 1, r, ll, rr);
    } else {
      res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
    }
    pull(x, z);
    return res;
  }

  template <typename... T>
  void modify(int x, int l, int r, int ll, int rr, const T&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  SegTree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  Node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr < n);
    return get(0, 0, n - 1, ll, rr);
  }

  // due to variadic templates, we cannot also have modify(int p, const T&... v)
  template <typename... T>
  void modify(int ll, int rr, const T&... v) {
    assert(0 <= ll && ll <= rr && rr < n);
    modify(0, 0, n - 1, ll, rr, v...);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n >> md;
  {
    int x = md;
    for (int i = 2; i * i <= md; i++) {
      int e = 0;
      while (x % i == 0) {
        x /= i;
        e += 1;
      }
      if (e > 0) {
        f.emplace_back(i, e);
      }
    }
    if (x > 1) {
      f.emplace_back(x, 1);
    }
  }
  F = (int) f.size();
  assert(F <= 9);
  POW.resize(F);
  for (int i = 0; i < F; i++) {
    const auto [p, _] = f[i];
    POW[i].resize(30 * Q);
    POW[i][0] = 1;
    for (int j = 1; j < 30 * Q; j++) {
      POW[i][j] = mul(POW[i][j - 1], p);
    }
  }
  INV.resize(X);
  for (int x = 1; x < X; x++) {
    if (gcd(x, md) == 1) {
      INV[x] = inverse(x);
    }
  }
  auto Get = [&](int& x) {
    // vector<int> e(F);
    array<int, 9> e = I;
    e.fill(0);
    for (int i = 0; i < F; i++) {
      const auto [p, _] = f[i];
      while (x % p == 0) {
        x /= p;
        e[i] += 1;
      }
    }
    return e;
  };
  SegTree st(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    auto e = Get(a);
    st.modify(i, i, a, e);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int op;
    cin >> op;
    if (op == 1) {
      int L, R, x;
      cin >> L >> R >> x;
      --L; --R;
      auto e = Get(x);
      st.modify(L, R, x, e);
    }
    if (op == 2) {
      int p, x;
      cin >> p >> x;
      --p;
      auto e = Get(x);
      for (int i = 0; i < F; i++) {
        e[i] = -e[i];
      }
      st.modify(p, p, ~x, e);
    }
    if (op == 3) {
      int L, R;
      cin >> L >> R;
      --L; --R;
      auto nd = st.get(L, R);
      cout << nd.sum << '\n';
    }
  }
  return 0;
}