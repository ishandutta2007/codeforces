#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

vector<pair<int, int>> adj[6];
bool mark[1<<18];
int result;

void brute(int mask, int len, int n, int last) {
  {
    int mask2 = (mask | (7 << 3*len)) & ((1<<18)-1);
    if (mark[mask2]) return;
    mark[mask2] = true;
  }
  if (len == n) {
    ++result;
  } else {
    for (auto tomid : adj[last]) {
      int to, mid;
      tie(to, mid) = tomid;
      int mask2 = mask >> 3;
      mask2 = mask2 << 3 | mid;
      mask2 = mask2 << 3 | to;      
      brute(mask2, len+1, n, to);
    }
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; ++i) {
    char to, mid, from;
    scanf(" %c%c %c", &to, &mid, &from);
    adj[from-'a'].push_back({to-'a', mid-'a'});
  }

  memset(mark, 0, sizeof(mark));

  result = 0;
  brute(0, 1, n, 0);
  printf("%d\n", result);
  
  return 0;
}