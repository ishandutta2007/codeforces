#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 1000000

using namespace std;

typedef long long lint;

const lint inf = 1000000000000000LL;

int n;

struct bit {
  lint b[MAXN];

  bit() {
    for (int i = 0; i < MAXN; i++) b[i] = -inf;
  }
  
  lint get(int i) {
    lint ret = -inf;
    for (int j = i+1; j > 0; j -= j&-j)
      ret = max(ret, b[j-1]);
    return ret;
  }

  void add(int i, lint v) {
    for (int j = i+1; j <= n; j += j&-j)
      b[j-1] = max(b[j-1], v);
  }
} up, down;

int a[MAXN], cid[MAXN];

int main() {
  cin >> n;

  vector <pair<int, int> > comp;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    comp.push_back(make_pair(a[i], i));
  }
  sort(comp.begin(), comp.end());
  for (int i = 0; i < n; i++)
    cid[comp[i].second] = i;

  lint ndpi = 0;

  for (int i = n-1; i >= 0; i--) {
    lint dpi = -inf;

    dpi = max(dpi, -a[i] + up.get(n-1-cid[i]));
    dpi = max(dpi, a[i] + down.get(cid[i]));

    up.add(n-1-cid[i], a[i] + ndpi);
    down.add(cid[i], -a[i] + ndpi);
    
    ndpi = max(dpi, ndpi);
  }

  cout << ndpi << endl;

  return 0;
}