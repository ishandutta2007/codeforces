#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const ld EPS = 1e-12;
const ld PI = acos(-1.0L); 

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

unsigned int rdtsc() {
  unsigned int ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = (int) 1e5 + 100;
int n, k;
char s[maxn];

bool read() {
  if (scanf("%d%d%s", &n, &k, s) < 3) {
    return false;
  }
  return true;
}

void solve() {
  vector<int> sum(n + 1);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + (s[i] == '0');
  }
  int l = 1, r = 1e9;
  while (l < r) {
    int mid = (l + r) / 2;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        continue;
      }
      int a = max(0, i - mid), b = min(n, i + mid + 1);
      if (sum[b] - sum[a] >= k + 1) {
        ok = true;
        break;
      }
    }
    if (ok) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}