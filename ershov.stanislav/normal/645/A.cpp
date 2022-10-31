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

char s[2][4], t[2][4];

bool read() {
  if (scanf("%s%s%s%s", s[0], s[1], t[0], t[1]) < 4) {
    return false;
  }
  return true;
}

void solve() {
  if (s[0][1] == 'X') {
    swap(s[0][1], s[0][0]);
  }
  if (s[1][1] == 'X') {
    swap(s[1][1], s[1][0]);
  }
  if (s[1][0] == 'X') {
    swap(s[1][0], s[0][0]);
  }

  if (t[0][1] == 'X') {
    swap(t[0][1], t[0][0]);
  }
  if (t[1][1] == 'X') {
    swap(t[1][1], t[1][0]);
  }
  if (t[1][0] == 'X') {
    swap(t[1][0], t[0][0]);
  }

  vector<int> perm(3);
  perm[s[0][1] - 'A'] = t[0][1] - 'B';
  perm[s[1][1] - 'A'] = t[1][1] - 'B';
  perm[s[1][0] - 'A'] = t[1][0] - 'B';
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      if (perm[i] > perm[j]) {
        cnt++;
      }
    }
  }
  if (cnt & 1) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
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