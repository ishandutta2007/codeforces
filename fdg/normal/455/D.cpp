#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[100005];

const int BSIZE = 1200;
const int CNT = 100000 / BSIZE + 1; 

struct item {
  item(int _val) : next(NULL), prev(NULL), val(_val) {};
  int val;
  item* next;
  item* prev;
};

item* all[100005];
item* wh[CNT];
int f[CNT][100005];

void shift(int l, int r) {
  if (l == r) return;
  int bl = l / BSIZE, br = r / BSIZE;
  item* last = wh[br];
  int pos = r - br * BSIZE;
  while (pos--) last = last->next;

  if (r == br * BSIZE) {
    wh[br] = last->prev;
    f[br - 1][wh[br]->val]--;
    f[br][wh[br]->val]++;
  }

  f[br][last->val]--;
  f[bl][last->val]++;
  if (last->prev != NULL)
    last->prev->next = last->next;
  if (last->next != NULL)
    last->next->prev = last->prev;

  last->prev = last->next = NULL;

  item* fir = wh[bl];
  pos = l - bl * BSIZE;
  while (pos--) fir = fir->next;

  if (fir->prev != NULL)
    fir->prev->next = last;
  last->prev = fir->prev;

  last->next = fir;
  fir->prev = last;

  if (l == bl * BSIZE) {
    wh[bl] = last;
  }

  for (int i = bl + 1; i <= br - (r ==  br * BSIZE); ++i) {
    wh[i] = wh[i]->prev;
  }
  for (int i = bl + 1; i <= br - (r ==  br * BSIZE); ++i) {
    f[i - 1][wh[i]->val]--;
    f[i][wh[i]->val]++;
  }
}

int calc(int l, int r, int k) {
  int ret = 0;
  
  int bl = l / BSIZE, br = r / BSIZE;
  if (bl == br) {
    item* last = wh[br];
    int pos = r - br * BSIZE;
    while (pos--) {
      last = last->next;
    }

    item* fir = wh[bl];
    pos = l - bl * BSIZE;
    while (pos--) fir = fir->next;
  
    do {
      if (fir->val == k) ++ret;
      if (fir == last) break;
      fir = fir->next;
    } while(1);
  } else {
    item* last = wh[br];
    int pos = r - br * BSIZE;
    while (pos--) {
      if (last->val == k) ++ret;
      last = last->next;
    }
    if (last->val == k) ++ret;

    item* fir = wh[bl];
    pos = l - bl * BSIZE;
    while (pos--) fir = fir->next;
    
    while (fir != wh[bl + 1]) {
      if (fir->val == k) ++ret;
      fir = fir->next;
    }

    for (int i = bl + 1; i < br; ++i)
      ret += f[i][k];
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    all[i] = new item(arr[i]);
    if (i > 0) all[i]->prev = all[i - 1];
    if (i % BSIZE == 0)
      wh[i / BSIZE] = all[i];
    f[i / BSIZE][arr[i]]++;
  }
  for (int i = 0; i + 1 < n; ++i)
    all[i]->next = all[i + 1];

  int q;
  scanf("%d", &q);
  int lans = 0;
  while (q--) {
    int t, l, r, k;
    scanf("%d%d%d", &t, &l, &r);
    l = (l + lans - 1) % n;
    r = (r + lans - 1) % n;
    if (l > r) swap(l, r);
    if (t == 1) {
      shift(l, r);
    } else {
      scanf("%d", &k);
      k = (k + lans - 1) % n + 1;
      lans = calc(l, r, k);
      printf("%d\n", lans);
    }
  }
  return 0;
}