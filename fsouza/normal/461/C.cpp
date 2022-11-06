#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>
#include <map>
#include <set>

#define INF 1000000000

using namespace std;

typedef long long lint;

struct block {
  int offset;
  int l, r;
  inline int size() {return abs(l-r)+1;}
};

struct solver {
  vector<int> v;
  vector<int> sum;
  vector<block> blocks;

  solver(int n) {
    v = vector<int>(n, 1);
    sum = vector<int>(n+1, -1);
    for (int i = 0; i <= n; i++) sum[i] = i;
    blocks.clear();
    blocks.push_back((block){0, 0, n-1});
  }

  void rebuild() {
    int maxpos = -INF;

    for (int i = 0; i < (int)blocks.size(); i++)
      maxpos = max(maxpos, blocks[i].offset + blocks[i].size() - 1);
    
    vector<int> v2(maxpos + 1, 0);

    for (int i = 0; i < (int)blocks.size(); i++) {
      const block &bl = blocks[i];
      int place = bl.offset;

      if (bl.l <= bl.r) {
	for (int j = bl.l; j <= bl.r; j++)
	  v2[place++] += v[j];
      } else {
	for (int j = bl.l; j >= bl.r; j--)
	  v2[place++] += v[j];
      }
    }
    int v2size = v2.size();
    vector<int> sum2(v2size+1);
    sum2[0] = 0;
    for (int i = 0; i < v2size; i++)
      sum2[i+1] = sum2[i] + v2[i];

    swap(v, v2);
    swap(sum, sum2);

    blocks.clear();
    blocks.push_back((block){0, 0, v2size-1});
  }

  void fold(int div) {
    int nblock = blocks.size();

    for (int i = 0; i < nblock; i++) {
      block &b = blocks[i];

      int a2 = b.offset;
      int b2 = b.offset + b.size() - 1;
      
      if (a2 >= div) continue;
      if (b2 < div) {
	int a3, b3, d;
	
	d = (div-1) - a2;
	a3 = div+d;

	d = (div-1) - b2;
	b3 = div+d;

	block mirror;
	mirror.offset = b3;
	mirror.l = b.r;
	mirror.r = b.l;
	
	blocks[i] = mirror;
      } else {
	int a3 = a2, b3 = div-1;
	int a4 = div, b4 = b2;
	block bk3 = inblock(b, a3, b3);
	block bk4 = inblock(b, a4, b4);
	blocks[i] = bk4;
	blocks.push_back(bk3);
	nblock++;
      }
    }

    for (int i = 0; i < (int)blocks.size(); i++)
      blocks[i].offset -= div;
    if (blocks.size() > 500)
      rebuild();
  }

  block inblock(block &bl, int a, int b) {
    block ret;
    
    int a2 = bl.offset;
    int b2 = bl.offset + bl.size() - 1;

    int a3 = max(a, a2);
    int b3 = min(b, b2);

    assert(a3 <= b3);
    
    ret.offset = a3;
    if (bl.l <= bl.r) {
      ret.l = bl.l + (a3 - a2);
      ret.r = bl.r - (b2 - b3);
    } else {
      ret.l = bl.l - (a3 - a2);
      ret.r = bl.r + (b2 - b3);
    }
    
    return ret;
  }

  int query(int a, int b) {
    int ret = 0;

    for (int i = 0; i < (int)blocks.size(); i++) {
      block &bl = blocks[i];

      int a2 = bl.offset;
      int b2 = bl.offset + bl.size() - 1;
      
      int a3 = max(a, a2);
      int b3 = min(b, b2);

      if (a3 <= b3) {      
	if (bl.l <= bl.r) {
	  int l0 = bl.l + (a3 - a2);
	  int r0 = bl.r - (b2 - b3);
	  ret += sum[r0+1] - sum[l0];
	} else {
	  int l0 = bl.l - (a3 - a2);
	  int r0 = bl.r + (b2 - b3);
	  ret += sum[l0+1] - sum[r0];
	}
      }
    }
    
    return ret;
  }
};

int main() {
  int n, nq;
  
  scanf("%d %d", &n, &nq);

  solver s(n);

  for (int q = 0; q < nq; q++) {
    int kind;
    scanf("%d", &kind);

    if (kind == 1) {
      int pi;
      scanf("%d", &pi);
      s.fold(pi);
    } else {
      int li, ri;
      scanf("%d %d", &li, &ri);
      printf("%d\n", s.query(li, ri-1));
    }
  }

  return 0;
}