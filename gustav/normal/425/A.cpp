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

#define MAXN 205

int n, k;
int a[MAXN];

int main(void)
{
  scanf("%d%d", &n, &k);

  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);

  int sol = -2000000;
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      auto cmpf = [](int a, int b) {
        return a > b;
      };  

      multiset< int > min_set;
      multiset< int , decltype (cmpf) > max_set(cmpf);

      int sum = 0;
      for (int i = 0; i < n; ++i) {
        if (i < l || i > r) 
          max_set.insert(a[i]);
        else {
          min_set.insert(a[i]);
          sum += a[i];
        }
      }

      sol = max(sol, sum);
      int K = k;
      while (min_set.size() && max_set.size() && K) {
        int a = *min_set.begin(); min_set.erase(min_set.begin());
        int b = *max_set.begin(); max_set.erase(max_set.begin());
        sum -= a;
        sum += b;
        sol = max(sol, sum);
        --K;
      }
    }
  }

  printf("%d\n", sol);

  return 0;
}