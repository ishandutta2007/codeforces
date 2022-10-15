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

struct SegTree {
  struct node {
    int mx = 0;
    int mn = 0;
    int tag = 0;
    void modify(int x) {
      tag += x;
      mx += x;
      mn += x;
    }
  };

  node unite(const node& x, const node& y) {
    node res;
    res.mx = max(x.mx, y.mx);
    res.mn = min(x.mn, y.mn);
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

  vector<node> tree;
  int n;

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
  }

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
  
  node get(int ll, int rr) {
    assert(ll >= 0 && rr < n && ll <= rr);
    return get(0, 0, n - 1, ll, rr);
  }

  void modify(int ll, int rr, int x) {
    assert(ll >= 0 && rr < n && ll <= rr);
    modify(0, 0, n - 1, ll, rr, x);    
  }

  SegTree(int _n) : n(_n) {
    tree.resize((n << 1) - 1);
  }
};

string to_string(SegTree::node x) {
  return '(' + to_string(x.mx) + ", " + to_string(x.mn) + ')';
}




int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) {
    return a[x] < a[y];
  });

  SegTree st(n + 1);
  for (int i = 0; i < n; ++i) {
    st.modify(i + 1, n, +1);
  }

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int start = i;
    while (i < n - 1 && a[ord[i + 1]] == a[ord[start]]) {
      ++i;
    }
    debug(i);
    for (int j = start; j <= i; ++j) {
      int ind = ord[j];
      debug(ind);
      auto suf = st.get(ind + 1, n);
      auto pref = st.get(0, ind);
      debug(suf, pref);
      ans[ind] = max(ans[ind], (suf.mx - pref.mn) / 2); 
    }
    for (int j = start; j <= i; ++j) {
      int ind = ord[j];
      st.modify(ind + 1, n, -2);
    }
    for (int j = start; j <= i; ++j) {
      int ind = ord[j];
      debug(ind);
      auto suf = st.get(ind + 1, n);
      auto pref = st.get(0, ind);
      debug(suf, pref);
      ans[ind] = max(ans[ind], -(suf.mn - pref.mx + 1) / 2); 
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}