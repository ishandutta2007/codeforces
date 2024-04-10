#include <bits/stdc++.h>

using namespace std;

vector<pair<int, long long>> calc(vector<int>& a, int m) {
  int last = 0;
  long long cur = 0;
  vector<pair<int, long long>> ret;
  for (int i = 0; i < (int)a.size(); ++i) {
    int now = a[i];
    long long cnt = 1;
    while ((now % m) == 0) {
      now /= m;
      cnt *= m;
    }
    if (now != last) {
      if (cur) {
        ret.emplace_back(last, cur);
      }
      last = now;
      cur = cnt;
    } else {
      cur += cnt;
    }
  }
  if (cur) {
    ret.emplace_back(last, cur);
  }
  return ret;
}

void solve() {
  int n, m, k;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> k;
  vector<int> b(k);
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }
  cout << (calc(a, m) == calc(b, m) ? "Yes\n" : "No\n");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}