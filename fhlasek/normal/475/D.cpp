/* Written by Filip Hlasek 2014 */
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

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)
#define REP(i, b) for(int i=0;i<b;i++)

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

#define MAXN 333333
int N, A[MAXN], Q, q[MAXN];

map<int, long long> ans;
map<int, int> m;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  scanf("%d", &Q);
  REP(i, Q) { scanf("%d", q + i); ans[q[i]] = 0; }

  REP(i, N) {
    map<int, int> nm;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
      int g = gcd(A[i], it->first);
      if (ans.count(g)) ans[g] += it->second;
      nm[g] += it->second;
    }
    m = nm;
    m[A[i]]++;
    if (ans.count(A[i])) ans[A[i]]++;
  }
  REP(i, Q) cout << ans[q[i]] << endl;
  return 0;
}