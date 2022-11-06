#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct guy {
  int c, d, k, oldid;
  bool operator < (const guy &other) const {
    if (c != other.c) return c < other.c;
    return d < other.d;
  }
};

int main() {
  int nwant;

  scanf("%d", &nwant);
  
  vector<int> ans(nwant, -1);
  vector <pair<pair<int,int>, int> > want;

  for (int i = 0; i < nwant; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    want.push_back(make_pair(make_pair(a, b), i));
  }
  sort(want.begin(), want.end());
  
  int nhave;

  scanf("%d", &nhave);
  
  vector <guy> have;

  for (int i = 0; i < nhave; i++) {
    int c, d, k;
    scanf("%d %d %d", &c, &d, &k);
    have.push_back((guy){c, d, k, i}); 
  }
  sort(have.begin(), have.end());

  set<pair<int, pair<int, int> > > havenow; // pos, many, oldhaveid

  bool ok = true;

  int j = 0;
  for (int i = 0; i < nwant; i++) {
    int a = want[i].first.first, b = want[i].first.second;
    int oldwantid = want[i].second;

    while (j < nhave && have[j].c <= a) {
      havenow.insert(make_pair(have[j].d, make_pair(have[j].k, have[j].oldid)));
      j++;
    }

    set<pair<int, pair<int, int> > >::iterator it;

    it = havenow.lower_bound(make_pair(b, make_pair(-1, -1)));
    if (it == havenow.end()) {
      ok = false;
      break;
    }

    pair<int, pair<int, int> > got = *it;
    havenow.erase(it);

    assert(got.first >= b);
    assert(got.second.first >= 1);
    got.second.first -= 1;
    
    ans[oldwantid] = got.second.second;

    if (got.second.first > 0) {
      havenow.insert(got);
    }
  }

  if (ok) {
    printf("YES\n");
    for (int i = 0; i < nwant; i++) {
      if (i-1 >= 0) printf(" ");
      printf("%d", ans[i]+1);
    }
    printf("\n");
  } else {
    printf("NO\n");
  }

  return 0;
}