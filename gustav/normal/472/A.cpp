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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define MAX 1000005

int N;
int np[MAX];

int main(void)
{
  scanf("%d", &N);
  
  for (int i = 2; i <= N; ++i) {
    if (np[i]) continue;
    for (int j = 2 * i; j <= N; j += i)
      np[j] = 1;
  }

  for (int i = 2; i < N; ++i) {
    if (np[i] && np[N - i]) {
      printf("%d %d\n", i, N - i);
      exit(0);
    }
  }

  return 0;
}