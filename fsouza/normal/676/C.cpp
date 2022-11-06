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
  int n, k;
  cin >> n >> k;

  vector<int> pos[2];

  string s;
  cin >> s;

  int result = 0;

  for (int i = 0; i < (int)s.size(); ++i) {
    pos[s[i]-'a'].push_back(i);
    for (int kind = 0; kind < 2; ++kind) {
      vector<int> &guys = pos[kind];
      if (guys.size() <= k) result = max(result, i+1);
      else result = max(result, i-(guys[guys.size()-1-k]+1)+1);
    }
  }

  cout << result << "\n";

  return 0;
}