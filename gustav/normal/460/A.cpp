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
  scanf("%d%d", &n, &m);

  int day = 0;
  do {
    n -= 1;
    ++day;
    if (day % m == 0) n += 1;
  } while (n > 0);

  printf("%d\n", day);

  return 0;
}