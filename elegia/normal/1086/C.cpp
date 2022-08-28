#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1000010;

int n, k;
char ans[26];
bool vis[26];
char s[N], a[N], b[N];

char swp(char c) { return 'a' + (k - 1 - (c - 'a')); }

void Set(char a, char b) {
  ans[a - 'a'] = b;
  vis[b - 'a'] = true;
}

char Get(char a) { return ans[a - 'a']; }

bool Vis(char a) { return vis[a - 'a']; }

bool check() {
  memset(ans, 0, sizeof(ans));
  memset(vis, 0, sizeof(vis));
  bool f1 = false;
  for (int i = 1; i <= n; ++i) {
    if (f1) {
      if (!Get(s[i])) {
        for (char c = b[i] - 1; c >= 'a'; --c)
          if (!Vis(c)) {
            Set(s[i], c);
            break;
          }
      }
      if (!Get(s[i])) {
        if (!Vis(b[i])) {
          Set(s[i], b[i]);
        } else
          return false;
      }
      if (Get(s[i]) > b[i])
        return false;
      if (Get(s[i]) < b[i])
        return true;
    } else {
      if (a[i] == b[i]) {
        if (!Get(s[i])) {
          if (Vis(a[i])) {
            return false;
          }
          Set(s[i], a[i]);
        }
        if (Get(s[i]) != a[i]) {
          return false;
        }
      } else {
        if (!Get(s[i])) {
          for (char c = a[i] + 1; c <= b[i]; ++c) {
            if (!Vis(c)) {
              Set(s[i], c);
            //  printf("HERE %d [%c %c] %c %c\n", i, a[i] + 1, b[i], s[i], c);
              break;
            }
          }
        }
        if (!Get(s[i]) || !(ans[s[i] - 'a'] > a[i] && Get(s[i]) <= b[i]))
          return false;
        f1 = true;
        if (Get(s[i]) < b[i])
          return true;
      }
    }
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%s%s%s", &k, s + 1, a + 1, b + 1);
    n = strlen(s + 1);
    if (check()) {
      puts("YES");
      int ptr = 0;
      for (int i = 0; i < k; ++i) {
        if (!ans[i]) {
          while (vis[ptr])
            ++ptr;
          vis[ptr] = true;
          ans[i] = ptr + 'a';
        }
      }
      puts(ans);
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      swap(a[i], b[i]);
      a[i] = swp(a[i]);
      b[i] = swp(b[i]);
//      s[i] = swp(s[i]);
    }
    if (check()) {
      int ptr = 0;
      for (int i = 0; i < k; ++i) {
        if (!ans[i]) {
          while (vis[ptr])
            ++ptr;
          vis[ptr] = true;
          ans[i] = ptr + 'a';
        }
      }
      for (int i = 0; i < k; ++i)
        ans[i] = swp(ans[i]);
      puts("YES");
      puts(ans);
      continue;
    }
    puts("NO");
  }

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}