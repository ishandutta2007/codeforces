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

#define MAX 1005

int a, b;
int rt[MAX * MAX];

int main(void)
{
  for (int i = 1; i < MAX; ++i)
    rt[i * i] = i;

  scanf("%d%d", &a, &b);
  int a2 = a * a;
  int b2 = b * b;

  for (int i = 1; i * i < a2; ++i) {
    if (!rt[a2 - i * i]) continue;
    int I = rt[a2 - i * i];
    for (int j = 1; j * j < b2; ++j) {
      if (!rt[b2 - j * j]) continue;
      int J = rt[b2 - j * j];
      if (I == J) continue;
      if (i * j == I * J) {
        puts("YES");
        puts("0 0");
        printf("%d %d\n", -i, I);
        printf("%d %d\n", j, J);
        return 0;
      }
    }
  }

  puts("NO");

  return 0;
}