/* Written by Filip Hlasek 2018 */
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

#define MOD 1000000007
#define MAXN 555555

bool action[MAXN];
int value[MAXN];
int nextAccept[MAXN];

priority_queue<int> pq1, pq2;

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    char s[10];
    scanf("%s%d", s, value + i);
    action[i] = s[1] == 'C';
  }

  nextAccept[N] = -1;
  FORD(i, N - 1, 0) nextAccept[i] = action[i] ? value[i] : nextAccept[i + 1];

  int ans = 1, last = 1;
  REP(i, N) {
    // printf("i: %d Left: %d Right: %d\n", i, pq1.empty() ? -1 : pq1.top(), pq2.empty() ? -1 : -pq2.top());
    if (action[i]) {
      if (!pq1.empty() && pq1.top() == value[i]) {
        pq1.pop();
      } else if (!pq2.empty() && pq2.top() == -value[i]) {
        pq2.pop();
      } else {
        ans = 0;
        break;
      }
    } else {
      bool between = (pq1.empty() || pq1.top() < value[i]) && (pq2.empty() || -pq2.top() > value[i]);
      if (nextAccept[i] == -1) {
        if (between) last++;
        continue;
      }

      if (value[i] < nextAccept[i]) pq1.push(value[i]);
      else if (value[i] > nextAccept[i]) pq2.push(-value[i]);
      else if (between) {
        ans = (2 * ans) % MOD;
        pq1.push(value[i]);
      } else {
        ans = 0; break;
      }
    }
  }

  ans = ((long long)ans * last) % MOD;
  printf("%d\n", ans);
  return 0;
}