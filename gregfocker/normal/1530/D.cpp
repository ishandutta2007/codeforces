#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

mt19937 rng((long long) (new char));
const int N = (int) 2e5 + 7;
int n, a[N], sol[N];
vector<int> want[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      want[i].clear();
      sol[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      assert(a[i] != i);
      want[a[i]].push_back(i);
    }
    while (1) {
      for (int i = 1; i <= n; i++) sol[i] = -1, shuffle(want[i].begin(), want[i].end(), rng);
      vector<int> inds, vals;
      for (int x = 1; x <= n; x++) {
        if ((int) want[x].size() >= 1) {
          int who = want[x][0];
          sol[who] = x;
          for (int j = 1; j < (int) want[x].size(); j++) {
            inds.push_back(want[x][j]);
          }

        } else {
          vals.push_back(x);
        }
      }
      assert((int) vals.size() == (int) inds.size());
      int sz = (int) vals.size();
      int steps = 0;
      bool good = 0;
      for (int j = 1; j <= 20; j++) {
        shuffle(inds.begin(), inds.end(), rng);
        shuffle(vals.begin(), vals.end(), rng);
        bool ok = 1;
        for (int i = 0; i < sz; i++) {
          if (inds[i] == vals[i]) {
            ok = 0;
            break;
          }
        }
        steps++;
        if (!ok) {
          continue;
        }
        for (int i = 0; i < sz; i++) {
          sol[inds[i]] = vals[i];
        }
        good = 1;
        break;
      }
      if (good) {
        break;
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += (sol[i] == a[i]);
      assert(sol[i] != i);
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++) {
      if (sol[i] == -1) {
        cout << "? ";
        continue;
      }
      cout << sol[i] << " ";
    }
    cout << "\n";
  }
}


/**

**/