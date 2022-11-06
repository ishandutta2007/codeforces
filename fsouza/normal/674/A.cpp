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
  vector<int> color(n);
  for (int &c : color) {
    scanf("%d", &c), --c;
  }

  vector<int> ndom(n);

  vector<int> freq(n, 0);
  for (int i = 0; i < n; ++i) {
    int maxfreq = -1, winner = -1;
    fill(freq.begin(), freq.end(), 0);
    for (int j = i; j < n; ++j) {
      int c = color[j];
      ++freq[c];
      if (freq[c] > maxfreq || (freq[c] == maxfreq && c < winner)) {
	maxfreq = freq[c];
	winner = c;
      }
      ++ndom[winner];
    }
  }

  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", ndom[i]);
  }
  printf("\n");

  return 0;
}