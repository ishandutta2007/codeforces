// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 template<typename A, typename B> string to_string(pair<A, B> p);
template<typename A, typename B, typename C> string to_string(tuple<A, B, C> t);
template<typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> t);

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(char c) {
  return string("'") + c + "'";
}

string to_string(const char* c) {
  return to_string(string(c));
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<size_t T> string to_string(bitset<T> bs) {
  return bs.to_string();
}

string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < int(v.size()); ++i) {
    if (i > 0) {
      res += ", ";
    }
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template<typename T> string to_string(T v) {
  string res = "{";
  for (auto& e : v) {
    if (int(res.size()) > 1) {
      res += ", ";
    }
    res += to_string(e);
  }
  res += "}";
  return res;
}

template<typename A, typename B> string to_string(pair<A, B> p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename A, typename B, typename C> string to_string(tuple<A, B, C> t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + '}';
}
template<typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + '}';   
}

void debug_out() {
  cerr << endl;
}

template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << "  " << to_string(H);
  debug_out(T...);
}

#ifdef DEBUG 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) void(37)
#endif

const int inf = int(2e9);
struct SegTree {
  struct node {
    int tag = inf;
    int mx = -1;
    void modify(int x) {
      tag = x;
      mx = x;
    }
  };

  int n;
  vector<node> tree;

  node unite(const node& x, const node& y) {
    node res;
    res.mx = max(x.mx, y.mx);
    return res;
  }

  void push(int v, int rv) {
    if (tree[v].tag != inf) {
      tree[v + 1].modify(tree[v].tag);
      tree[rv].modify(tree[v].tag);
    }
    tree[v].tag = inf;
  }
  
  /*==========================================================================*/

  void pull(int v, int rv) {
    tree[v] = unite(tree[v + 1], tree[rv]);
  }

  void modify(int v, int l, int r, int ll, int rr, int x) {
    if (l >= ll && rr >= r) {
      tree[v].modify(x);
      return;
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, rv);
    if (mid >= ll) {
      modify(v + 1, l, mid, ll, rr, x);
    }
    if (mid < rr) {
      modify(rv, mid + 1, r, ll, rr, x);      
    }
    pull(v, rv);
  };

  node get(int v, int l, int r, int ll, int rr) {
    if (l >= ll && rr >= r) {    
      return tree[v];
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, rv);
    node res;
    if (mid >= ll) {
      if (mid < rr) {
        res = unite(get(v + 1, l, mid, ll, rr), get(rv, mid + 1, r, ll, rr));
      } else {   
        res = get(v + 1, l, mid, ll, rr);
      }
    } else {
      res = get(rv, mid + 1, r, ll, rr);
    }
    return res;
  }

  void modify(int ll, int rr, int x) {
    assert(ll >= 0 && rr < n && ll <= rr);
    modify(0, 0, n - 1, ll, rr, x);
  }

  node get(int ll, int rr) {
    assert(ll >= 0 && rr < n && ll <= rr);  
    return get(0, 0, n - 1, ll, rr);
  }

  SegTree() { }

  SegTree(int _n) : n(_n) {
    tree.resize((n << 1) - 1);
  }
};

void my_assert(bool x) {
  if (!x) {
    cout << "No\n";
    exit(0);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> k(n);
  vector<array<int, 2>> a(n);  
  vector<array<int, 2>> b(n);

  for (int i = 0; i < n; ++i) {
    cin >> k[i];
    cin >> a[i][0] >> a[i][1];
    cin >> b[i][0] >> b[i][1];
  }

  vector<int> all = k;
  all.push_back(-1);
  all.push_back(0);
  all.push_back(m + 1);
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  int size = int(all.size());
  for (int i = 0; i < n; ++i) {
    k[i] = int(lower_bound(all.begin(), all.end(), k[i]) - all.begin());
  }
  
  debug(all, k);
  array<vector<array<int, 2>>, 2> ranges = {a, b};
  for (int j = 0; j < 2; ++j) {
    for (auto&[l, r] : ranges[j]) {
      l = int(lower_bound(all.begin(), all.end(), l) - all.begin());
      r = int(lower_bound(all.begin(), all.end(), r + 1) - all.begin()) - 1;  
      debug(l, r);
      my_assert(l <= r);    
    }
  }

  debug(ranges);
  debug(k);
  vector<vector<bool>> dp(n, vector<bool>(2));
  vector<vector<bool>> can(n, vector<bool>(2));
  vector<vector<int>> go(n, vector<int>(2));
  vector<vector<int>> pref(n + 1, vector<int>(2));  
  SegTree emp(size);
  array<SegTree, 2> ks = {emp, emp};
  for (int j = 0; j < 2; ++j) {
    ks[j].modify(1, 1, 0);
  }

  for (int i = 0; i < n; ++i) {
    /*
    #ifdef DEBUG
    for (int j = 0; j < 2; ++j) {
      for (int ind = 0; ind < size; ++ind) {
        debug(j, ind, ks[j].get(ind, ind).mx);
      }
    }
    #endif
    */
    for (int me = 0; me < 2; ++me) {
      if (ranges[me][i][0] > k[i] || ranges[me][i][1] < k[i]) {
        continue;
      }
      can[i][me] = true;
      int ot = me ^ 1;
      int take = ks[ot].get(ranges[ot][i][0], ranges[ot][i][1]).mx;
      --take;
      debug(i, me, take, ranges[ot][i]);
      if (take == -2 || pref[i][me] - pref[take + 1][me] != (i - take - 1)) {
        continue;
      }
      dp[i][me] = true;
      go[i][me] = take;
    }

    for (int j = 0; j < 2; ++j) {
      pref[i + 1][j] = pref[i][j] + can[i][j];
      if (dp[i][j]) {
        ks[j].modify(k[i], k[i], i + 1);  
      }
      if (ranges[j][i][0] > 0) {
        ks[j].modify(0, ranges[j][i][0] - 1, -1);
      }
      if (ranges[j][i][1] < size - 1) {
        ks[j].modify(ranges[j][i][1] + 1, size - 1, -1);
      }
    }
  }
                        
  debug(dp);   
  debug(go);
  debug(can);

  my_assert(dp[n - 1][0] || dp[n - 1][1]);
  int take = dp[n - 1][1];
  int till = go[n - 1][take];
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; --i) {
    if (till == i) {
      take ^= 1;
      till = go[i][take];
    }
    ans[i] = take;
  } 
  cout << "Yes\n";
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }

}