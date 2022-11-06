#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <complex>

using namespace std;

typedef long long lint;
typedef complex<lint> point;

lint cross(point p1, point p2) {
  return real(p1) * imag(p2) - imag(p1) * real(p2);
}

int main() {
  point p[3];

  for (int i = 0; i < 3; i++) {
    double x, y;
    cin >> x >> y;
    p[i] = point(x, y);
  }

  lint c = cross(p[2]-p[0], p[1]-p[0]);

  if (c == 0) cout << "TOWARDS" << endl;
  else if (c > 0) cout << "RIGHT" << endl;
  else cout << "LEFT" << endl;

  return 0;
}