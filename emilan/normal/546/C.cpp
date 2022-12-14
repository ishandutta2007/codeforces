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

using State = pair<queue<int>, queue<int>>;

int main() {
  ioThings();

  int n, an, bn; cin >> n;
  queue<int> a, b;
  cin >> an;
  for (int i = 0; i < an; i++) {
    int k; cin >> k;
    a.push(k);
  }
  cin >> bn;
  for (int i = 0; i < bn; i++) {
    int k; cin >> k;
    b.push(k);
  }

  set<State> state;
  state.insert({a, b});
  while (!a.empty() && !b.empty()) {
    auto& win = a.front() > b.front() ? a : b;
    auto& lose = a.front() > b.front() ? b : a;

    win.push(lose.front());
    win.push(win.front());
    win.pop();
    lose.pop();

    if (state.count({a, b}))
      break;
    state.insert({a, b});
  }

  if (!a.empty() && !b.empty()) {
    cout << -1;
  } else {
    cout << sz(state) - 1 << ' ' << (a.empty() ? 2 : 1);
  }

  return 0;
}