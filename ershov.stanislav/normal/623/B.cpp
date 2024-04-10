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

const int maxn = (int) 1e6 + 100;
const int maxm = 500;

int n, a, b;
int arr[maxn];
ll ans = 1e18;
set<int> s;
int c[maxn];
ll d[maxn];

int main() {
#ifdef DEBUG
  freopen("text.in", "r", stdin);
#endif

  scanf("%d%d%d", &n, &a, &b);
  
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  for (int it = 0; it < 2; it++) {
    for (int i = -1; i <= 1; i++) {
      int r = arr[it ? 0 : (n - 1)] + i;
      for (int i = 2; i < 50000; i++) {
        while (r % i == 0) {
          r /= i;
          s.insert(i);
        }
      }
      if (r > 1) {
        s.insert(r);
      }
    }
  }
  for (auto p : s) {
    //cout << p << endl;
    memset(c, 0, sizeof(c));
    int mn = INF, mx = -INF;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      if ((arr[i] + 1) % p == 0 || (arr[i] - 1) % p == 0) {
        c[i] += b;
        sum += b;
      }
      if ((arr[i] + 1) % p != 0 && arr[i] % p != 0 && (arr[i] - 1) % p != 0) {
        mn = min(i, mn);
        mx = max(i, mx);
      }
    }
    /*for (int i = 0; i < n; i++) {
      cout << c[i] << ' ';
    }
    cout << endl;
    cout << mn << ' ' << mx << endl;*/
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
      d[i] = d[i - 1] - c[i - 1] + (ll) a;
    }
    ll curmx = -1e18;
    for (int i = 0; i <= n; i++) {
      if (i <= mn) {
        curmx = max(curmx, d[i]);
      }
      if (i > mx) {
        ans = min(ans, sum + d[i] - curmx);
      }
    }
    //cout << ans << endl;
  }
  
  printf(LLD "\n", ans);

  return 0;
}