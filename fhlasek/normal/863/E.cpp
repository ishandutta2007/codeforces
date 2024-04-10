/* Written by Filip Hlasek 2017 */
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

#define MAXN 222222
int N;
int L[MAXN], R[MAXN];

template <class ValueType>
class SegmentTree{
  private:
    int SIZE; // the smallest power of two, which is at least number of elements
    int *Left, *Right;
    ValueType *value, *minimum, *maximum;
    ValueType *lazy_add, *lazy_set_val;
    bool *lazy_set;

    void clearVertex(int v) {
      if (lazy_set[v]) {
        value[v] = lazy_set_val[v] * (Right[v] - Left[v]);
        minimum[v] = maximum[v] = lazy_set_val[v];
        lazy_set[v] = false;
        if (Left[v] + 1 != Right[v]) {
          lazy_set[2*v] = lazy_set[2*v + 1] = true;
          lazy_set_val[2*v] = lazy_set_val[2*v + 1] = lazy_set_val[v];
          lazy_add[2*v] = lazy_add[2*v + 1] = 0;
        }
      }
      if (lazy_add[v]) {
        value[v] += lazy_add[v] * (Right[v] - Left[v]);
        minimum[v] += lazy_add[v];
        maximum[v] += lazy_add[v];
        if (Left[v] + 1 != Right[v]) {
          if (lazy_set[2*v]) clearVertex(2*v);
          lazy_add[2*v] += lazy_add[v];
          if (lazy_set[2*v + 1]) clearVertex(2*v + 1);
          lazy_add[2*v + 1] += lazy_add[v];
        }
        lazy_add[v] = 0;
      }
    }
    ValueType getSum(int v, int l, int r) {
      clearVertex(v);
      if (l == Left[v] && r == Right[v]) return value[v];
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) return getSum(2*v, l, r);
      if (middle <= l) return getSum(2*v+1, l, r);
      return getSum(2*v, l, middle) + getSum(2*v+1, middle, r);
    }
    ValueType getMin(int v, int l, int r) {
      clearVertex(v);
      if (l == Left[v] && r == Right[v]) return minimum[v];
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) return getMin(2*v, l, r);
      if (middle <= l) return getMin(2*v+1, l, r);
      return min(getMin(2*v, l, middle), getMin(2*v+1, middle, r));
    }
    ValueType getMax(int v, int l, int r) {
      clearVertex(v);
      if (l == Left[v] && r == Right[v]) return maximum[v];
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) return getMax(2*v, l, r);
      if (middle <= l) return getMax(2*v+1, l, r);
      return max(getMax(2*v, l, middle), getMax(2*v+1, middle, r));
    }
    void add(int v, int l, int r, ValueType val) {
      clearVertex(v);
      if (l == Left[v] && r == Right[v]) { lazy_add[v] = val; return; }
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) add(2*v, l, r, val);
      else if (middle <= l) add(2*v+1, l, r, val);
      else {
        add(2*v, l, middle, val);
        add(2*v+1, middle, r, val);
      }
      clearVertex(2*v); clearVertex(2*v+1);
      value[v] += (r-l) * val;
      minimum[v] = min(minimum[2*v], minimum[2*v+1]);
      maximum[v] = max(maximum[2*v], maximum[2*v+1]);
      /*
      value[v] += (r-l) * val;
      minimum[v] = min(minimum[2*v] + lazy_add[2*v], minimum[2*v+1] + lazy_add[2*v+1]);
      maximum[v] = max(maximum[2*v] + lazy_add[2*v], maximum[2*v+1] + lazy_add[2*v+1]);
      */
    }
    void setValue(int v, int l, int r, ValueType val) {
      clearVertex(v);
      if (l == Left[v] && r == Right[v]) {
        lazy_set_val[v] = val; lazy_set[v] = true; return;
      }
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) setValue(2*v, l, r, val);
      else if (middle <= l) setValue(2*v+1, l, r, val);
      else {
        setValue(2*v, l, middle, val);
        setValue(2*v+1, middle, r, val);
      }
      clearVertex(2*v); clearVertex(2*v+1);
      value[v] = value[2*v] + value[2*v+1];
      minimum[v] = min(minimum[2*v], minimum[2*v+1]);
      maximum[v] = max(maximum[2*v], maximum[2*v+1]);
      /*
      value[v] = ( lazy_set[2*v] ? lazy_set_val[2*v] * (middle - Left[v]) : value[2*v] ) +
             ( lazy_set[2*v+1] ? lazy_set_val[2*v+1] * (Right[v] - middle) : value[2*v+1] );
      minimum[v] = min( ( lazy_set[2*v] ? lazy_set_val[2*v] : minimum[2*v] ),
                    ( lazy_set[2*v+1] ? lazy_set_val[2*v+1] : minimum[2*v+1] ));
      maximum[v] = max( ( lazy_set[2*v] ? lazy_set_val[2*v] : maximum[2*v] ),
                    ( lazy_set[2*v+1] ? lazy_set_val[2*v+1] : maximum[2*v+1] ));
      */
    }

  public:
    // Elements are indexed from 0 to len - 1
    // All queries work with elements l, l + 1, ... r - 1
    void init(int len) {
      for (SIZE = 1; SIZE < len; SIZE *= 2) ;

      Left = (int*)malloc(sizeof(int) * 2 * SIZE);
      Right = (int*)malloc(sizeof(int) * 2 * SIZE);
      value = (ValueType*)malloc(sizeof(ValueType) * 2 * SIZE);
      minimum = (ValueType*)malloc(sizeof(ValueType) * 2 * SIZE);
      maximum = (ValueType*)malloc(sizeof(ValueType) * 2 * SIZE);
      lazy_add = (ValueType*)malloc(sizeof(ValueType) * 2 * SIZE);
      lazy_set_val = (ValueType*)malloc(sizeof(ValueType) * 2 * SIZE);
      lazy_set = (bool*)malloc(sizeof(bool) * 2 * SIZE);

      Left[1] = 0;
      Right[1] = SIZE;
      FOR(i, 1, SIZE - 1) {
        Left[2*i] = Left[i];
        Right[2*i] = (Left[i] + Right[i]) / 2;
        Left[2*i + 1] = (Left[i] + Right[i]) / 2;
        Right[2*i + 1] = Right[i];
      }
      REP(i, 2 * SIZE) {
        value[i] = minimum[i] = maximum[i] = lazy_add[i] = ValueType();
        lazy_set[i] = false;
      }
    }
    ValueType getSum(int l, int r) { return getSum(1, l, r); }
    ValueType getMin(int l, int r) { return getMin(1, l, r); }
    ValueType getMax(int l, int r) { return getMax(1, l, r); }
    void add(int l, int r, ValueType val) { add(1, l, r, val); }
    void setValue(int l, int r, ValueType val) { setValue(1, l, r, val); }
};

set<int> events;
SegmentTree<int> s;
map<int, int> m;

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) {
    scanf("%d%d", L + i, R + i);
    FOR(d, -1, 1) {
      events.insert(L[i] + d);
      events.insert(R[i] + d);
    }
  }
  vector<int> v(events.begin(), events.end());
  s.init(v.size());
  REP(i, v.size()) m[v[i]] = i;

  REP(i, N) s.add(m[L[i]], m[R[i]] + 1, 1);
  REP(i, N) if (s.getMin(m[L[i]], m[R[i]] + 1) > 1) {
    printf("%d\n", i + 1);
    return 0;
  }

  printf("-1\n");
  return 0;
}