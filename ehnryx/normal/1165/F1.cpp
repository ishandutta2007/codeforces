#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int INF = 0x3f3f3f3f;

const int N = 2e5+1;
int goal[N], vis[N];
map<int,vector<int>> sale;
int tot = 0;

bool valid(int k) {
  memset(vis, 0, sizeof vis);
  int cur = k;
  auto it = sale.upper_bound(k);
  int minv = INF;
  int sum = 0;
  while (it != sale.begin()) {
    it = prev(it);
    minv = min(minv, it->first);
    for (int j : it->second) {
      if (!vis[j]) {
        int take = min(minv, goal[j]);
        minv -= take;
        sum += take;
        vis[j] = true;
      }
    }
  }
  return 2*(tot-sum) <= k-sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i=1; i<=n; i++) {
    cin >> goal[i];
    tot += goal[i];
  }

  for (int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    sale[a].push_back(b);
  }

  int left = 1;
  int right = 1e6;
  while (left < right) {
    int mid = (left+right)/2;
    if (valid(mid)) {
      right = mid;
    } else {
      left = mid+1;
    }
  }
  cout << left << nl;

  return 0;
}