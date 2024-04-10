// August 4, 2019
// https://codeforces.com/contest/1201/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


const long long INF = 1e18;
const int K = 2e5;


int n, m, k, q;
vector<pair<int, int>> tmp;
vector<pair<int, vector<long long>>> v;
vector<long long> b;
vector<int> len;
long long dp[K][2];

int closest_to_left(int c) {
  int ret = upper_bound(b.begin(), b.end(), c) - b.begin() - 1;
  if (ret < 0) {
    ret = 0;
  }
  return b[ret];
}

int closest_to_right(int c) {
  int ret = lower_bound(b.begin(), b.end(), c) - b.begin();
  if (ret >= q) {
    ret = q - 1;
  }
  return b[ret];
}

long long dist(int r1, int c1, int r2, int c2) {
  assert(r1 <= r2);
  if (r1 == r2) {
    return abs(c1 - c2);
  }
  int l = closest_to_left(c1);
  int r = closest_to_right(c1);
  return r2 - r1 + min(abs(l - c1) + abs(c2 - l), abs(r - c1) + abs(c2 - r));
}

long long cost(int i, int k, int j) {
  return dist(v[i - 1].first, v[i - 1].second[k], v[i].first, v[i].second[j ^ 1]) + len[i];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> m >> k >> q;
  tmp.resize(k);
  for (auto &p : tmp) {
    cin >> p.first >> p.second;
    p.first--;
    p.second--;
  }
  sort(tmp.begin(), tmp.end());
  int last = 0;
  for (int i = 0; i <= k; i++) {
    if (i < k && tmp[i].first == tmp[last].first) {
      continue;
    }
    int l = tmp[last].second, r = tmp[i - 1].second;
    v.push_back({tmp[last].first, {l, r}});
    len.push_back(r - l);
    last = i;
  }
  b.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> b[i];
    b[i]--;
  }
  sort(b.begin(), b.end());
  dp[0][0] = dist(0, 0, v[0].first, v[0].second[1]) + len[0];
  dp[0][1] = dist(0, 0, v[0].first, v[0].second[0]) + len[0];
  for (int i = 1; i < (int) v.size(); i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = INF;
      for (int k = 0; k < 2; k++) {
        dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost(i, k, j));
      }
    }
  }
  cout << min(dp[v.size() - 1][0], dp[v.size() - 1][1]) << '\n';


  return 0;
}