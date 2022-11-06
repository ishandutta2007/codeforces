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
  scanf("%d %d", &n, &k);
  string have;
  cin >> have;
  int m = have.size();

  vector<pair<int, char>> many(k);
  for (int i = 0; i < k; ++i) many[i] = make_pair(0, 'a'+i);

  const int mod = 1e9+7;
  
  for (char c : have) {
    int sum = 0;
    for (int i = 0; i < k; ++i)
      sum = (many[i].first + sum) % mod;

    for (int i = 0; i < k; ++i)
      if (many[i].second == c) {
	many[i].first = (sum + 1) % mod;
	auto guy = many[i];
	many.erase(many.begin() + i);
	many.push_back(guy);
	break;
      }
  }

  for (int rep = 0; rep < n; ++rep) {
    int sum = 0;
    for (int i = 0; i < k; ++i)
      sum = (many[i].first + sum) % mod;
    auto guy = many[0];
    guy.first = (sum + 1) % mod;
    many.erase(many.begin());
    many.push_back(guy);
  }

  int sum = 0;
  for (int i = 0; i < k; ++i)
    sum = (many[i].first + sum) % mod;
  printf("%d\n", (sum+1) % mod);
  
  return 0;
}