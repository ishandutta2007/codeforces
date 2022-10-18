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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
int N, A[MAXN];

map<int, int> m1, m2, m, mm;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);

  REP(i, N / 2) {
    m1[A[i]]++;
    m2[A[N - i - 1]]++;
  }

  long long ans = 0;
  int start = 0;
  while (start < N && A[start] == A[N - start - 1]) start++;
  if (start == N) { // it is a palindrom already
    cout << (long long)N * (N + 1) / 2 << endl;
    return 0;
  }

  REP(asdfghj, 2) {
    int end = N - start - 1;
    if (m1 == m2) {
      end = (N - 1) / 2;
      while (A[end] == A[N - end - 1]) --end;
    }
    else {
      m.clear();
      int odd = 0;
      FOR(i, start, end) {
        if ((++m[A[i]]) % 2) odd++;
        else odd--;
      }
      if (odd != N % 2) { printf("0\n"); return 0; }
      mm.clear();
      FORD(i, end, start) {
        if (2 * (++mm[A[i]]) > m[A[i]]) {
          end = i;
          break;
        }
      }
    }
    // printf("start: %d end: %d\n", start, end);
    ans += (long long)(start + 1) * (N - end);
    reverse(A, A + N);
  }
  ans -= (long long)(start + 1) * (start + 1);
  cout << ans << endl;
  return 0;
}