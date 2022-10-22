//
// Created by TigerZhao on 2020-09-02.
//

#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  queue<pair<int, int>> nodes;
  int level = 0;
  pair<int, int> node = make_pair(n, level);
  vector<bool> vis(20000 + 1); // add a visited array
  while (node.first != m) {
    if(node.first > 0 && !vis[node.first - 1]) { // check that it doesn't go negative
      vis[node.first - 1] = true; // set the new number to visited
      nodes.push(make_pair(node.first - 1, node.second + 1));
    }
    if (node.first < m && !vis[node.first * 2]) {
      vis[node.first * 2] = true; // set the new number to visited
      nodes.push(make_pair(node.first * 2, node.second + 1));
    }
    node = nodes.front();
    nodes.pop();
  }
  cout << node.second << endl;
  return 0;
}