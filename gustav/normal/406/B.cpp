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
#define MAXN 1000000

int n;
int b[MAXN + 1];

vector< int > sol, res;

int main(void)
{
  scanf("%d", &n);

  int x = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d",  &x);
    b[x] = 1;
  }

  int cnt = 0;
  for (int i = 1; i <= MAXN / 2; ++i) {
    int j = MAXN - i + 1;

    if (b[i] == 0 && b[j] == 0) 
      res.pb(i), res.pb(j);

    if (b[i] == 0 && b[j] == 1) 
      sol.pb(i);

    if (b[i] == 1 && b[j] == 0) 
      sol.pb(j);
    
    if (b[i] == 1 && b[j] == 1) 
      ++cnt;
  }

  for (int i = 0; i < cnt; ++i)
    sol.pb(res[2 * i]), sol.pb(res[2 * i + 1]);

  printf("%d\n", sol.size());
  for (int i = 0; i < sol.size(); ++i)
    printf("%d ", sol[i]);
  puts("");

  return 0;
}