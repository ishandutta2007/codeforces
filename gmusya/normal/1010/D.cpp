#include <iostream>
#include <vector>

using namespace std;

int true_ans;

struct scheme {
  string type;
  int left_kid, right_kid;
  int parent;
  int adjacent;
  int val;
  int ans;
};

vector <scheme> g;

void dfs(int v) {
  if (g[v].type == "IN")
    return;
  if (g[v].type == "NOT") {
    dfs(g[v].left_kid);
    g[v].val = (g[g[v].left_kid].val ^ 1);
    return;
  }
  dfs(g[v].left_kid);
  dfs(g[v].right_kid);
  if (g[v].type == "AND")
    g[v].val = (g[g[v].left_kid].val & g[g[v].right_kid].val);
  if (g[v].type == "OR")
    g[v].val = (g[g[v].left_kid].val | g[g[v].right_kid].val);
  if (g[v].type == "XOR")
    g[v].val = (g[g[v].left_kid].val ^ g[g[v].right_kid].val);
}

void dfs1(int v) {
  if (g[g[v].parent].type == "NOT")
    g[v].ans = g[g[v].parent].ans;
  else {
    int val0 = 1 - g[v].val;
    int val1;
    if (g[g[v].parent].left_kid == v)
      val1 = g[g[g[v].parent].right_kid].val;
    else
      val1 = g[g[g[v].parent].left_kid].val;
    int newval;
    if (g[g[v].parent].type == "AND")
      newval = (val0 & val1);
    if (g[g[v].parent].type == "OR")
      newval = (val0 | val1);
    if (g[g[v].parent].type == "XOR")
      newval = (val0 ^ val1);
    if (newval == g[g[v].parent].val)
      g[v].ans = true_ans;
    else
      g[v].ans = g[g[v].parent].ans;
  }
  if (g[v].type == "IN")
    return;
  if (g[v].type == "NOT") {
    dfs1(g[v].left_kid);
    return;
  }
  dfs1(g[v].left_kid);
  dfs1(g[v].right_kid);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i].type;
    if (g[i].type == "IN")
      cin >> g[i].val;
    else if (g[i].type == "NOT") {
      cin >> g[i].left_kid;
      g[i].left_kid--;
      g[g[i].left_kid].parent = i;
    }
    else {
      cin >> g[i].left_kid >> g[i].right_kid;
      g[i].left_kid--, g[i].right_kid--;
      g[g[i].left_kid].adjacent = g[i].right_kid;
      g[g[i].right_kid].adjacent = g[i].left_kid;
      g[g[i].left_kid].parent = i;
      g[g[i].right_kid].parent = i;
    }
  }
  dfs(0);
  true_ans = g[0].val;
  g[0].ans = 1 - true_ans;
  dfs1(g[0].left_kid);
  dfs1(g[0].right_kid);
  for (int i = 0; i < n; i++)
    if (g[i].type == "IN")
      cout << g[i].ans;
  return 0;
}