#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
  int vals[4], result = 0;
  char c;

  for (int i = 0; i < 4; i++) scanf("%d", vals+i);
  
  while (scanf(" %c", &c) > 0) result += vals[c-'0'-1];

  printf("%d\n", result);

  return 0;
}