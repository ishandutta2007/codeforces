/* Written by Filip Hlasek 2018 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MAXN 222222

int solve_greedy(const string &a, const string &b, bool ab, bool print = false) {

  // if (print) cout << a << endl << b << endl;
  int x[MAXN], y[MAXN], X = 0, Y = 0;
  int N = a.size(), M = b.size();
  int ans = 0;

  while (true) {
    while (N && (a[N - 1] == 'a') == (ab ^ (X % 2))) N--;
    if (!N) break;
    x[X++] = N;
  }
  x[X++] = 0;
  reverse(x, x + X);

  while (true) {
    while (M && (b[M - 1] == 'b') == (ab ^ (Y % 2))) M--;
    if (!M) break;
    y[Y++] = M;
  }
  y[Y++] = 0;
  reverse(y, y + Y);

  int n = X - 1, m = Y - 1;
  while (n > 0 || m > 0) {
    int a1 = x[n], a2 = y[m];
    if (n) n--;
    if (m) m--;
    if (print) {
      if (ans % 2) {
        swap(a1, a2);
      }
      printf("%d %d\n", a1, a2);
    }
    ans++;
  }
  return ans;
}

int solve(string a, string b, bool ab, bool print = false) {
  int x[MAXN], y[MAXN], X = 0, Y = 0;
  int N = a.size(), M = b.size();

  while (true) {
    while (N && (a[N - 1] == 'a') == (ab ^ (X % 2))) N--;
    if (!N) break;
    x[X++] = N;
  }
  x[X++] = 0;

  while (true) {
    while (M && (b[M - 1] == 'b') == (ab ^ (Y % 2))) M--;
    if (!M) break;
    y[Y++] = M;
  }
  y[Y++] = 0;

  int ans = solve_greedy(a, b, ab);

  if (X >= Y) {
    FOR(d, -5, 5) {
      string na, nb;
      int t = (X + Y) / 2 - Y + d;
      if (t % 2) t++;
      if (t < 0) t = 0;
      if (t > X) break;
      na.insert(na.end(), b.begin(), b.begin() + y[0]);
      na.insert(na.end(), a.begin() + x[t], a.begin() + x[0]);
      nb.insert(nb.end(), a.begin(), a.begin() + x[t]);
      ans = min(ans, 1 + solve_greedy(na, nb, ab, false));
    }
    if (print) {
      if (ans == solve_greedy(a, b, ab)) {
        solve_greedy(a, b, ab, true);
        return ans;
      }
      FOR(d, -5, 5) {
        string na, nb;
        int t = (X + Y) / 2 - Y + d;
        if (t % 2) t++;
        if (t < 0) t = 0;
        if (t > X) break;
        na.insert(na.end(), b.begin(), b.begin() + y[0]);
        na.insert(na.end(), a.begin() + x[t], a.begin() + x[0]);
        nb.insert(nb.end(), a.begin(), a.begin() + x[t]);
        if (ans == 1 + solve_greedy(na, nb, ab, false)) {
          printf("%d %d\n", x[t], y[0]);
          solve_greedy(na, nb, ab, true);
          return ans;
        }
      }
    } else {
      return ans;
    }
  } else {
    FOR(d, -5, 5) {
      string na, nb;
      int t = (X + Y) / 2 - X + d;
      if (t % 2) t++;
      if (t < 0) t = 0;
      if (t > Y) break;
      nb.insert(nb.end(), a.begin(), a.begin() + x[0]);
      nb.insert(nb.end(), b.begin() + y[t], b.begin() + y[0]);
      na.insert(na.end(), b.begin(), b.begin() + y[t]);
      ans = min(ans, 1 + solve_greedy(na, nb, ab, false));
    }
    if (print) {
      if (ans == solve_greedy(a, b, ab)) {
        solve_greedy(a, b, ab, true);
        return ans;
      }
      FOR(d, -5, 5) {
        string na, nb;
        int t = (X + Y) / 2 - X + d;
        if (t % 2) t++;
        if (t < 0) t = 0;
        if (t > Y) break;
        nb.insert(nb.end(), a.begin(), a.begin() + x[0]);
        nb.insert(nb.end(), b.begin() + y[t], b.begin() + y[0]);
        na.insert(na.end(), b.begin(), b.begin() + y[t]);
        if (ans == 1 + solve_greedy(na, nb, ab, false)) {
          printf("%d %d\n", x[0], y[t]);
          solve_greedy(na, nb, ab, true);
          return ans;
        }
      }
    } else {
      return ans;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  string a, b;
  cin >> a;
  cin >> b;

  int s0 = solve(a, b, 0), s1 = solve(a, b, 1);
  printf("%d\n", min(s0, s1));
  if (s0 < s1) {
    solve(a, b, 0, true);
  } else {
    solve(a, b, 1, true);
  }
  return 0;
}