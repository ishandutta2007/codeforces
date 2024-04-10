#include <bits/stdc++.h>

using namespace std;

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

const int maxn = 2e5;
int n;
char s[maxn];

int main() {
#ifdef DEBUG
  freopen("text.in", "r", stdin);
#endif
  scanf("%d %s", &n, s);
  map<pair<int, int>, int> m;
  int x = 0, y = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    m[mp(x, y)]++;
    if (s[i] == 'U') {
      y++;
    } else if (s[i] == 'D') {
      y--;
    } else if (s[i] == 'L') {
      x--;
    } else if (s[i] == 'R') {
      x++;
    }
    ans += m[mp(x, y)];
  }
  printf("%d\n", ans);

  return 0;
}