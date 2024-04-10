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

#define MAXN 111111
int N, W, H;

struct Dancer {
  int g, p, t;
  int id;
  int x, y, ex, ey, val;
};

Dancer dancer[MAXN];
int ansX[MAXN], ansY[MAXN];
int o[MAXN];

bool cmp(int a, int b) {
  return dancer[a].val < dancer[b].val;
}

bool cmp2(int a, int b) {
  if (dancer[a].x != dancer[b].x) return dancer[a].x < dancer[b].x;
  return dancer[a].y > dancer[b].y;
}

bool cmp3(int a, int b) {
  if (dancer[a].ex != dancer[b].ex) return dancer[a].ex < dancer[b].ex;
  return dancer[a].ey > dancer[b].ey;
}

int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &W, &H);

  REP(i, N) {
    scanf("%d%d%d", &dancer[i].g, &dancer[i].p, &dancer[i].t);
    dancer[i].id = i;
    if (dancer[i].g == 1) {
      dancer[i].x = dancer[i].p;
      dancer[i].ex = dancer[i].p;
      dancer[i].y = 0;
      dancer[i].ey = H;
    } else {
      dancer[i].x = 0;
      dancer[i].ex = W;
      dancer[i].y= dancer[i].p;
      dancer[i].ey = dancer[i].p;
    }
    dancer[i].val = dancer[i].x + dancer[i].y - dancer[i].t;
    o[i] = i;
  }

  sort(o, o + N, cmp);
  int pos = 0;
  while (pos < N) {
    int start = pos;
    while (pos < N && dancer[o[pos]].val == dancer[o[start]].val) pos++;
    sort(o + start, o + pos, cmp2);
    vector<int> indexes;
    for (int i = start; i < pos; ++i) {
      indexes.push_back(dancer[o[i]].id);
    }
    sort(o + start, o + pos, cmp3);
    for (int i = start; i < pos; ++i) {
      ansX[indexes[i - start]] = dancer[dancer[o[i]].id].ex;
      ansY[indexes[i - start]] = dancer[dancer[o[i]].id].ey;
    }
  }

  REP(i, N) printf("%d %d\n", ansX[i], ansY[i]);
  return 0;
}