#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>
#include <ctime>

using namespace std;

double mx[100005], mn[100005];

long double p[100005], q[100005], ps[100005], qs[100005];

long double get(int i) {
  return mx[i] + (i > 0 ? ps[i - 1] * qs[i - 1] : 0);
}

int main() {
  if (false) {
    int n = 100;
    srand(time(NULL));
    vector<double> P(n, 0), Q(n, 0);
    double s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) {
      P[i] = rand(); Q[i] = rand();
      s1 += P[i]; s2 += Q[i];
    }
    for (int i = 0; i < n; ++i) {
      P[i] /= s1; Q[i] /= s2;
    }

    vector<double> MN(n, 0), MX(n, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        MN[min(i, j)] += P[i] * Q[j];
        MX[max(i, j)] += P[i] * Q[j];
      } 
    }

    cout << n << endl;
    for (double x : MX)
      cout << x << "  ";
    cout << endl;
    for (double x : MN)
      cout << x << "  ";
    cout << endl;
    cout << endl;
    for (double x : P)
      cout << x << "  ";
    cout << endl;
    for (double x : Q)
      cout << x << "  ";
    cout << endl;
    return 0;
  }

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lf", &mx[i]);
  for (int i = 0; i < n; ++i)
    scanf("%lf", &mn[i]);

  for (int i = 0; i < n; ++i) {
    long double mult = get(i);
    long double sum  = mn[i] + mult;
    if (i) sum -= ps[i - 1] * qs[i - 1] - ps[i - 1] - qs[i - 1];

    // cout << mult << " " << sum << endl;
    long double d = sqrt(fabs(sum * sum - 4 * mult));
    long double p1 = (sum + d) / 2, q1 = sum - p1;

    // cout << "R: " << d << endl;

    p[i] = ps[i] = p1; q[i] = qs[i] = q1;
    if (i) p[i] -= ps[i - 1], q[i] -= qs[i - 1];

    // if (i) {
    //   ps[i] = ps[i - 1] + p[i];
    //   qs[i] = qs[i - 1] + q[i];
    // }
  }

  for (int i = 0; i < n; ++i) {
    printf("%.10lf ", (double) p[i]);
  }
  printf("\n");
  for (int i = 0; i < n; ++i) {
    printf("%.10lf ", (double) q[i]);
  }
  printf("\n");
  return 0;
}