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

struct node_t {
  string op;
  int value, a, b;

  int inv_root;
};

void dfs0(node_t &v, vector<node_t> &tree) {
  if (v.op == "IN") {
  } else if (v.op == "NOT") {
    dfs0(tree[v.a], tree);
    v.value = !tree[v.a].value;
  } else {
    dfs0(tree[v.a], tree);
    dfs0(tree[v.b], tree);
    int a = tree[v.a].value, b = tree[v.b].value;
    if (v.op == "AND") v.value = a && b;
    else if (v.op == "OR") v.value = a || b;
    else v.value = (a ^ b);
  }
}

void dfs1(node_t &v, vector<node_t> &tree) {
  if (v.op == "IN") {
  } else if (v.op == "NOT") {
    tree[v.a].inv_root = v.inv_root;
    dfs1(tree[v.a], tree);
  } else {
    int a = !tree[v.a].value, b = tree[v.b].value;
    assert(v.a != v.b);
    int value;
    if (v.op == "AND") value = a && b;
    else if (v.op == "OR") value = a || b;
    else value = (a ^ b);
    if (value == v.value) tree[v.a].inv_root = tree[0].value;
    else tree[v.a].inv_root = v.inv_root;

    a = tree[v.a].value, b = !tree[v.b].value;
    if (v.op == "AND") value = a && b;
    else if (v.op == "OR") value = a || b;
    else value = (a ^ b);
    if (value == v.value) tree[v.b].inv_root = tree[0].value;
    else tree[v.b].inv_root = v.inv_root;

    dfs1(tree[v.a], tree);
    dfs1(tree[v.b], tree);
  }
}

string read_string() {
  char *str;
  scanf("%ms", &str);
  string result(str);
  free(str);
  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<node_t> tree(n);
  for (int i = 0; i < n; ++i) {
    node_t &v = tree[i];
    v.op = read_string();
    if (v.op == "IN") scanf("%d", &v.value);
    else if (v.op == "NOT") scanf("%d", &v.a), --v.a;
    else scanf("%d %d", &v.a, &v.b), --v.a, --v.b;
  }
  dfs0(tree[0], tree);
  tree[0].inv_root = !tree[0].value;
  dfs1(tree[0], tree);
  for (int i = 0; i < n; ++i) {
    if (tree[i].op == "IN") {
      printf("%d", tree[i].inv_root);
    }
  }
  printf("\n");
  return 0;
}