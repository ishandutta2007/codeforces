#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = (1 << 20) + 5;
const int M = 105;
const int INF = 0x3f3f3f3f;

int n, m, v[N], h[M], order[M][2], rec[N];

bool cmp(const int& a, const int& b) {
  return a > b;
}

void init() {
  memset(v, 0, sizeof(v));

  char ch;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &h[i]);
  sort(h, h + n, cmp);
  scanf("%d%*c", &m);
  for (int i = 0; i < m; i++) {
    scanf("%c %d%*c", &ch, &order[i][0]);
    order[i][1] = (ch == 'p' ? 1 : 0);
  }
  n = min(n, 20);
}

int dp(int s, int d) {
  if (v[s]) return rec[s];
  if (d >= m) return 0;
  int& ans = rec[s]; v[s] = 1;
  ans = 0;
  while (d < m) {

    if (order[d][1]) {
      int id;
      for (id = 0; id < n; id++) if ((s & (1 << id)) == 0) break;

      s += (1 << id);
      order[d][0] == 1 ? ans += h[id] : ans -= h[id];

    } else {

      int tmp = order[d][0] == 1 ? -INF : INF;
      for (int i = 0; i < n; i++) if ((s & (1 << i)) == 0) {
        int t = dp(s + (1 << i), d+1);
        if (order[d][0] == 1) tmp = max(tmp, t);
        else tmp = min(tmp, t);		
      }
      ans += tmp;
      break;
    }
    d++;
  }
  return ans;
}

int main () {
  init();
  printf("%d\n", dp(0, 0));
  return 0;
}