#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <climits>

#define INF (INT_MAX/2)
#define MAXN 100000

typedef long long lint;

using namespace std;

vector<int> adj[MAXN];
int parent[MAXN], rank[MAXN], size[MAXN];

int search(int v) {
  if (v == parent[v]) return v;
  return parent[v] = search(parent[v]);
}

void join(int a, int b) {
  a = search(a); b = search(b);
  if (a == b) return;
  if (rank[a] > rank[b]) swap(a, b);
  parent[a] = b;
  size[b] += size[a];
  if (rank[a] == rank[b]) rank[b]++;
}

int getsize(int v) {
  return size[search(v)];
}

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  vector <pair <int, int> > vals;
  vector<int> origval(n, -1);

  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    origval[i] = v;
    vals.push_back(make_pair(v, i));
  }
  sort(vals.rbegin(), vals.rend());

  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y); x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for (int i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 0;
    size[i] = 1;
  }

  lint result = 0;

  for (int j = 0; j < n; j++) {
    int val = vals[j].first;
    int i = vals[j].second;

    lint nnewpath = 0;

    for (int k = 0; k < (int)adj[i].size(); k++) {
      int i2 = adj[i][k];

      if (make_pair(origval[i2], i2) > make_pair(origval[i], i)) {
	if (search(i) != search(i2)) {
	  nnewpath += 2LL * (lint)getsize(i) * getsize(i2);
	  join(i, i2);
	}
      }
    }

    result += nnewpath * val;
  }

  double res = result / (1.0 * n * (n-1.0));

  printf("%f\n", res);

  return 0;
}