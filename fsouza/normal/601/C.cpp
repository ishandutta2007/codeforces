#include <iostream>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int maxscore = n*m;
  vector<int> rank(n);
  for (int i = 0; i < n; ++i) scanf("%d", &rank[i]);
  int myscore = accumulate(rank.begin(), rank.end(), 0);

  long double ret = 1.0;

  if (m == 1) {
  } else {
    vector<long double> prob(maxscore+1, 0.0);
    prob[0] = 1.0;
    vector<long double> probsum(maxscore+1, 1.0);
    
    vector<long double> nextprob(maxscore+1), nextprobsum(maxscore+1);
    
    for (int i = 0; i < n; ++i) {
      for (int s = 0; s <= maxscore; ++s) {
    long double &ret = nextprob[s];
    ret = 0.0;
    if (s-1 >= 0)
      ret += probsum[s-1];
    if (s-1-m >= 0)
      ret -= probsum[s-1-m];
    if (s-rank[i] >= 0)
      ret -= prob[s-rank[i]];
    ret /= m-1;
    
    nextprobsum[s] = nextprob[s];
    if (s-1 >= 0)
      nextprobsum[s] += nextprobsum[s-1];
      }
      swap(prob, nextprob);
      swap(probsum, nextprobsum);
    }

    for (int s = 0; s < myscore; ++s)
      ret += prob[s] * (m-1.0);
  }

  printf("%.16f\n", (double)ret);
  
  return 0;
}