#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#define debug(x) cerr << #x << ": <" << (x) << ">\n"
#else
#define debug(x)
#endif
}

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n, m;
  cin >> n >> m;

  set<int> visited;
  queue<pair<int, int>> q;
  q.emplace(n, 0);
  while (!q.empty()) {
    int cur = q.front().fi;
    int op = q.front().se;
    q.pop();

    if (cur > 10000 || cur == 0) continue;
    else if (cur == m) {
      cout << op;
      break;
    }

    if (!visited.count(cur * 2)) {
      visited.insert(cur * 2);
      q.emplace(cur * 2, op + 1);
    }
    
    if (!visited.count(cur - 1)) {
      visited.insert(cur - 1);
      q.emplace(cur - 1, op + 1);
    }
  }

  return 0;
}