// September 27, 2020
// https://codeforces.com/contest/1416/problem/C

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1416C.cpp && a
*/


#include <bits/stdc++.h>

using namespace std;


struct Fenwick {
  int n;
  vector<int> fenw;

  Fenwick(int _n) : n(_n) {
    fenw.resize(n + 1, 0);
  }

  int get(int x) {
    int res = 0;
    for (x++; x > 0; x -= x & -x) {
      res += fenw[x];
    }
    return res;
  }

  void modify(int x, int v) {
    for (x++; x <= n; x += x & -x) {
      fenw[x] += v;
    }
  }
};


inline long long Count(const vector<int>& a) {
  int n = (int) a.size();
  auto as = a;
  sort(as.begin(), as.end());
  as.resize(unique(as.begin(), as.end()) - as.begin());
  int m = (int) as.size();
  Fenwick ft(m);
  long long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    int pos = (int) (lower_bound(as.begin(), as.end(), a[i]) - as.begin());
    res += ft.get(pos - 1);
    ft.modify(pos, 1);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<int> a(n);
  const int BITS = 30;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto v = a;
  int x = 0;
  vector<int> starts = {0, n};
  auto CountGroup = [&](const vector<int>& v, int b) {
    long long res = 0;
    for (int s = 0; s < (int) starts.size() - 1; s++) {
      int cnt = 0;
      for (int i = starts[s]; i < starts[s + 1]; i++) {
        if (v[i] & (1 << b)) {
          cnt += 1;
        } else {
          res += cnt;
        }
      }
    }
    return res;
  };
  for (int b = BITS - 1; b >= 0; b--) {
    long long res = CountGroup(v, b);
    for (int i = 0; i < n; i++) {
      v[i] ^= (1 << b);
    }
    long long res2 = CountGroup(v, b);
    if (res2 < res) {
      x |= (1 << b);
    } else {
      for (int i = 0; i < n; i++) {
        v[i] ^= (1 << b);
      }
    }
    vector<int> added;
    vector<int> new_v = v;
    for (int s = 0; s < (int) starts.size() - 1; s++) {
      vector<int> zeros, ones;
      for (int i = starts[s]; i < starts[s + 1]; i++) {
        if (v[i] & (1 << b)) {
          ones.push_back(i);
        } else {
          zeros.push_back(i);
        }
      }
      int p = starts[s];
      for (int i : zeros) {
        new_v[p++] = v[i];
      }
      if (!zeros.empty() && !ones.empty()) {
        added.push_back(p);
      }
      for (int i : ones) {
        new_v[p++] = v[i];
      }
    }
    swap(v, new_v);
    vector<int> new_starts;
    int p = 0;
    for (int i : starts) {
      while (p < (int) added.size() && added[p] < i) {
        new_starts.push_back(added[p++]);
      }
      new_starts.push_back(i);
    }
    while (p < (int) added.size()) {
      new_starts.push_back(added[p++]);
    }
    swap(starts, new_starts);
    assert(is_sorted(starts.begin(), starts.end()));
  }
  for (int i = 0; i < n; i++) {
    a[i] ^= x;
  }
  cout << Count(a) << ' ' << x << '\n';


  return 0;
}