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
int cnt[3];
int all;
int n;
char s[maxn];
int can[3];

int main() {
#ifdef DEBUG
  freopen("text.in", "r", stdin);
#endif
  scanf("%d %s", &n, s);
  
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      cnt[0]++;
    } else if (s[i] == 'G') {
      cnt[1]++;
    } else {
      cnt[2]++;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (cnt[i]) {
      all++;
    }
  }
  if (all == 3) {
    can[0] = can[1] = can[2] = 1;
  } else {
    if (all == 1) {
      for (int i = 0; i < 3; i++) {
        if (cnt[i]) {
          can[i] = 1;
        }
      }
    } else {
      int cnt2 = 0;
      for (int i = 0; i < 3; i++) {
        if (cnt[i] == 0) {
          can[i] = 1;
        }
        if (cnt[i] > 1) {
          cnt2++;
        }
      }
      if (cnt2 == 1) {
        for (int i = 0; i < 3; i++) {
          if (cnt[i] == 1) {
            can[i] = 1;
          }
        }
      } else if (cnt2 == 2) {
        for (int i = 0; i < 3; i++) {
          can[i] = 1;
        }
      }
    }
  }
  if (can[0]) {
    printf("B");
  }
  if (can[1]) {
    printf("G");
  }
  if (can[2]) {
    printf("R");
  }
  printf("\n");
  return 0;
}