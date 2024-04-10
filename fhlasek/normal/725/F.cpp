/* Written by Filip Hlasek 2016 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 333333
int A1[MAXN], B1[MAXN], A2[MAXN], B2[MAXN];
priority_queue< pair<int, int> > pq1, pq2;

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  long long ans = 0;
  REP(i, N) {
    scanf("%d%d%d%d", A1 + i, B1 + i, A2 + i, B2 + i);
    // if (A1[i] <= B2[i] && B1[i] <= A2[i]) continue;
    if (A1[i] + B1[i] > A2[i] + B2[i]) {
      pq2.push(make_pair(A1[i] + B1[i], i));
      continue;
    }
    if (A1[i] <= B2[i] && B1[i] > A2[i]) {
      ans += A2[i] - B1[i];
      continue;
    }
    if (A1[i] > B2[i] && B1[i] <= A2[i]) {
      ans += A1[i] - B2[i];
      continue;
    }
  }
  int a = false;
  while (true) {
    a = !a;
    if (pq1.empty() && pq2.empty()) break;
    if (pq1.empty() || (!pq1.empty() && !pq2.empty() && pq1.top().first < pq2.top().first)) {
      int index = pq2.top().second; pq2.pop();
      pq1.push(make_pair(A2[index] + B2[index], index));
      if (a > 0) ans += A1[index];
      else ans -= B1[index];
    }
    else {
      int index = pq1.top().second; pq1.pop();
      if (a > 0) ans += A2[index];
      else ans -= B2[index];
    }
  }
  cout << ans << endl;
  return 0;
}