#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<double> p(n);
  for (int i = 0; i < n; ++i) {
    int prob;
    scanf("%d", &prob);
    p[i] = prob / 100.0;
  }

  vector<int> many(n, 1);
  vector<double> pcomp2many(n);
  for (int i = 0; i < n; ++i) pcomp2many[i] = 1 - p[i];
  double winp = accumulate(p.begin(), p.end(), 1.0, multiplies<double>());
  double result = 0.0;

  result += n * winp;

  const int lastround = 1000000;
  for (int r = n; r < lastround; ++r) {
    double bestdelta = -1;
    int besti = -1;
    for (int i = 0; i < n; ++i) {
      double delta = (1 - pcomp2many[i] * (1 - p[i])) / (1 - pcomp2many[i]);
      if (delta > bestdelta) {
	bestdelta = delta;
	besti = i;
      }
    }
    {
      int i = besti;
      double newwinp = winp * bestdelta;

      result += (r+1) * (newwinp - winp);
      ++many[i];
      pcomp2many[i] *= (1 - p[i]);
      
      winp = newwinp;
    }
  }
  result += (lastround+1) * (1.0 - winp);
  
  printf("%.7f\n", (double)result);
  
  return 0;
}