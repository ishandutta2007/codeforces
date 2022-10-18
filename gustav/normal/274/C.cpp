#include <cstdio>
#include <cstring>

#include <map>
#include <complex>
#include <algorithm>

using namespace std;
typedef complex< double > vekt;

const double eps = 1e-9;

bool lt(double a, double b) { return a + eps < b; }
bool gt(double a, double b) { return lt(b, a); }
bool eq(double a, double b) { return !lt(a, b) && !gt(a, b); }

vekt center(vekt A, vekt B, vekt C) {
  vekt a = B - A; vekt ar = a * vekt(0, 1);
  vekt b = C - B; vekt br = b * vekt(0, 1);
  vekt r = A - B + 0.5 * a - 0.5 * b;

  double a1 = ar.real(), b1 = -br.real(), c1 = r.real();
  double a2 = ar.imag(), b2 = -br.imag(), c2 = r.imag();

  double d = a1 * b2 - a2 * b1;
  
  if (eq(d, 0.0)) return A;

  double k = (c2 * b1 - c1 * b2) / d;

  return A + 0.5 * a + k * ar;
}

double area(vekt A, vekt B, vekt C) {
  return fabs(
      A.real() * (B.imag() - C.imag()) +
      B.real() * (C.imag() - A.imag()) +
      C.real() * (A.imag() - B.imag())
      );
}

struct cmp {
  bool operator()(vekt a, vekt b) {
    if (eq(a.real(), b.real()))
      return lt(a.imag(), b.imag());
    return lt(a.real(), b.real());
  }
};

map< vekt, int, cmp > m;

int N;
vekt v[105];

int main(void)
{
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) 
    scanf("%lf%lf", &v[i].real(), &v[i].imag());

  double sol = 0.0;

  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int k = j + 1; k < N; ++k) {
        vekt c = center(v[i], v[j], v[k]);
        if (c == v[i]) continue;


        double r = abs(v[i] - c);
        bool ok = 1;

        for (int l = 0; l < N; ++l) {
          if (i == l || j == l || k == l) continue;
          if (lt(abs(v[l] - c), r)) {
            ok = 0;
            break;
          }
        }

        if (!ok) continue;

        double a1 = area(v[i], v[j], c);
        double a2 = area(v[i], v[k], c);
        double a3 = area(v[j], v[k], c);

        ++m[r];

        if (m[r] != 4) {
          if (eq(a1, 0.0)) continue;
          if (eq(a2, 0.0)) continue;
          if (eq(a3, 0.0)) continue;
        }

        if (!eq(a1 + a2 + a3, area(v[i], v[j], v[k]))) continue;

        if (lt(sol, r)) sol = r;
      }
    }
  }

  if (eq(sol, 0)) puts("-1");
  else printf("%.6lf", sol);

  return 0;
}