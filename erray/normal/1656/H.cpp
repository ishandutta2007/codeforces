// author: erray
#include <bits/stdc++.h>

using namespace std;

typedef __int128 int128;
istream& operator>>(istream& in, int128& n) {
  string s;
  in >> s;
  n = 0;
  for (char c : s) {
    n *= 10;
    n += c - '0'; 
  }     
  return in;
}

string to_string(int128 n) {
  string res;
  if (n == 0) {
    res = "0";
  } else {
    bool neg = n < 0;
    while (n != 0) {
      res += char('0' + n % 10);
      n /= 10;
    }
    if (neg) {
      res += '-';
    }
    reverse(res.begin(), res.end());
  }
  return res;
}

ostream& operator<<(ostream& out, int128 n) {
  out << to_string(n);    
  return out;
}

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

int128 __lcm(int128 x, int128 y) {
  return x / __gcd(x, y) * y;
}

struct SegTree {
  int n;
  vector<int128> tree;
  SegTree(int _n = 0) : n(_n) {
    tree.resize(n << 1, 1);
  }

  void modify(int p, int128 x) {
    assert(0 <= p && p < n);
    for (tree[p += n] = x; p > 1; p >>= 1) {
      tree[p >> 1] = __lcm(tree[p], tree[p ^ 1]);
    }
  }

  int128 get() {
    int128 res = 1;
    for (int l = n, r = n * 2; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        res = __lcm(res, tree[l++]);
      }
      if (r & 1) {
        res = __lcm(res, tree[--r]);
      }
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    array<int, 2> S;
    cin >> S[0] >> S[1];
    array<vector<int128>, 2> A;
    for (int j = 0; j < 2; ++j) {
      A[j].resize(S[j]);
      for (int i = 0; i < S[j]; ++i) {
        cin >> A[j][i];
      }
    }  

    debug(A);
    vector<SegTree> st(S[0] + S[1]);
    for (int i = 0; i < S[0]; ++i) {
      st[i] = SegTree(S[1]);
    }
    for (int i = 0; i < S[1]; ++i) {
      st[i + S[0]] = SegTree(S[0]);
    }
    for (int i = 0; i < S[0]; ++i) {
      for (int j = 0; j < S[1]; ++j) {
        int128 g = __gcd(A[0][i], A[1][j]);
        st[i].modify(j, g);
        st[j + S[0]].modify(i, g);
      }
    }

    auto G = [&](int x) {
      int t = x >= S[0];
      return array{t, x - t * S[0]};
    };

    vector<bool> r(S[0] + S[1]);
    queue<int> que;
    for (int i = 0; i < S[0] + S[1]; ++i) {
      auto[t, x] = G(i);
      if (st[i].get() != A[t][x]) {
        que.push(i);
        r[i] = true;
      }  
    }

    auto left = A;
    while (!que.empty()) {
      int id = que.front();
      que.pop();
      auto[t, ind] = G(id);
      left[t].erase(find(left[t].begin(), left[t].end(), A[t][ind]));
      for (int i = 0; i < S[t ^ 1]; ++i) {
        int x = i + (t ^ 1) * S[0];
        if (r[x]) {
          continue;
        }
        st[x].modify(ind, 1);
        if (st[x].get() != A[t ^ 1][i]) {
          que.push(x);
          r[x] = true;
        }
      }
    }

    if (left[0].empty() || left[1].empty()) {
      cout << "NO\n";
    } else {
      cout << "YES\n" << int(left[0].size()) << ' ' << int(left[1].size()) << '\n';
      for (int i = 0; i < 2; ++i) {
        for (auto e : left[i]) {     
          cout << e << ' ';
        }
        cout << '\n';
      }
    }
  }
  return 0;
}