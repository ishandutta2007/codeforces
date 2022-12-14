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

  string s, t; cin >> s >> t;

  int si = 0, ti;
  for (ti = 0; ti < sz(t); ti++) {
    while (si < sz(s) && s[si] != t[ti]) si++;
    if (si == sz(s)) break;
    si++;
  }

  if (ti == sz(t)) {
    cout << "automaton";
    return 0;
  }

  map<char, int> m;
  for (char& i : s) m[i]++;
  for (char& i : t) m[i]--;

  bool tree = false;
  bool both = false;
  for (auto& i : m) {
    if (i.se < 0) tree = true;
    else if (i.se > 0) both = true;
  }

  cout << (tree ? "need tree" : both ? "both" : "array");

  return 0;
}