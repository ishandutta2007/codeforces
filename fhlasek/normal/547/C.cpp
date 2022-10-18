/* Written by Filip Hlasek 2015 */
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

#define MAXN 555555
vector<int> primes[MAXN];

int cnt[MAXN];
int N, Q;
int A[MAXN];
bool is_there[MAXN];

long long ans = 0;

void add_it(int n) {
  int x = A[n];
  is_there[n] = true;

  int P = primes[x].size();
  REP(mask, 1 << P) {
    int _cnt = 0;
    int d = 1;
    REP(i, P) if (mask & (1 << i)) { _cnt++; d *= primes[x][i]; }
    if (_cnt % 2 == 0) ans += cnt[d];
    else               ans -= cnt[d];
    cnt[d]++;
  }
}

void remove_it(int n) {
  int x = A[n];
  is_there[n] = false;

  int P = primes[x].size();
  REP(mask, 1 << P) {
    int _cnt = 0;
    int d = 1;
    REP(i, P) if (mask & (1 << i)) { _cnt++; d *= primes[x][i]; }
    cnt[d]--;
    if (_cnt % 2 == 0) ans -= cnt[d];
    else               ans += cnt[d];
  }
}

int main(int argc, char *argv[]) {
  FOR(i, 2, MAXN - 1) if (!primes[i].size()) for (int j = i; j < MAXN; j += i) primes[j].push_back(i);

  scanf("%d%d", &N, &Q);
  REP(i, N) scanf("%d", A + i);

  while (Q--) {
    int n;
    scanf("%d", &n); n--;
    if (is_there[n]) remove_it(n);
    else add_it(n);
    cout << ans << endl;
  }

  return 0;
}