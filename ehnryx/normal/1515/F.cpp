#include <bits/stdc++.h>
using namespace std;

// START #include "../../../lca/data_structure/leftist_tree.h"

template <typename T, class Compare = less<>>
struct leftist_tree {
  struct leftist_node {
    T value;
    int size;
    leftist_node *left, *right;
    leftist_node(const T& val):
      value(val), size(1), left(nullptr), right(nullptr) {}
  };
  leftist_node *root;
  leftist_tree(): root(nullptr) {}
  bool empty() const { return root == nullptr; }
  int size() const { return empty() ? 0 : root->size; }
  const T& top() const { return root->value; }
  void push(const T& v) {
    root = merge(root, new leftist_node(v));
  }
  void pop() {
    leftist_node *new_root = merge(root->left, root->right);
    delete root;
    root = new_root;
  }
  void merge(leftist_tree<T, Compare>& o) {
    root = merge(root, o.root);
    o.root = nullptr;
  }
  leftist_node* merge(leftist_node *a, leftist_node *b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    if (Compare()(b->value, a->value)) swap(a, b);
    a->right = merge(a->right, b);
    a->size = 1 + a->right->size + (a->left == nullptr ? 0 : a->left->size);
    if (a->left == nullptr || a->left->size < a->right->size) {
      swap(a->left, a->right);
    }
    return a;
  }
};

// END #include "../../../lca/data_structure/leftist_tree.h"

constexpr char nl = '\n';
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, x;
  cin >> n >> m >> x;
  vector<ll> have(n + 1, -1);
  for(int i=1; i<=n; i++) {
    cin >> have[i];
  }
  if(accumulate(begin(have) + 1, end(have), (ll)0) < (ll)x * (n-1)) {
    cout << "NO" << nl;
    return 0;
  }

  vector<int> dsu(n + 1, -1);
  function<int(int)> find = [&](int i) {
    if(dsu[i] == -1) return i;
    return dsu[i] = find(dsu[i]);
  };
  function<bool(int,int)> link = [&](int i, int j) {
    if(find(i) == find(j)) return false;
    dsu[find(j)] = find(i);
    return true;
  };

  vector<vector<pair<int,int>>> adj(n + 1);
  for(int i=1; i<=m; i++) {
    int a, b;
    cin >> a >> b;
    if(link(a, b)) {
      adj[a].emplace_back(b, i);
      adj[b].emplace_back(a, i);
    }
  }

  vector<int> parent(n + 1), pedge(n + 1);
  vector<leftist_tree<pair<ll,int>,greater<>>> children(n + 1);
  function<void(int)> init_tree = [&](int u) {
    for(auto [v, i] : adj[u]) {
      parent[v] = u;
      pedge[v] = i;
      adj[v].erase(std::find(begin(adj[v]), end(adj[v]), pair(u, i)));
      init_tree(v);
      children[u].push(pair(have[v], v));
    }
  };
  init_tree(1);

  vector<int> ans;
  vector<bool> done(n + 1);
  priority_queue<pair<ll,int>> most;
  for(int i=1; i<=n; i++) {
    most.emplace(have[i], i);
  }
  fill(begin(dsu), end(dsu), -1);

  function<void(int,int)> connect = [&](int a, int b) {
    done[b] = true;
    children[a].merge(children[b]);
    have[a] += have[b] - x;
    assert(have[a] >= 0);
    link(a, b);
    ans.push_back(pedge[b]);
    most.emplace(have[a], a);
    if(parent[a]) {
      children[parent[a]].push(pair(have[a], a));
    }
  };

  while(size(ans) < n-1) {
    assert(!most.empty());
    auto [value, u] = most.top();
    most.pop();
    if(done[u] || value != have[u]) continue;
    while(!children[u].empty() && done[children[u].top().second]) {
      children[u].pop();
    }

    ll up = have[find(parent[u])];
    ll down = children[u].empty() ? -0x3f3f3f3f3f3f3f3f : children[u].top().first;
    if(up > down) {
      connect(find(parent[u]), u);
    } else {
      connect(u, children[u].top().second);
    }
  }

  cout << "YES" << nl;
  for(int it : ans) {
    cout << it << nl;
  }

  return 0;
}