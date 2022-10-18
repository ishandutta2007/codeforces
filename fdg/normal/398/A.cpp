#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char str[200005];

long long get(int a, int b) {
  if (a == 0) return -1LL * b * b;
  return 1LL * a * a - 1LL * (b / 2) * (b / 2) - 1LL * ((b + 1) / 2) * ((b + 1) / 2);
}

int main() {
  int a, b;
  cin >> a >> b;
  int A = a, B = b;
  int ga = max(min(a, b - 1), 1), gb = min(b, a + 1);
  // return 0;
  int bg = a != 0;
  long long val = 1LL * a * a - 1LL * b * b;
  for (int g = 1; g <= ga && a; ++g) {
    long long cur = 1LL * (a - g + 1) * (a - g + 1) + (g - 1);
    int sz = b / (g + 1);
    cur -= 1LL * (sz + 1) * (sz + 1) * (b % (g + 1));
    cur -= 1LL * (sz) * (sz) * (g + 1 - b % (g + 1));
    if (cur > val) {
      val = cur;
      bg = g;
    }
    // cout << g << "  " << cur << endl;
  }
  ga = bg; gb = min(b, ga + 1);
  // cout << ga << " " << gb << endl;
  long long ans = 0;
  int pos = 0, col = 0, gs = gb != 0 ? (b / gb) : 1;
  int left = b - gs * gb;
  // cout << ga << " " << gb << "  " << gs << endl;
  while (a > 0 || b > 0) {
    // cout << a << "  " << b << endl;
    col ^= 1;
    if (col == 1) {
      if (b == 0) continue;
      int cnt = gs;
      if (left) ++cnt, --left;
      b -= cnt;
      for (int i = 0; i < cnt; ++i) {
        str[pos++] = 'x';
      }
      // cout << cnt << endl;
      ans -= 1LL * cnt * cnt;
    } else {
      if (a == 0) continue;
      int cnt = 1;
      if (a > ga) cnt = a - ga + 1;
      // cout << cnt << endl;
      a -= cnt;
      for (int i = 0; i < cnt; ++i) {
        str[pos++] = 'o';
      }
      ans += 1LL * cnt * cnt;
    }
  }
  if (get(A, B) <= ans) {
    cout << ans << endl;
    puts(str);
    return 0;
  }
  return 0;
  pos = 0; a = A; b = B;
  for (int i = 0; i < b / 2; ++i)
    str[pos++] = 'x';
  for (int i = 0; i < a; ++i)
    str[pos++] = 'o';
  for (int i = 0; i < (b + 1) / 2; ++i)
    str[pos++] = 'x';
  ans = 1LL * a * a - 1LL * (b / 2) * (b / 2) - 1LL * ((b + 1) / 2) * ((b + 1) / 2);
  if (a == 0) ans = -1LL * b * b;
  cout << ans << endl;
  puts(str);
  return 0;
}