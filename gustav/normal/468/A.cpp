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

int main(void)
{
  int N;
  scanf("%d", &N);

  if (N <= 3) {
    puts("NO");
    exit(0);
  }

  if (N % 2 == 0) {
    puts("YES");
    puts("1 * 2 = 2");
    puts("2 * 3 = 6");
    puts("6 * 4 = 24");

    for (int i = 5; i < N; i += 2) 
      printf("%d - %d = 1\n", i + 1, i);

    REP(i, (N - 4) / 2)
      puts("24 * 1 = 24");
  } else {
    puts("YES");
    puts("4 - 2 = 2");
    puts("5 - 1 = 4");
    puts("2 * 3 = 6");
    puts("6 * 4 = 24");
    
    for (int i = 6; i < N; i += 2) 
      printf("%d - %d = 1\n", i + 1, i);
    
    REP(i, (N - 5) / 2)
      puts("24 * 1 = 24");
  }

  return 0;
}