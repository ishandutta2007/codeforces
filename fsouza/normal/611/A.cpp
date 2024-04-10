#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <complex>
#include <map>
#include <numeric>
#include <set>
#include <cstring>
#include <utility>
#include <vector>

#define INF 1000000000

using namespace std;

typedef long long lint;

int sizes[] = {31, 29, 31, 30, 31, 30, 31,
           31, 30, 31, 30, 31};


int main() {
  int tot = accumulate(sizes, sizes+12, 0);
  int id;
  scanf("%d", &id), --id;
  char type[32];
  scanf(" of %s", type);
  bool week = !strcmp(type, "week");

  int result = 0;
  
  int daym = 0, dayw = 4, mon = 0;
  for (int rep = 0; rep < tot; ++rep) {
    if (week) result += (dayw == id);
    else result += (daym == id);

    if (rep+1 < tot) {
      ++daym, ++dayw;
      if (daym == sizes[mon]) {
    daym = 0;
    ++mon;
      }
      dayw %= 7;
    }
  }

  printf("%d\n", result);
  
  return 0;
}