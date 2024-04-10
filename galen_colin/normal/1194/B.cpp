#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll i, j;

ll n, q, Q, t, T, m, k, r, x;
ll a, b, c, d;
string s;

int main() {
  io;
  cin >> Q;
  f0r(q, Q) {
    cin >> n >> m;
    bool grid[n+5][m+5];
    int cs[m+5], rs[n+5];
    f0r(i, n) {
      cin >> s;
      f0r(j, m) {
        grid[i][j] = (s[j] == '*' ? 1 : 0);
      }
    }
    f0r(i, n) {
      rs[i] = 0;
      f0r(j, m) {
        rs[i] += grid[i][j];
      }
    }

    f0r(i, m) {
      cs[i] = 0;
      f0r(j, n) {
        cs[i] += grid[j][i];
      }
    }

    ll ans = 10000000;
    f0r(i, n) {
      f0r(j, m) {
        ll r = (n - cs[j]) + (m - rs[i]);
        if (!grid[i][j]) r--;
        ans = min(ans, r);
      }
    }
    cout << ans << endl;
  }

}