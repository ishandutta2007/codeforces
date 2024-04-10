#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  string big, small;
  cin >> big >> small;
  vector<int> failure(small.size()+1, 0);
  for (int s = 2; s <= (int)small.size(); ++s) {
    failure[s] = failure[s-1];
    while (failure[s] > 0 && small[s-1] != small[failure[s]])
      failure[s] = failure[failure[s]];
    if (small[s-1] == small[failure[s]]) ++failure[s];
  }

  int result = 0;
  int size = 0;
  for (int i = 0; i < (int)big.size(); ++i) {
    while (size > 0 && big[i] != small[size]) size = failure[size];
    if (big[i] == small[size]) {
      ++size;
      if (size == (int)small.size()) {
	++result;
	size = 0;
      }
    }
  }

  cout << result << "\n";
  
  return 0;
}