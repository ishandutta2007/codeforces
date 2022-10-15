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

const int inf = int(1e9);

struct SegTree {
  struct node {
    int val = inf;
    int tag = 0;
    void modify(int x) {
      val += x;
      tag += x;
    }
  };
  int n;
  vector<node> tree;
  node unite(node x, node y) {
    node res;
    res.val = min(x.val, y.val);
    return res;
  }

  void pull(int v, int rv) {
    tree[v] = unite(tree[v + 1], tree[rv]);
  }

  void push(int v, int rv) {
    if (tree[v].tag != 0) {
      tree[v + 1].modify(tree[v].tag);
      tree[rv].modify(tree[v].tag);
      tree[v].tag = 0;    
    } 
  }

  void modify(int v, int l, int r, int ll, int rr, int del) {
    if (l >= ll && rr >= r) {
      tree[v].modify(del);
      return;
    }
    int mid = (l + r) >> 1;
    int rv = v + ((mid - l + 1) << 1);
    push(v, rv);
    if (mid >= ll) {
      modify(v + 1, l, mid, ll, rr, del);
    } 
    if (mid < rr) {
      modify(rv, mid + 1, r, ll, rr, del);
    }
    pull(v, rv);
  }

  void modify(int ll, int rr, int del) {
    assert(ll >= 0 && ll <= rr && rr < n);
    modify(0, 0, n - 1, ll, rr, del);
  }

  SegTree(int _n) : n(_n) {
    tree.resize((n << 1) - 1);
  }

  int get() {
    return tree[0].val;
  }
}; 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int, int> mp;
  int size = 0;
  for (int i = 0; i < n; ++i) {
    if (!mp.count(a[i])) {
      mp[a[i]] = size++;
    }
    a[i] = mp[a[i]];
  }
  
  vector<int> dp(n + 1, inf);
  dp[0] = 0;
  for (int it = 0; it < k; ++it) {
    SegTree st(n + 1);
    vector<int> lst(size, -1);
    vector<int> new_dp(n + 1, inf);
    for (int i = it; i < n; ++i) {
      st.modify(i, i, -inf + dp[i]);
      if (lst[a[i]] != -1) {
        st.modify(0, lst[a[i]], i - lst[a[i]]);       
      }
      new_dp[i + 1] = st.get();
      lst[a[i]] = i;
    }
    swap(dp, new_dp);
    debug(dp);
  }
  cout << dp[n] << '\n';
}