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

int n, m;

int main() {
#ifdef DEBUG
  freopen("text.in", "r", stdin);
#endif
  scanf("%d%d", &n, &m);
  int L = 1, R = 1e9;
  while (L < R) {
    int mid = (L + R) / 2;
    int n0 = max(0, n - (mid / 2 - mid / 6));
    int m0 = max(0, m - (mid / 3 - mid / 6));
    if (n0 + m0 <= mid / 6) {
      R = mid;
    } else {
      L = mid + 1;
    }
  }
  cout << L << endl;
  return 0;
}