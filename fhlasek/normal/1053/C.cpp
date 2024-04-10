/* Written by Filip Hlasek 2018 */
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

#define MOD 1000000007
#define MAXN 222222
int A[MAXN];

class SegmentTree{
  private:
    int SIZE; // the smallest power of two, which is at least number of elements
    int *Left, *Right;
    long long *sum_w, *sum_left, *sum_right;

    long long getSum(int v, int l, int r) {
      if (l == Left[v] && r == Right[v]) return sum_w[v];
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) return getSum(2*v, l, r);
      if (middle <= l) return getSum(2*v+1, l, r);
      return getSum(2*v, l, middle) + getSum(2*v+1, middle, r);
    }

    int getLeft(int v, int l, int r) {
      if (l == Left[v] && r == Right[v]) {
        return sum_left[v];
      }
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) return getLeft(2*v, l, r);
      if (middle <= l) return getLeft(2*v+1, l, r);
      return (getLeft(2*v, l, middle) + getLeft(2*v+1, middle, r) + getSum(2*v+1, middle, r) % MOD * (A[middle] - A[l])) % MOD;
    }

    int getRight(int v, int l, int r) {
      if (l == Left[v] && r == Right[v]) {
        return sum_right[v];
      }
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) return getRight(2*v, l, r);
      if (middle <= l) return getRight(2*v+1, l, r);
      return (getRight(2*v, l, middle) + getRight(2*v+1, middle, r) + getSum(2*v, l, middle) % MOD * (A[r - 1] - A[middle - 1])) % MOD;

    }

    void setValue(int v, int i, long long val) {
      if (i == Left[v] && i + 1 == Right[v]) {
        sum_w[v] = val;
        return;
      }
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= i + 1) setValue(2*v, i, val);
      else setValue(2*v+1, i, val);
      sum_w[v] = sum_w[2*v] + sum_w[2*v+1];
      sum_left[v] = (sum_left[2*v] + sum_left[2*v+1] + sum_w[2*v+1] % MOD * (A[middle] - A[Left[v]])) % MOD;
      sum_right[v] = (sum_right[2*v] + sum_right[2*v+1] + sum_w[2*v] % MOD * (A[Right[v] - 1] - A[middle - 1])) % MOD;
    }

    int kth_index(int v, int l, long long k) {
      if (Left[v] + 1 == Right[v]) return Left[v];
      int middle = (Left[v] + Right[v]) / 2;
      if (middle <= l) return kth_index(2*v+1, l, k);
      long long s = getSum(2*v, l, middle);
      if (k < s) return kth_index(2*v, l, k);
      return kth_index(2*v+1, middle, k - s);
    }

  public:
    // Elements are indexed from 0 to len - 1
    // All queries work with elements l, l + 1, ... r - 1
    void init(int len) {
      for (SIZE = 1; SIZE < len; SIZE *= 2) ;

      Left = (int*)malloc(sizeof(int) * 2 * SIZE);
      Right = (int*)malloc(sizeof(int) * 2 * SIZE);
      sum_w = (long long*)malloc(sizeof(long long) * 2 * SIZE);
      sum_left = (long long*)malloc(sizeof(long long) * 2 * SIZE);
      sum_right = (long long*)malloc(sizeof(long long) * 2 * SIZE);

      Left[1] = 0;
      Right[1] = SIZE;
      FOR(i, 1, SIZE - 1) {
        Left[2*i] = Left[i];
        Right[2*i] = (Left[i] + Right[i]) / 2;
        Left[2*i + 1] = (Left[i] + Right[i]) / 2;
        Right[2*i + 1] = Right[i];
      }
      REP(i, 2 * SIZE) {
        sum_w[i] = sum_left[i] = sum_right[i] = 0;
      }
    }
    long long getSum(int l, int r) { return getSum(1, l, r); }
    void setValue(int i, long long val) { setValue(1, i, val); }
    int solve(int l, int r) {
      int mid = kth_index(1, l, getSum(l, r) / 2);
      // printf("mid: %d\n", mid);
      return (getRight(1, l, mid + 1) + getLeft(1, mid, r)) % MOD;
    }
    void print(int v=1, int indent=0) {
      REP(i, indent) printf(" ");
      printf("v=%d (%d-%d) sum: %lld sum_left: %lld sum_right: %lld\n", v, Left[v], Right[v], sum_w[v], sum_left[v], sum_right[v]);
      if (Left[v] + 1 < Right[v]) {
        print(2*v, indent + 2);
        print(2*v+1, indent + 2);
      }
    }
};

SegmentTree sg;

int main(int argc, char *argv[]) {
  int N, Q;
  scanf("%d%d", &N, &Q);
  sg.init(N);
  REP(i, N) {
    scanf("%d", A + i);
    A[i] -= i;
  }
  REP(i, N) {
    int w;
    scanf("%d", &w);
    sg.setValue(i, w);
  }
  // sg.print();
  while (Q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < 0) sg.setValue(-x-1, y);
    else printf("%d\n", sg.solve(x-1, y));
    // printf("x: %d y: %d\nTree:\n", x, y); sg.print();
  }
  return 0;
}