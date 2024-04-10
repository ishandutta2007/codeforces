// author: erray
#include<bits/stdc++.h>
 
using namespace std;

template<typename T, typename F> string to_string(pair<T, F> p);
string to_string(string s) {
  return '"' + s + '"';
}
string to_string(char c) {
  return (string) "'" + c + "'";
}
string to_string(const char* p) {
  return to_string((string) p);
}
string to_string(bool B) {
  return (B ? "true" : "false");
}
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < (int) v.size(); ++i) {
    if ((int) res.size() > 1) res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template<size_t T> string to_string(bitset<T> bs) {
  return bs.to_string();
}
template<typename T> string to_string(T v) {
  string res = "{";
  for (auto& el : v) {
    if ((int) res.size() > 1) res += ", ";
    res += to_string(el);
  }
  res += "}";
  return res;
}
template<typename T, typename F> string to_string(pair<T, F> p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
void debug_out() {
  cerr << endl;
}
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" , debug_out(__VA_ARGS__)
#else
#define debug(...) (void) 37
#endif

template<typename T, typename F = function<T(const T&, const T&)>> class bit {
  public:
  vector<T> tree;
  F cal;
  int sz;
  int lb(int x) { return x & -x; }
  void modify(int ind, T val) {
    ++ind;
    while (ind < sz) {
      tree[ind] = cal(tree[ind], val);
      ind += lb(ind);
    }
  }
  bit(vector<T> v, T uneff, F _cal) : cal(_cal) {
    sz = (int) v.size() + 1;
    tree.resize(sz, uneff);
    for (int i = 0; i < (int) v.size(); ++i) modify(i, v[i]);
  }
  T get(int ind) {
    ++ind;
    T res = tree[0];
    while (ind) {
      res = cal(res, tree[ind]);
      ind -= lb(ind);
    }
    return res;
  }
  void clear() {
    fill(tree.begin(), tree.end(), tree[0]);
  }
};

const int tot = (int) 1e6 + 1; 

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> h(2);
  for (int i = 0; i < n; ++i) {
   int x, l, r;
   cin >> x >> l >> r;
   h[l != 0].emplace_back(x, (l > 0 ? l : r));
  }
  int temp = 0;
  vector<pair<int, int>> cut(tot, make_pair(-1, -1));
  for (int i = 0; i < m; ++i) {
    int y, l, r;
    cin >> y >> l >> r;
    temp += (l == 0 && r == tot - 1);
    cut[y] = make_pair(l, r);
  }
  cut[0] = cut[tot - 1] = make_pair(0, tot - 1);  
  debug(h);
  vector<vector<int>> del(tot);
  bit<int> t(vector<int>(tot, 0), 0, [&](int x, int y) {
    return x + y;
  });
  for (auto el : h[0]) {  
    del[el.second].push_back(el.first);    
    t.modify(el.first, 1);
  }
  
  long long ans = 1;
  for (int i = 1; i < tot; ++i) {
    if (cut[i].first != -1) ans += t.get(cut[i].second) - (cut[i].first ? t.get(cut[i].first - 1) : 0);
    for (auto el : del[i]) {
      t.modify(el, -1);
    }   
    del[i].clear();
  }
  t.clear();
  
  for (auto el : h[1]) {
    del[el.second].push_back(el.first);
    t.modify(el.first, 1);
  }

  for (int i = tot - 2; i >= 0; --i) {
    if (cut[i].first != -1) ans += t.get(cut[i].second) - (cut[i].first ? t.get(cut[i].first - 1) : 0);
    for (auto el : del[i]) {
      t.modify(el, -1);
    }
  }
  cout << ans + temp << '\n';
}