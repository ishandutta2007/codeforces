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

priority_queue<long long> pq;

#define MAXN 111111
int V[MAXN], T[MAXN];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%d", V + i);
  REP(i, N) scanf("%d", T + i);
  long long sumT = 0;
  REP(i, N) {
    pq.push(-(V[i] + sumT));
    long long ans = 0;
    while (!pq.empty() && -pq.top() < sumT + T[i]) {
      ans += -pq.top() - sumT;
      pq.pop();
    }
    sumT += T[i];
    ans += (long long)T[i] * pq.size();
    if (i) cout << " ";
    cout << ans;
  }
  cout << endl;
  return 0;
}