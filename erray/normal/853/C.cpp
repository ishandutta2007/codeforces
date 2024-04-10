// author: erray
#include<bits/stdc++.h>
 
using namespace std;

struct Fenw {
  int n;
  vector<int> tree;

  Fenw(int _n) : n(_n) {
    tree.resize(n + 1);
  }

  int lb(int x) {
    return x & -x;
  }

  void modify(int ind) {
    ++ind;
    while (ind <= n) {
      ++tree[ind];
      ind += lb(ind);
    }
  }

  int get(int ind) {
    ++ind;
    int res = 0;
    while (ind > 0) {
      res += tree[ind];
      ind -= lb(ind);
    }
    return res;
  }
};

 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    b[--x] = i;
  }

  vector<array<int, 5>> a(q);
  vector<long long> add(q);
  auto match = [&](int x) {
    return 1LL * x * (x - 1) / 2;
  };


  for (int i = 0; i < q; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> a[i][j];
      --a[i][j];
      if (j < 2) {
        add[i] += match(a[i][j]);
      } else {
        add[i] += match(n - 1 - a[i][j]);
      }
    }
    a[i][4] = i; 
    
  }

  {
    sort(a.begin(), a.end(), [&](auto x, auto y) {
      return x[1] < y[1];
    });
    
    Fenw act(n);
    int p = 0;
    for (auto[l, d, r, u, id] : a) {
      while (p < d) {
        act.modify(b[p]);
        ++p;  
      }
      add[id] -= match(act.get(l - 1)) + match(p - act.get(r));
    }
  }
  {
    sort(a.begin(), a.end(), [&](auto x, auto y) {
      return x[3] > y[3];
    });
    
    Fenw act(n);
    int p = n - 1;
    for (auto[l, d, r, u, id] : a) {
      while (p > u) {
        act.modify(b[p]);
        --p;  
      }
      add[id] -= match(act.get(l - 1)) + match(act.get(n - 1) - act.get(r));
    }
  }

  for (int i = 0; i < q; ++i) {
    assert(add[i] >= 0);
    cout << match(n) - add[i] << '\n';  
  }
  
}