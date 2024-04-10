#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int main() {
#ifdef DEBUG
  freopen("text.in", "r", stdin);
  freopen("text.out", "w", stdout);
#endif
  map<int, int> m1, m2;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    m1[x - y]++;
    m2[x + y]++;
  }

  ll ans = 0;
  
  for (auto i : m1) {
    ans += (ll) i.sc * (i.sc - 1) / 2;
  } 

  for (auto i : m2) {
    ans += (ll) i.sc * (i.sc - 1) / 2;
  } 

  cout << ans << endl;

  return 0;
}