#include <bits/stdc++.h>
 
using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
int i, j;
typedef long long ll;
typedef pair<int, int> pii;
 
ll n, q, Q, t, T, m, k;
int a[1001];
int def = (int)1e8;
vector<pii > f[2];
set<pii > on;
 
int main() {
  io;
  cin >> n >> m;
  const int drop = n + 5;
  f0r(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    b--;
    c--;
    f[a].pb(mp(b, c));
  }
 
  //any 1 fully contains a 0 - impossible
  f0r(i, f[1].size()) {
    f0r(j, f[0].size()) {
      if (f[1][i].first <= f[0][j].first && f[1][i].second >= f[0][j].second) {
        cout << "NO" << endl;
        exit(0);
      }
    }
  }
 
  f0r(i, n) {
    auto it = on.begin();
    while (on.size() > 0 && it != on.end()) {
      if ((*it).second < i) it = on.erase(it);
      else it++;
    }
    if (on.size() == 0) {
      def -= drop;
    }
    a[i] = def;
    def++;
    f0r(j, f[1].size()) if (f[1][j].first == i) on.insert(f[1][j]);
  }
 
  f0r(i, f[0].size()) {
    bool fl = 0;
    f1r(j, f[0][i].first + 1, f[0][i].second + 1) {
      if (a[j] < a[j-1]) fl = 1;
    }
    if (!fl) {
      cout << "NO" << endl;
      exit(0);
    }
  }
 
  cout << "YES" << endl;
  f0r(i, n) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}