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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111111
#define LOG 22
char line[MAXN];

int closing[MAXN], N;
int min_balance[LOG][MAXN];

int main(int argc, char *argv[]) {
  scanf("%s", line);
  N = strlen(line);
  REP(i, N) closing[i + 1] = closing[i] + (line[i] == ')');
  REP(i, N) min_balance[0][i + 1] = min_balance[0][i] + (line[i] == '(' ? 1 : -1);
  REP(_log, LOG - 1) REP(i, N + 1) if (i + (1 << (_log + 1)) <= N + 1)
    min_balance[_log + 1][i] = min(min_balance[_log][i], min_balance[_log][i + (1 << _log)]);
  
  int Q;
  scanf("%d", &Q);
  while(Q--) {
    int L, R;
    scanf("%d%d", &L, &R);
    int l = L, m_balance = MAXN;
    REP(_log, LOG) if ((R - L + 1) & (1 << _log)) {
      m_balance = min(m_balance, min_balance[_log][l]);
      l += (1 << _log);
    }
    m_balance -= min_balance[0][L - 1];
    int _close = closing[R] - closing[L - 1], _open = R - L + 1 - _close;
    int total_balance = min_balance[0][R] - min_balance[0][L - 1];
    if (m_balance < 0) {
      _close += m_balance;
      total_balance -= m_balance;
    }
    if (total_balance > 0) _open -= total_balance;
    printf("%d\n", 2 * (min(_open, _close)));
  }
  
  return 0;
}