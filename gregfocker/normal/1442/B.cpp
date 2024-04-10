#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 998244353;
const int N = 200000 + 7;

int k;
int sol;
vector<int> ops;
vector<int> b;

int need[N];

int smart(int n, vector<int> a) {
  vector<int> pos(k, -1);
  vector<int> asking(n + 1, -1);
  set<pair<int, int>> s;
  for (int i = 0; i < k; i++) {
    asking[b[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    need[i] = 0;
  }
  for (auto &i : b) {
    need[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (asking[a[i]] != -1) {
      pos[asking[a[i]]] = i;
    }
    s.insert({i, a[i]});
  }
  int sol = 1;
  for (int i = 0; i < k; i++) {
    int j = pos[i];
    auto after = s.lower_bound({j, N});
    auto before = s.lower_bound({j, -N});
    int opt = 0, some = 0;
    if (before != s.begin()) {
      before--;
      if (!need[before->second]) {
        opt++;
        some = before->first;
      }
    }
    if (after != s.end()) {
      if (!need[after->second]) {
        opt++;
        some = after->first;
      }
    }
    sol = sol * opt % M;
    if (opt == 0) {
      break;
    }
    s.erase({some, a[some]});
    need[b[i]] = 0;
  }
  return sol;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n >> k;
    vector<int> a(n);
    b.resize(k);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
      cin >> b[i];
    }
    cout << smart(n, a) << "\n";
  }

}