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

const int maxn = 110;
const int maxm = 500000;

int n;
int p[maxn];
int cnt[maxn];
double pows[maxn];
double cur = 1;

int main() {
#ifdef DEBUG
  freopen("text.in", "r", stdin);
#endif

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
  }
  /*n = 100;
  for (int i = 0; i < 100; i++) {
    p[i] = 1;
  }*/
  
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  
  double ans = n;
  for (int i = 0; i < n; i++) {
    pows[i] = (1 - 0.01 * p[i]);
  }
  
  for (int i = 0; i < maxm; i++) {
    double cur = 1;
    for (int j = 0; j < n; j++) {
      cur *= 1 - pows[j];
      //cout << pows[j][cnt[j]] << endl;
    }
    ans += 1 - cur;
    //cout << 1 - cur << endl;
    //cout << cur << endl;
    /*for (int i = 0; i < n; i++) {
      cout << cnt[i] << ' ';
    }
    cout << endl;*/
    {
      int mxi = -1;
      double curmx = -1;
      for (int j = 0; j < n; j++) {
        double nn = (1 - pows[j] * (1 - 0.01 * p[j])) / (1 - pows[j]);
        if (mxi == -1 || nn > curmx) {
          mxi = j;
          curmx = nn;
        }
      }
      cnt[mxi]++;
      pows[mxi] = pows[mxi] * (1 - 0.01 * p[mxi]);
    }
  }
  
  printf("%.18f\n", (double) ans);

  return 0;
}