#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;
const ll mod = 1e9 + 7;

int n, m;
int grid[2002][2002];
struct comp {
  int bounds[4];
  comp() {
    bounds[0] = 10000000;
    bounds[1] = 10000000;
    bounds[2] = -1;
    bounds[3] = -1;
  }
};
comp comps[27];
bool on[27];
pair<int, int> valid;

int maxg = 0;
int t, T;
int main() {
  io;
  cin >> T;
  f0r(t, T) {
    f0r(i, 27) comps[i] = comp();
    f0r(i, 27) on[i] = 0;
    maxg = 0;
    cin >> n >> m;
    f0r(i, n) {
      string s; cin >> s;
      f0r(j, m) {
        grid[i][j] = s[j];
        if (grid[i][j] == '.') {
          grid[i][j] = 0;
          continue;
        }
        grid[i][j] = grid[i][j] - 'a' + 1;
        int g = grid[i][j];
        maxg = max(maxg, g);
        g--;
        on[g] = 1;
        comps[g].bounds[0] = min(comps[g].bounds[0], j);
        comps[g].bounds[1] = min(comps[g].bounds[1], i);
        comps[g].bounds[2] = max(comps[g].bounds[2], j);
        comps[g].bounds[3] = max(comps[g].bounds[3], i);
      }
    }
    // int g;
    // f0r(g, maxg) {
    //   // cout << g << " " << comps[g].bounds[1] << " " << comps[g].bounds[0] << " " << comps[g].bounds[3] << " " << comps[g].bounds[2] << " " << endl;
    //   if (comps[g].bounds[0] == 10000000) on[i] = 0;
    // }
    bool ok = 1;
    f0r(i, maxg) {
      if (!on[i]) continue;
      if (comps[i].bounds[0] != comps[i].bounds[2] && comps[i].bounds[1] != comps[i].bounds[3]) {
        ok = 0;
      }
      for (int r = comps[i].bounds[1]; r <= comps[i].bounds[3]; r++) {
        for (int c = comps[i].bounds[0]; c <= comps[i].bounds[2]; c++) {
          // cout << r << " " << c << " " << grid[r][c] << " " << i << " " << ok << endl;
          if (grid[r][c] < i + 1) ok = 0;
        }
      }
    }

    if (!ok) cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      cout << maxg << endl;
      f0r(i, maxg) {
        if (on[i])
          cout << comps[i].bounds[1] + 1 << " " << 1 + comps[i].bounds[0] << " " << 1+comps[i].bounds[3] << " " << 1+comps[i].bounds[2] << " " << endl;
        else {
          cout << comps[maxg - 1].bounds[1] + 1<< " " << comps[maxg - 1].bounds[0]+1 <<" " << comps[maxg - 1].bounds[1] + 1<< " " << comps[maxg - 1].bounds[0] + 1<< " " << endl;
        }
      }
    }
  }
}