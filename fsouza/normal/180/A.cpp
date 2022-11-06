#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <numeric>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef long long lint;

void move(int a, int b, vector< pair<int, int> > &hd, vector< pair<int, int> > &ret, int &freeguy) {
  hd[b] = hd[a];
  hd[a] = make_pair(-1, -1);
  ret.push_back(make_pair(a, b));

  freeguy = a;
}

int main() {
  int n, m;
  
  scanf("%d %d", &n, &m);

  vector< pair<int, int> > hd(n, make_pair(-1, -1));

  for (int i = 0; i < m; i++) {
    int nb;
    scanf("%d", &nb);
    for (int j = 0; j < nb; j++) {
      int b;
      scanf("%d", &b); b--;
      hd[b] = make_pair(i, j);
    }
  }

  vector< pair<int, int> > result;

  int freeguy = -1;
  for (int i = 0; i < n; i++) if (hd[i].first == -1) freeguy = i;
  int now = 0;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      int pos = find(hd.begin(), hd.end(), make_pair(i, j)) - hd.begin();
      if (pos == n) break;

      if (hd[now].first == -1) {
	move(pos, now, hd, result, freeguy);
      } else if (pos == now) {
      } else {
	move(now, freeguy, hd, result, freeguy);
	move(pos, now, hd, result, freeguy);
      }

      now++;
    }

  printf("%d\n", (int)result.size());
  for (int i = 0; i < (int)result.size(); i++)
    printf("%d %d\n", result[i].first+1, result[i].second+1);

  return 0;
}