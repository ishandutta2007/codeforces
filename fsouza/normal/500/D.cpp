#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 100000

using namespace std;

typedef long long lint;

vector<int> adj[MAXN];
int height[MAXN], sts[MAXN];
int a[MAXN-1], b[MAXN-1], len[MAXN-1];

void dfs(int v, int p, int h) {
  height[v] = h;
  sts[v] = 1;

  for (int u: adj[v])
    if (u != p) {
      dfs(u, v, h+1);
      sts[v] += sts[u];
    }
}

lint choose(lint a, lint b) {
  if (b < 0 || b > a) return 0;
  lint ret = 1;
  for (lint i = 1; i <= b; i++)
    ret = ret * (a - i + 1) / i;
  return ret;
}

void update(double &result, int edge, int delta, int n) {
  int size1 = min(sts[a[edge]], sts[b[edge]]);
  int size2 = n - size1;

  double p = 2.0 * (1.0 - 1.0 * (choose(size1, 3) + choose(size2, 3)) / choose(n, 3));

  result += p * delta;
}

int main() {
  int n;
  
  scanf("%d", &n);

  for (int i = 0; i < n-1; i++) {
    scanf("%d %d %d", &a[i], &b[i], &len[i]);
    a[i]--, b[i]--;
    adj[a[i]].push_back(b[i]);
    adj[b[i]].push_back(a[i]);
  }

  dfs(0, -1, 0);

  double result = 0.0;

  for (int i = 0; i < n-1; i++)
    update(result, i, len[i], n);

  int nq;

  scanf("%d", &nq);

  for (int q = 0; q < nq; q++) {
    int change, to;
    scanf("%d %d", &change, &to);
    change--;
    update(result, change, to - len[change], n);
    len[change] = to;
    printf("%.8f\n", result);
  }

  return 0;
}