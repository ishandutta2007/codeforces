#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 1e15;

struct segment_tree {
  int tail = 0;
  ll maxpos = INF;
  vector <pair <int, int>> t;
  vector <int> left, right;
  segment_tree() {
    addvertex();
    tail++;
  }
  void addvertex() {
    left.push_back(-1);
    right.push_back(-1);
    t.push_back({0, -1});
  }
  void push(int v) {
    if (left[v] == -1) {
      left[v] = tail++;
      addvertex();
      right[v] = tail++;
      addvertex();
    }
  }
  pair <int, int> get(int v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
      return {0, -1};
    if (l == tl && r == tr)
      return t[v];
    if (t[v] == make_pair(0, -1))
      return t[v];
    ll tm = (tl + tr) / 2;
    pair <int, int> x = get(left[v], tl, tm, l, min(r, tm));
    pair <int, int> y = get(right[v], tm + 1, tr, max(l, tm + 1), r);
    return max(x, y);
  }
  void upd(int v, ll tl, ll tr, ll pos, pair <int, int> val) {
    if (tl == tr) {
      t[v] = val;
      return;
    }
    push(v);
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
      upd(left[v], tl, tm, pos, val);
    else
      upd(right[v], tm + 1, tr, pos, val);
    t[v] = max(t[left[v]], t[right[v]]);
  }
  pair <int, int> get(ll l, ll r) {
    return get(0, 1, maxpos, max(1ll, l), min(maxpos, r));
  }
  void upd(ll pos, pair <int, int> val) {
    upd(0, 1, maxpos, pos, val);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector <ll> h(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  segment_tree st;
  vector <int> ans(n), p(n);
  for (int i = 0; i < n; i++) {
    pair <int, int> val1 = st.get(0, h[i] - d);
    pair <int, int> val2 = st.get(h[i] + d, INF);
    pair <int, int> val = max(val1, val2);
    val.first++;
    ans[i] = val.first, p[i] = val.second;
    st.upd(h[i], {ans[i], i});
  }
  int id = max_element(ans.begin(), ans.end()) - ans.begin();
  cout << ans[id] << '\n';
  vector <int> answer;
  while (id != -1) {
    answer.push_back(id);
    id = p[id];
  }
  reverse(answer.begin(), answer.end());
  for (int x : answer)
    cout << x + 1 << ' ';
  return 0;
}