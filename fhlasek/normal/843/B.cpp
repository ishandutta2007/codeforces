/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

int N, start, X;
int best_index = -1, best_value = -1;

set<int> known;

int Q = 0;

void q(int index) {
  Q++;
  printf("? %d\n", index + 1);
  fflush(stdout);
  int value, next;
  scanf("%d%d", &value, &next);
  known.insert(index);
  known.insert(next - 1);
  if (best_value < value && (value <= X || best_value == -1)) {
    best_index = index;
    best_value = value;
  }
}

int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &start, &X);
  q(start - 1);
  REP(i, 2 * 666) {
    if ((int)known.size() > N - 2) break;
    int id;
    do {
      id = ((rand() << 15) + rand()) % N;
    } while (known.find(id) != known.end());
    q(id);
  }
  int index = best_index, value = best_value;
  if (value >= X) {
    printf("! %d\n", value);
    fflush(stdout);
    return 0;
  }
  while (index != -1) {
    Q++;
    if (Q >= 2000) {
      while (Q >= 2000) ;
    }
    printf("? %d\n", index + 1);
    fflush(stdout);
    scanf("%d%d", &value, &index);
    if (value >= X) {
      printf("! %d\n", value);
      fflush(stdout);
      return 0;
    }
    if (index == -1) break;
    index--;
  }
  printf("! -1\n");
  fflush(stdout);
  return 0;
}