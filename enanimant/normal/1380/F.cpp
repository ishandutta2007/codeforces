// July 12, 2020
// https://codeforces.com/contest/1380/problem/F

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MOD = 998244353;

struct Mat {
  long long a[2][2];
  
  Mat() {
  }
  
  Mat(int aa, int b, int c, int d) {
    a[0][0] = aa;
    a[0][1] = b;
    a[1][0] = c;
    a[1][1] = d;
  }
};

void multiply(const Mat& A, const Mat& B, Mat& C) {
  // for (int i = 0; i < 2; i++) {
  //   for (int j = 0; j < 2; j++) {
  //     cerr << C.a[i][j] << ' ';
  //   }
  //   cerr << '\n';
  // }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      C.a[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        C.a[i][j] += A.a[i][k] * B.a[k][j] % MOD;
        C.a[i][j] %= MOD;
      }
    }
  }
}


struct SegTree {
  int n;
  vector<Mat> tree;
  
  void pull(int x, int z) {
    multiply(tree[z], tree[x + 1], tree[x]);
  }
  
  void build(int x, int l, int r, const vector<Mat>& v) {
    // cerr << "building from node " << x << '\n';
    // cerr << x << ' ' << l << ' ' << r << '\n';
    if (l == r) {
      tree[x] = v[l];
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }
  
  void modify(int x, int l, int r, int p, const Mat& v) {
    if (l == r) {
      tree[x] = v;
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (p <= y) {
      modify(x + 1, l, y, p, v);
    } else {
      modify(z, y + 1, r, p, v);
    }
    pull(x, z);
  }
  
  SegTree(const vector<Mat>& v) {
    n = (int) v.size();
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }
  
  void modify(int p, const Mat& v) {
    modify(0, 0, n - 1, p, v);
  }
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int n, m;
  cin >> n >> m;
  vector<int> c(n), d(n);
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    c[i] = ch - '0';
    d[i] = ((i > 0 && c[i - 1] == 1) ? 9 - c[i] : 0);
  }
  vector<Mat> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = Mat(c[i] + 1, d[i], 1, 0);
  }
  SegTree st(a);
  while (m--) {
    int i, y;
    cin >> i >> y;
    i--;
    c[i] = y;
    d[i] = ((i > 0 && c[i - 1] == 1) ? 9 - c[i] : 0);
    st.modify(i, Mat(c[i] + 1, d[i], 1, 0));
    if (i + 1 < n) {
      d[i + 1] = (c[i] == 1 ? 9 - c[i + 1] : 0);
      st.modify(i + 1, Mat(c[i + 1] + 1, d[i + 1], 1, 0));
    }
    Mat A = st.tree[0];
    cout << A.a[0][0] << '\n';
  }
  
  
  return 0;
}