/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

template <class ValueType>
class SegmentTree {
  private:
    int SIZE; // the smallest power of two, which is at least number of elements
    int *Left, *Right;
    ValueType *value;
    ValueType *lazy_add, *lazy_set_val;
    bool *lazy_set;
    // TODO: It is faster to have an array of Nodes instead of multiple arrays.

    void clearVertex(int v) {
      if (lazy_set[v]) {
        value[v] = lazy_set_val[v] * (Right[v] - Left[v]);
        lazy_set[v] = false;
        if (Left[v] + 1 != Right[v]) {
          lazy_set[2 * v] = lazy_set[2 * v + 1] = true;
          lazy_set_val[2 * v] = lazy_set_val[2 * v + 1] = lazy_set_val[v];
          lazy_add[2 * v] = lazy_add[2 * v + 1] = 0;
        }
      }
      if (lazy_add[v]) {
        value[v] += lazy_add[v] * (Right[v] - Left[v]);
        if (Left[v] + 1 != Right[v]) {
          if (lazy_set[2 * v]) clearVertex(2 * v);
          lazy_add[2 * v] += lazy_add[v];
          if (lazy_set[2 * v + 1]) clearVertex(2 * v + 1);
          lazy_add[2 * v + 1] += lazy_add[v];
        }
        lazy_add[v] = 0;
      }
    }
    ValueType getSum(int v, int l, int r) {
      clearVertex(v);
      if (l == Left[v] && r == Right[v]) return value[v];
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) return getSum(2 * v, l, r);
      if (middle <= l) return getSum(2 * v + 1, l, r);
      return getSum(2 * v, l, middle) + getSum(2 * v + 1, middle, r);
    }
    void add(int v, int l, int r, ValueType val) {
      clearVertex(v);
      if (l == Left[v] && r == Right[v]) { lazy_add[v] = val; return; }
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) add(2 * v, l, r, val);
      else if (middle <= l) add(2 * v + 1, l, r, val);
      else {
        add(2 * v, l, middle, val);
        add(2 * v + 1, middle, r, val);
      }
      clearVertex(2 * v); clearVertex(2 * v + 1);
      value[v] += (r - l) * val;
    }

  public:
    // Elements are indexed from 0 to len - 1
    // All queries work with elements l, l + 1, ... r - 1
    void init(int len) {
      for (SIZE = 1; SIZE < len; SIZE *= 2) ;

      Left = (int*)malloc(sizeof(int) * 2 * SIZE);
      Right = (int*)malloc(sizeof(int) * 2 * SIZE);
      value = (ValueType*)malloc(sizeof(ValueType) * 2 * SIZE);
      lazy_add = (ValueType*)malloc(sizeof(ValueType) * 2 * SIZE);
      lazy_set_val = (ValueType*)malloc(sizeof(ValueType) * 2 * SIZE);
      lazy_set = (bool*)malloc(sizeof(bool) * 2 * SIZE);

      Left[1] = 0;
      Right[1] = SIZE;
      FOR(i, 1, SIZE - 1) {
        Left[2 * i] = Left[i];
        Right[2 * i] = (Left[i] + Right[i]) / 2;
        Left[2 * i + 1] = (Left[i] + Right[i]) / 2;
        Right[2 * i + 1] = Right[i];
      }
      REP(i, 2 * SIZE) {
        value[i] = lazy_add[i] = ValueType();
        lazy_set[i] = false;
      }
    }
    ValueType getSum(int l, int r) { return l == r ? 0 : getSum(1, l, r); }
    void add(int l, int r, ValueType val) { add(1, l, r, val); }
};

SegmentTree<int> s;

int main(int argc, char *argv[]) {
  int N, K;
  scanf("%d%d", &N, &K);
  K = min(K, N - K);
  long long ans = 1;
  s.init(N + 1);
  int X = 0;
  REP(i, N) {
    int Y = X + K;
    ans++;
    if (Y < N) ans += s.getSum(X + 1, Y);
    else {
      Y -= N;
      ans += s.getSum(X + 1, N) + s.getSum(0, Y);
    }
    s.add(X, X + 1, 1);
    s.add(Y, Y + 1, 1);
    X = Y;
    if (i) cout << " ";
    cout << ans;
  }
  cout << endl;
  return 0;
}