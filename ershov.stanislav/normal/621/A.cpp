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
  int n;
  cin >> n;

  ll sum = 0;
  bool has = false;
  int mn = INF;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (a % 2) {
      has ^= true;
      mn = min(mn, a);
    }
    sum += a;
  }
  if (has) {
    sum -= mn;
  }
  cout << sum << endl;

  return 0;
}