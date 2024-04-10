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
#define MAXN 1005

int n, q;
int a[MAXN][MAXN];
int type, x;
int sum;

int main(void)
{
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &a[i][j]);

  for (int i = 0; i < n; ++i) 
    for (int j = 0; j < n; ++j) 
      sum ^= (a[i][j] && a[j][i]);

  scanf("%d", &q);

  for (int i = 0; i < q; ++i) {
    scanf("%d", &type);

    if (type == 1 || type == 2) {
      scanf("%d", &x); --x;
      sum ^= 1;
    }

    if (type == 3)
      putchar('0' + sum);
  }

  return 0;
}