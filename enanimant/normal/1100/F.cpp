/*
 * author:  ADMathNoob
 * created: 07/19/21 10:57:05
 * problem: https://codeforces.com/contest/1100/problem/F
 */

/*
g++ 1100F.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1100F.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

namespace xor_basis {

using Basis = vector<int>;

bool Representable(int v, const Basis& basis) {
  for (int w : basis) {
    int f = (1 << __lg(w));
    if (v & f) {
      v ^= w;
    }
  }
  return (v == 0);
}

bool Insert(int v, Basis& basis) {
  for (int w : basis) {
    int f = (1 << __lg(w));
    if (v & f) {
      v ^= w;
    }
  }
  if (v == 0) {
    return false;
  }
  basis.push_back(v);
  return true;
}

Basis Merge(const Basis& a, const Basis& b) {
  Basis res = a;
  for (int v : b) {
    Insert(v, res);
  }
  return res;
}
  
}

using namespace xor_basis;

int n;
vector<int> a;
vector<int> L, R;

vector<Basis> basis;
vector<int> ans;

void Solve(int l, int r, const vector<int>& qids) {
  if (l == r) {
    for (int id : qids) {
      ans[id] = a[l];
    }
    return;
  }
  int y = (l + r) >> 1;
  for (int i = y; i >= l; i--) {
    basis[i].clear();
    if (i < y) {
      basis[i] = basis[i + 1];
    }
    Insert(a[i], basis[i]);
  }
  for (int i = y + 1; i <= r; i++) {
    basis[i].clear();
    if (i > y + 1) {
      basis[i] = basis[i - 1];
    }
    Insert(a[i], basis[i]);
  }
  vector<int> left, right;
  for (int id : qids) {
    if (R[id] <= y) {
      left.push_back(id);
    } else if (L[id] > y) {
      right.push_back(id);
    } else {
      Basis b = Merge(basis[L[id]], basis[R[id]]);
      int res = 0;
      for (int v : b) {
        res = max(res, res ^ v);
      }
      ans[id] = res;
    }
  }
  Solve(l, y, left);
  Solve(y + 1, r, right);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int tt;
  cin >> tt;
  L.resize(tt);
  R.resize(tt);
  ans.resize(tt);
  for (int qq = 0; qq < tt; qq++) {
    cin >> L[qq] >> R[qq];
    --L[qq]; --R[qq];
  }
  vector<int> ids(tt);
  iota(ids.begin(), ids.end(), 0);
  basis.resize(n);
  Solve(0, n - 1, ids);
  for (int i = 0; i < tt; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}