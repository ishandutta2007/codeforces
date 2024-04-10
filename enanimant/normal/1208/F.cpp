// August 25, 2019
// https://codeforces.com/contest/1208/problem/F

/*
Learn some helpful names for variables, especially names of arrays; ones that
are descriptive and short. Examples (taken from (guess who) tourist!):

who
mark

Again, submit this tomorrow.
*/


#include <bits/stdc++.h>

using namespace std;


const int N = 1000005;
const int BITS = 21;
const int MAX = 1 << BITS;


int a[N];
vector<int> pos[MAX];
pair<int, int> dp[MAX]; // rightmost index such that there exists 2 supersets of
// i with indices >= dp[i]

void update(pair<int, int>& p, int v) {
  if (v > p.first) {
    p.second = p.first;
    p.first = v;
  } else {
    p.second = max(p.second, v);
  }
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


  int n;
  cin >> n;
  fill(dp, dp + MAX, make_pair(-1, -1));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    update(dp[a[i]], i);
  }
  for (int k = 0; k < BITS; k++) {
    for (int i = 0; i < MAX; i++) {
      if (!(i & (1 << k))) {
        const auto &p = dp[i ^ (1 << k)];
        update(dp[i], dp[i ^ (1 << k)].first);
        update(dp[i], dp[i ^ (1 << k)].second);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n - 2; i++) {
    int cur = 0;
    for (int j = BITS - 1; j >= 0; j--) {
      if (a[i] & (1 << j)) {
        continue;
      }
      if (dp[cur + (1 << j)].second > i) {
        cur += 1 << j;
      }
    }
    ans = max(ans, a[i] | cur);
  }
  cout << ans << '\n';


  return 0;
}