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

const double E = 1e-10;

void read(vector<int> &many) {
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); ++i)
    if (s[i] == '1')
      ++many[s.size()-1-i];
}

int main() {
  const int lim = 100000;
  vector<int> many1(lim, 0), many2(lim, 0);
  read(many1);
  read(many2);

  for (int i = lim-1; i-2 >= 0; --i) {
    int diff = abs(many1[i] - many2[i]);
    if (many1[i] > many2[i]) {
      many1[i-1] += diff;
      many1[i-2] += diff;

      if (diff >= 1000000000/2) {
	printf(">\n");
	return 0;
      }
    } else if (many2[i] > many1[i]) {
      many2[i-1] += diff;
      many2[i-2] += diff;
      if (diff >= 1000000000/2) {
	printf("<\n");
	return 0;
      }
    }
  }

  double q = (sqrt(5)+1)/2;
  double v1 = many1[0] + many1[1] * q;
  double v2 = many2[0] + many2[1] * q;
  if (v1 < v2-E) printf("<");
  else if (v1 > v2+E) printf(">");
  else printf("=");
  printf("\n");

  return 0;
}