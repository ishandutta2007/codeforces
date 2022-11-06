#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

void solve(vector<int> &d, int a, int b, vector<int> &toleft, vector<int> &toright) {
  const int n = d.size();
  const int len = b-a+1;
  
  vector<pair<int, int>> vpos(len);
  for (int i = a; i <= b; ++i)
    vpos[i-a] = make_pair(d[i], i);
  sort(vpos.rbegin(), vpos.rend());
  
  set<int> setpos;
  setpos.insert(a-1);
  setpos.insert(b+1);

  for (int i = 0; i < len; ++i) {
    int v = vpos[i].first, pos = vpos[i].second;
    auto it = setpos.insert(pos).first;
    auto itl = it, itr = it;
    --itl, ++itr;
    int left = *itl, right = *itr;
    toleft[pos] = left+1;
    toright[pos] = right-1;
  }
}

int main() {
  int n, nq;
  scanf("%d %d", &n, &nq);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  vector<int> d(n-1);
  for (int i = 0; i+1 < n; ++i) d[i] = abs(a[i] - a[i+1]);

  vector<int> toleft(n-1), toright(n-1);
  solve(d, 0, n-2, toleft, toright);
  
  for (int q = 0; q < nq; ++q) {
    int l, r;
    scanf("%d %d", &l, &r), --l, --r;
    --r;

    lint ret = 0;
    for (int i = l; i <= r; ++i) {
      int tl = toleft[i], tr = toright[i];
      tl = max(tl, l);
      tr = min(tr, r);
      ret += (lint)(i-tl+1) * (tr-i+1) * d[i];
    }

    cout << ret << endl;
  }
  
  return 0;
}