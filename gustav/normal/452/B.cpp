#include <cstdio>
#include <cmath>

#include <vector>
#include <algorithm>

using namespace std;
typedef pair< int, int > pt;

#define x first
#define y second

const int dx[] = { 0, 0, 1, 0, -1 };
const int dy[] = { 0, 1, 0, -1, 0 };

double D(pt a, pt b) {
  double X = a.x - b.x;
  double Y = a.y - b.y;
  return sqrt(X * X + Y * Y);
}

int main(void)
{
  int n, m;
  scanf("%d%d", &n, &m);

  vector< pt > v;
  v.push_back(pt(0, 0));
  v.push_back(pt(n, 0));
  v.push_back(pt(n, m));
  v.push_back(pt(0, m));

  vector< pt > P;
  for (auto p : v) {
    for (int d = 0; d < 5; ++d) {
      pt q(p.x + dx[d], p.y + dy[d]);
      if (q.x < 0 || q.x > n) continue;
      if (q.y < 0 || q.y > m) continue;
      P.push_back(q);
    }
  }

  sort(P.begin(), P.end());
  P.resize(unique(P.begin(), P.end()) - P.begin());

  double dist = -1.0;
  vector< pt > sol;

  for (auto a : P) {
    for (auto b : P) {
      if (a == b) continue;
      for (auto c : P) { 
        if (a == c) continue;
        if (b == c) continue;
        for (auto d : P) {
          if (a == d) continue;
          if (b == d) continue;
          if (c == d) continue;
          vector< pt > Q = {a, b, c, d};
          do {
            double cdist = 0.0;
            for (int i = 0; i < 3; ++i) 
              cdist += D(Q[i], Q[i + 1]);
            if (dist + 1e-9 < cdist) {
              dist = cdist;
              sol = Q;
            }
          } while (next_permutation(Q.begin(), Q.end()));
        }
      }
    }
  }

  for (int i = 0; i < 4; ++i)
    printf("%d %d\n", sol[i].x, sol[i].y);

  return 0;
}