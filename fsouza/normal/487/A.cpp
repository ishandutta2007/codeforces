#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define INF 1000000000

using namespace std;

int main() {
  int hp[2], atk[2], def[2];
  int costh, costa, costd;

  for (int i = 0; i < 2; i++)
    scanf("%d %d %d", &hp[i], &atk[i], &def[i]);
  scanf("%d %d %d", &costh, &costa, &costd);
  
  int result = INF;

  for (int a = 0; a <= 200; a++) {
    if (atk[0] + a <= def[1])
      continue;

    int mdec = atk[0] + a - def[1];

    for (int d = 0; d <= 100; d++) {
      int ydec = max(atk[1] - (def[0] + d), 0);

      int r1 = (hp[1] + mdec-1) / mdec;
      int receive = r1 * ydec;

      int need_have = receive + 1;
      int h = max(0, need_have - hp[0]);

      result = min(result, costh * h + costa * a + costd * d);
    }
  }
  
  printf("%d\n", result);

  return 0;
}