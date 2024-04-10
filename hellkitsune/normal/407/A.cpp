#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int gcd(int a, int b) {
  if (a < b)
    return gcd(b, a);
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

const double eps = 1e-9;

int main() {
  int a, b, c;
  cin >> a >> b;
  int x[2], y[2];
  c = gcd(a, b);
  for (int i = 1; i < c; ++i) {
    int j = sqrt(c * c - i * i) + eps;
    if (i * i + j * j == c * c) {
      x[0] = j;
      y[0] = i;
      x[0] *= a / c;
      y[0] *= a / c;
      x[1] = i;
      y[1] = -j;
      x[1] *= b / c;
      y[1] *= b / c;
      if ((x[0] == x[1]) || (y[0] == y[1])) {
        x[1] *= -1;
        y[1] *= -1;
        if ((x[0] != x[1]) && (y[0] != y[1])) {
          cout << "YES\n0 0\n" << x[0] << ' ' << y[0] << endl << x[1] << ' ' << y[1] << endl;
          return 0;
        }
      } else {
        cout << "YES\n0 0\n" << x[0] << ' ' << y[0] << endl << x[1] << ' ' << y[1] << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}