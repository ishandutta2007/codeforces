#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 100000

using namespace std;

struct snapshot {
  int when;
  int linkl, linkr;
  int toleft, toright, maxblock;
};

bool operator < (const snapshot &ss, int link) {
  return ss.when < link;
}

vector<snapshot> tree[4*MAXN];

void init(int n, int l, int r) {
  if (l != r) {
    int m = (l+r)/2;
    init(2*n+1, l, m);
    init(2*n+2, m+1, r);
    tree[n].push_back((snapshot){-1, 0, 0, 0, 0, 0});
  } else {
    tree[n].push_back((snapshot){-1, -1, -1, 0, 0, 0});
  }
}

int h[MAXN];

void update(int now, int guy, int n, int l, int r) {
  if (l == r) {
    tree[n].push_back((snapshot){now, -1, -1, 1, 1, 1});
  } else {
    int m = (l+r)/2;
    if (guy <= m) update(now, guy, 2*n+1, l, m);
    else update(now, guy, 2*n+2, m+1, r);
    
    int sizel = (m-l+1);
    snapshot &snapl = tree[2*n+1].back();
    int sizer = (r-(m+1)+1);
    snapshot &snapr = tree[2*n+2].back();

    int tl, tr, mb;

    tl = snapr.toleft;
    if (tl == sizer)
      tl = sizer + snapl.toleft;

    tr = snapl.toright;
    if (tr == sizel)
      tr = sizel + snapr.toright;
    
    mb = max(snapl.maxblock, snapr.maxblock);
    mb = max(mb, snapl.toleft + snapr.toright);

    tree[n].push_back((snapshot){now, tree[2*n+1].size()-1, tree[2*n+2].size()-1, tl, tr, mb});
  }
}

snapshot query(int link, int a, int b, int n, int l, int r) {
  if (a > r || b < l) {
    return (snapshot){-2, -2, -2, 0, 0, 0};
  } else if (a <= l && r <= b) {
    return tree[n][link];
  } else {
    int m = (l+r)/2;

    int sizel = (m-l+1);
    snapshot snapl = query(tree[n][link].linkl, a, b, 2*n+1, l, m);
    int sizer = (r-(m+1)+1);
    snapshot snapr = query(tree[n][link].linkr, a, b, 2*n+2, m+1, r);

    int tl, tr, mb;

    tl = snapr.toleft;
    if (tl == sizer)
      tl = sizer + snapl.toleft;

    tr = snapl.toright;
    if (tr == sizel)
      tr = sizel + snapr.toright;
    
    mb = max(snapl.maxblock, snapr.maxblock);
    mb = max(mb, snapl.toleft + snapr.toright);

    return (snapshot){-2, -2, -2, tl, tr, mb};
  }
}

int query(int now, int a, int b, int n) {
  int link = lower_bound(tree[0].begin(), tree[0].end(), now) - tree[0].begin();
  return query(link, a, b, 0, 0, n-1).maxblock;
}

int main() {
  int n;

  scanf("%d", &n);

  vector <pair <int, int> > sh(n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
    sh[i] = make_pair(h[i], i);
  }
  sort(sh.rbegin(), sh.rend());

  init(0, 0, n-1);

  for (int i = 0; i < n; i++) {
    update(i, sh[i].second, 0, 0, n-1);
  }

  int nq;

  scanf("%d", &nq);

  for (int q = 0; q < nq; q++) {
    int l, r, w;
    scanf("%d %d %d", &l, &r, &w); l--, r--;
    
    int a = 0, b = n-1;
    
    while (a < b) {
      int m = (a+b)/2;
      if (query(m, l, r, n) >= w) b = m;
      else a = m+1;
    }
    
    printf("%d\n", sh[a].first);
  }

  return 0;
}