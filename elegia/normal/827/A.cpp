#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

const int L = 2000010, N = 100010;

int n, l;
vector<int> tag[L];
int ll[N];
char* pos[N];
char s[L], sv[L];

int main() {
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  scanf("%d", &n);
  char* p = sv;
  for (int i = 1; i <= n; ++i) {
    scanf(" %s", p);
    pos[i] = p;
    int len = strlen(p);
    ll[i] = len;
    p += len + 1;
    int c;
    scanf("%d", &c);
    while (c--) {
      int t;
      scanf("%d", &t);
      tag[t].push_back(i);
      l = max(l, t + len - 1);
    }
  }
  queue<pair<int, int>> q;
  for (int i = 1; i <= l; ++i) {
    for (const auto& v : tag[i])
      q.push(make_pair(i + ll[v] - 1, v));
    while (!q.empty() && q.front().first < i)
      q.pop();
    if (q.empty())
      s[i] = 'a';
    else {
      int ed = q.front().first, v = q.front().second;
      s[i] = pos[v][ll[v] - (ed - i) - 1];
    }
  }
  puts(s + 1);
}