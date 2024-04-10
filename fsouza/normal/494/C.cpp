#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define INF 1000000000
#define MAXN 100000
#define MAXR 5000

using namespace std;

struct sol_t {
  int start, end;
  vector<double> p;
  vector<double> psum;

  sol_t() {}

  sol_t(int v) {
    start = end = v;
    p.push_back(1.0);
    psum.push_back(1.0);
  }

  sol_t(sol_t &s1, sol_t &s2) {
    start = max(s1.start, s2.start);
    end = max(s1.end, s2.end);

    p = vector<double>(end - start + 1);
    psum = vector<double>(end - start + 1);

    for (int v = start; v <= end; v++)
      p[v - start] = s1.fetchp(v) * s2.fetchpsum(v-1) + 
	s1.fetchpsum(v-1) * s2.fetchp(v) + s1.fetchp(v) * s2.fetchp(v);

    update_psum();
  }

  double fetchp(int v) {
    if (!(start <= v && v <= end)) return 0.0;
    return p[v - start];
  }

  double fetchpsum(int v) {
    if (v < start) return 0.0;
    if (v > end) return 1.0;
    return psum[v - start];
  }

  void update(double prob) {
    end++;
    p.push_back(0.0);
    psum.push_back(-1);
    for (int v = end-1; v >= start; v--) {
      p[v+1 - start] += p[v - start] * prob;
      p[v - start] *= (1 - prob);
    }
    update_psum();
  }

  void update_psum() {
    for (int v = start; v <= end; v++) {
      psum[v - start] = p[v - start];
      if (v-1 >= start)
	psum[v - start] += psum[v - 1 - start];
    }
  }

  double expectation() {
    double result = 0.0;

    for (int v = start; v <= end; v++) {
      result += v * p[v - start];
    }

    return result;
  }
};

int values[MAXN];

struct range_t {
  int a, b;
  double prob;
  int maxv;
  vector<int> child;
  sol_t solution;

  bool operator < (const range_t &other) const {
    if (a != other.a) return a < other.a;
    return (b-a) > (other.b - other.a);
  }

  void populate(int &pos, int nr);
  void solve();
} range[MAXR+1];

void range_t::populate(int &pos, int nr) {
  while (pos < nr && range[pos].b <= this -> b) {
    this -> child.push_back(pos);
    pos++;
    range[pos-1].populate(pos, nr);
  }
}

void range_t::solve() {
  maxv = -INF;

  if (child.empty()) {
    for (int i = a; i <= b; i++)
      maxv = max(maxv, values[i]);
  } else {
    for (int i = a; i <= range[child.front()].a-1; i++)
      maxv = max(maxv, values[i]);
    for (int k = 0; k+1 < (int)child.size(); k++)
      for (int i = range[child[k]].b+1; i <= range[child[k+1]].a-1; i++)
	maxv = max(maxv, values[i]);
    for (int i = range[child.back()].b+1; i <= b; i++)
      maxv = max(maxv, values[i]);
  }

  solution = sol_t(maxv);
  for (int c : child) {
    range[c].solve();
    solution = sol_t(solution, range[c].solution);
  }
  solution.update(prob);
}

int main() {
  int n, nr;

  scanf("%d %d", &n, &nr);

  for (int i = 0; i < n; i++) scanf("%d", &values[i]);

  for (int r = 0; r < nr; r++)
    scanf("%d %d %lf", &range[r].a, &range[r].b, &range[r].prob), range[r].a--, range[r].b--;

  range[nr].a = 0, range[nr].b = n-1, range[nr].prob = 0.0;
  nr++;

  sort(range, range+nr);

  int pos = 1;
  range[0].populate(pos, nr);

  range[0].solve();

  printf("%.8f\n", range[0].solution.expectation());

  return 0;
}