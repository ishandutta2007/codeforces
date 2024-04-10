#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct bit{
  bit() {};
  unsigned int a[(100000>>5) + 4];
  int size;
  void setSize(int sz) {
    // memset(a, 0, sizeof(a));
    size = (sz>>5) + 2;
  }
  void set(int pos, int val) {
    int ind=pos>>5;
    unsigned int r=1;
    if (val==1) {
      a[ind] |= r<<(pos&31);
    } else {
      if (a[ind] & (r<<(pos&31))) a[ind] -= r<<(pos&31);
    }
  }
  int get(int pos) {
    int ind=pos>>5;
    unsigned int r=1;
    return (a[ind]&(r<<(pos&31)))>0;
  }
  void shiftR(int n) {
    int cnt=n>>5;
    if (cnt)
      for(int i=size;i>=0;--i) {
        if (i+cnt<=size) a[i+cnt]=a[i];
        a[i]=0;
      }
    cnt=n&31;
    if (cnt) {
      unsigned int r=1,last=(r<<cnt)-1,mask=0;
      for(int i=0;i<=size;++i) {
        last=a[i]>>(32-cnt);
        a[i]<<=cnt; a[i]|=mask;
        mask=last;
      }
    }
  }
};

int n, d, x, a[100005], b[100005];

int getNextX() {
    x = (1LL * x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

bit bs, used, tmp;

int ans[100005], fbit[1<<16];

int main() {
  for (int mask = 0; mask < (1<<16); ++mask) {
    fbit[mask] = -1;
    for (int j = 0; j < 16; ++j) {
      if (mask & (1<<j)) {
        fbit[mask] = j;
        break;
      }
    }
  }
  scanf("%d%d%d", &n, &d, &x);
  bs.setSize(n);
  used.setSize(n);
  initAB();
  for (int i = 0; i < n; ++i) {
    if (b[i])
      bs.set(i, 1);
    used.set(i, 1);
  }
  vector<pair<int, int> > v;
  for (int i = 0; i < n; ++i) {
    v.push_back(make_pair(a[i], i));
  }
  sort(v.rbegin(), v.rend());
  int MASK = (1<<16) - 1;
  for (int t = 0; t < v.size(); ++t) {
    memcpy(tmp.a, bs.a, sizeof(tmp.a));
    tmp.size = bs.size;
    tmp.shiftR(v[t].second);
    // for (int i = 0; i < n; ++i)
    //   cout << tmp.get(i) << " ";
    // cout << endl;
    for (int i = 0; i < used.size; ++i) {
      if (used.a[i] & tmp.a[i]) {
        unsigned int val = used.a[i] & tmp.a[i], one = 1;
        /*for (int j = 0; j < 32; ++j) {
          if ((val & (one << j))) {
            used.set(i * 32 + j, 0);
            ans[i * 32 + j] = v[t].first;
          }
        }*/
        int mask = val & MASK, j;
        while (fbit[mask] != -1) {
          j = fbit[mask];
          mask -= 1 << j;
          used.set(i * 32 + j, 0);
          ans[i * 32 + j] = v[t].first;
        }
        mask = (val >> 16) & MASK;
        while (fbit[mask] != -1) {
          j = fbit[mask];
          mask -= 1 << j;
          used.set(i * 32 + 16 + j, 0);
          ans[i * 32 + 16 + j] = v[t].first;
        }  
      }
    }
  }
  for (int i = 0; i < n; ++i)
    printf("%d\n", ans[i]);
  return 0;
}