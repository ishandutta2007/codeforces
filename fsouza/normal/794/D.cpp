#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  map<vector<int>, int> group_of_set;
  vector<int> group_size;
  vector<int> group_of_node(n);
  for (int i = 0; i < n; ++i) {
    adj[i].push_back(i);
    sort(adj[i].begin(), adj[i].end());
    auto it = group_of_set.find(adj[i]);
    if (it != group_of_set.end()) {
      group_of_node[i] = it->second;
      ++group_size[group_of_node[i]];
    } else {
      int group = group_of_set.size();
      group_of_node[i] = group_of_set[adj[i]] = group;
      group_size.push_back(1);
    }
  }

  map<int, int> label_of_group;
  map<int, int> group_of_label;
  vector<bool> mark(n, false);

  bool ok = true;
  int max_label = 0;

  function<void(int, int)> dfs = [&](int v, int p) {
    const int g = group_of_node[v];
    if (label_of_group.find(g) == label_of_group.end()) {
      int parent_label;

      if (p == -1) parent_label = 0;
      else parent_label = label_of_group[group_of_node[p]];

      int chosen_label = INT_MAX;
      for (int l = parent_label - 1; l <= parent_label + 1; ++l) {
        if (group_of_label.find(l) == group_of_label.end()) {
          chosen_label = l;
          break;
        }
      }
      if (chosen_label == INT_MAX) {
        chosen_label = max_label + 1;
        ok = false;
      }

      label_of_group[g] = chosen_label;
      group_of_label[chosen_label] = g;

      max_label = max(max_label, chosen_label);
    }
    mark[v] = true;
    for (int u : adj[v])
      if (!mark[u])
        dfs(u, v);
  };
  dfs(0, -1);

  for (int v = 0; v < n; ++v)
    for (int u : adj[v])
      if (abs(label_of_group[group_of_node[v]] - label_of_group[group_of_node[u]]) > 1)
        ok = false;

  lint expect_edge_count = 0;
  for (int l1 = -n; l1 <= n; ++l1) {
    if (group_of_label.find(l1) != group_of_label.end()) {
      int g1 = group_of_label[l1];
      expect_edge_count += (lint)group_size[g1] * (group_size[g1] - 1) / 2;

      int l2 = l1 + 1;
      if (group_of_label.find(l2) != group_of_label.end()) {
        int g2 = group_of_label[l2];
        expect_edge_count += (lint)group_size[g1] * group_size[g2];
      }
    }
  }

  if (expect_edge_count != m)
    ok = false;

  if (ok) {
    printf("YES\n");
    vector<int> labels(n);
    for (int i = 0; i < n; ++i) {
      labels[i] = label_of_group[group_of_node[i]];
    }
    int minlabel = *min_element(labels.begin(), labels.end());
    for (int i = 0; i < n; ++i) {
      int new_label = labels[i] - minlabel + 1;
      if (i > 0)
        printf(" ");
      printf("%d", new_label);
    }
    printf("\n");
  } else {
    printf("NO\n");
  }

  return 0;
}