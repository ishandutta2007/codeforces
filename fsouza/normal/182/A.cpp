#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <complex>

#define INF 1000000000
#define MAXN 1000

using namespace std;

typedef complex<int> point;
typedef long long lint;

point readpoint() {
  int x, y;
  scanf("%d %d", &x, &y);
  return point(x, y);
}

point corner[MAXN][2];
int dist[MAXN], mark[MAXN];

double dist11(point p1, point p2) {
  int dx = real(p1) - real(p2);
  int dy = imag(p1) - imag(p2);
  return sqrt(dx*dx + dy*dy);
}

bool dist11good(point p1, point p2, int a) {
  int dx = real(p1) - real(p2);
  int dy = imag(p1) - imag(p2);
  return dx*dx + dy*dy <= a*a;
}

double dist21(int i, point p) {
  point p0 = corner[i][0];
  point p1 = corner[i][1];

  int minx = min(real(p0), real(p1));
  int maxx = max(real(p0), real(p1));
  int miny = min(imag(p0), imag(p1));
  int maxy = max(imag(p0), imag(p1));

  point pmid = p;
  if (real(pmid) < minx) pmid = point(minx, imag(pmid));
  if (real(pmid) > maxx) pmid = point(maxx, imag(pmid));
  if (imag(pmid) < miny) pmid = point(real(pmid), miny);
  if (imag(pmid) > maxy) pmid = point(real(pmid), maxy);

  return dist11(pmid, p);
}

bool dist21good(int i, point p, int a) {
  point p0 = corner[i][0];
  point p1 = corner[i][1];

  int minx = min(real(p0), real(p1));
  int maxx = max(real(p0), real(p1));
  int miny = min(imag(p0), imag(p1));
  int maxy = max(imag(p0), imag(p1));

  point pmid = p;
  if (real(pmid) < minx) pmid = point(minx, imag(pmid));
  if (real(pmid) > maxx) pmid = point(maxx, imag(pmid));
  if (imag(pmid) < miny) pmid = point(real(pmid), miny);
  if (imag(pmid) > maxy) pmid = point(real(pmid), maxy);

  return dist11good(pmid, p, a);
}

bool dist22good(int i, int j, int a) {
  return (dist21good(i, corner[j][0], a) ||
	  dist21good(i, corner[j][1], a) ||
	  dist21good(j, corner[i][0], a) ||
	  dist21good(j, corner[i][1], a));
}

int main() {
  int a, b;

  scanf("%d %d", &a, &b);

  point start = readpoint();
  point end = readpoint();

  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++)
      corner[i][j] = readpoint();
  
  for (int i = 0; i < n; i++) {
    dist[i] = INF;
    if (dist21good(i, start, a))
      dist[i] = 1;
    mark[i] = 0;
  }

  int current;
  do {
    current = -1;
    for (int i = 0; i < n; i++)
      if (!mark[i] && dist[i] < INF && (current == -1 || dist[i] < dist[current]))
	current = i;
    if (current == -1)
      break;

    for (int i = 0; i < n; i++)
      if (dist22good(current, i, a))
	dist[i] = min(dist[i], 1 + dist[current]);
    mark[current] = 1;
  } while (current != -1);

  double result;

  if (dist11good(start, end, a))
    result = dist11(start, end);
  else {
    result = 1e50;
    for (int i = 0; i < n; i++)
      if (dist[i] < INF && dist21good(i, end, a))
	result = min(result, 1.0 * dist[i] * (a+b) + dist21(i, end));
    if (result > 1e49)
      result = -1;
  }

  if (result < -0.5) printf("-1\n");
  else printf("%.10f\n", result);
  
  return 0;
}