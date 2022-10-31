#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L); 

mt19937 mrand(random_device{} ()); 
int rnd(int x) {
  return mrand() % x;
}

const int maxn = 100;

bool checkprime(int p) {
  for (int i = 2; i * i <= p; i++) {
    if (p % i == 0) {
      return false;
    }
  }
  return true;
}

vector<int> primes;

void precalc() {
  for (int i = 2; i <= 100; i++) {
    if (checkprime(i)) {
      primes.pb(i);
    }
  }
  /*for (int i = 0; i < sz(primes); i++) {
    printf("%d %d\n", i, primes[i]);
  }*/
}

int main() {
  precalc();

  int cur = 1;
  int times = 0;
  for (int i = 0; i < sz(primes); i++) {
    if (primes[i] > 10 && !times) {
      printf("prime\n");
      fflush(stdout);
      return 0;
    }
    while (true) {
      int tocheck = cur * primes[i];
      if (tocheck > 100) {
        break;
      }
      printf("%d\n", tocheck);
      fflush(stdout);
      char ans[10];
      scanf("%s", ans);
      if (!strcmp(ans, "yes")) {
        cur = tocheck, times++;
      } else {
        break;
      }
    }
  }
  if (times == 1) {
    printf("prime\n");
  } else {
    printf("composite\n");
  }
  fflush(stdout);
  return 0;
}