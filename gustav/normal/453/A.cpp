#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back

int main(void)
{
  int n, m;
  scanf("%d%d", &m, &n);

  double sol = 0.0;
  for (int k = 1; k <= m; ++k) {
    double p1 = pow((double)k / m, n);
    double p2 = pow((double)(k - 1) / m, n);
    sol += (p1 - p2) * k;
  }

  printf("%.6lf\n", sol);

  return 0;
}