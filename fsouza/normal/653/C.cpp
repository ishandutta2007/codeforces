#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> seq(n);
  for (int i = 0; i < n; ++i) scanf("%d", &seq[i]);

  int nbad = 0;
  int badl = -1;
  for (int i = 0; i+1 < n; ++i)
    if (seq[i] == seq[i+1] || (seq[i] < seq[i+1] != (i%2 == 0))) {
      ++nbad;
      badl = i;
    }
  assert(badl != -1);
  
  set<pair<int, int>> cands;
  for (int i = 0; i < n; ++i)
    for (int j : {badl, badl+1})
      if (i != j)
	cands.insert({min(i, j), max(i, j)});

  auto change = [&seq, &nbad, n](int i, int value) {
    if (i+1 < n) nbad -= (seq[i] == seq[i+1] || (seq[i] < seq[i+1] != (i%2 == 0)));
    if (i > 0) {
      --i;
      nbad -= (seq[i] == seq[i+1] || (seq[i] < seq[i+1] != (i%2 == 0)));
      ++i;
    }
    seq[i] = value;
    if (i+1 < n) nbad += (seq[i] == seq[i+1] || (seq[i] < seq[i+1] != (i%2 == 0)));
    if (i > 0) {
      --i;
      nbad += (seq[i] == seq[i+1] || (seq[i] < seq[i+1] != (i%2 == 0)));
      ++i;
    }    
  };
  
  int result = 0;
  for (auto cand : cands) {
    int i, j;
    tie(i, j) = cand;
    int oldvi = seq[i], oldvj = seq[j];
    change(i, oldvj);
    change(j, oldvi);
    if (nbad == 0) ++result;
    change(i, oldvi);
    change(j, oldvj);
  }

  printf("%d\n", result);
  
  return 0;
}