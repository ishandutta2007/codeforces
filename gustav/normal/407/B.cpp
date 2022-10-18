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

const int mod = 1000000007;

#define MAX 1005

int n;
int p[MAX];
int memo[MAX][MAX];

int f(int i, int j) {
  if (i == j) return 0;

  int &ref = memo[i][j];
  if (ref >= 0) return ref;

  ref = 0;
  ref += f(p[i], i) + 1;
  if (ref >= mod) ref -= mod;
  ref += f(i + 1, j) + 1;
  if (ref >= mod) ref -= mod;

  return ref;
}

int main(void)
{
  memset(memo, -1, sizeof memo);

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p + i); 
    --p[i];
  }

  printf("%d\n", f(0, n));

  return 0;
}