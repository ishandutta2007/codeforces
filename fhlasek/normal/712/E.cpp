/* Written by Filip Hlasek 2016 */
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
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

class Win {
public:
  long double l, r;
  Win operator+(const Win &other) const {
    long double c = other.l / (1 - (1 - other.l) * r);
    Win ans;
    ans.l = l * c;
    ans.r = other.r + (1 - other.r) * r * c;
    return ans;
  }
};

template <class ValueType>
class SegmentTree {
  private:
    int SIZE; // the smallest power of two, which is at least number of elements
    int *Left, *Right;
    ValueType *value;

    ValueType getSum(int v, int l, int r) {
      if (l == Left[v] && r == Right[v]) return value[v];
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) return getSum(2 * v, l, r);
      if (middle <= l) return getSum(2 * v + 1, l, r);
      return getSum(2 * v, l, middle) + getSum(2 * v + 1, middle, r);
    }
    void setValue(int v, int l, int r, ValueType val) {
      if (l == Left[v] && r == Right[v]) {
        value[v] = val;
        return;
      }
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) setValue(2 * v, l, r, val);
      else if (middle <= l) setValue(2 * v + 1, l, r, val);
      else {
        setValue(2 * v, l, middle, val);
        setValue(2 * v + 1, middle, r, val);
      }
      value[v] = value[2 * v] + value[2 * v + 1];
    }

  public:
    // Elements are indexed from 0 to len - 1
    // All queries work with elements l, l + 1, ... r - 1
    void init(int len) {
      for (SIZE = 1; SIZE < len; SIZE *= 2) ;

      Left = (int*)malloc(sizeof(int) * 2 * SIZE);
      Right = (int*)malloc(sizeof(int) * 2 * SIZE);
      value = (ValueType*)malloc(sizeof(ValueType) * 2 * SIZE);

      Left[1] = 0;
      Right[1] = SIZE;
      FOR(i, 1, SIZE - 1) {
        Left[2 * i] = Left[i];
        Right[2 * i] = (Left[i] + Right[i]) / 2;
        Left[2 * i + 1] = (Left[i] + Right[i]) / 2;
        Right[2 * i + 1] = Right[i];
      }
      REP(i, 2 * SIZE) {
        value[i] = ValueType();
      }
    }
    ValueType getSum(int l, int r) { return getSum(1, l, r); }
    void setValue(int l, int r, ValueType val) { setValue(1, l, r, val); }
};

SegmentTree<Win> s;

int main(int argc, char *argv[]) {
  int N, Q;
  scanf("%d%d", &N, &Q);
  s.init(N + 1);
  REP(i, N) {
    int a, b;
    scanf("%d%d", &a, &b);
    long double p = (long double)a / b;
    Win w;
    w.l = w.r = p;
    s.setValue(i, i + 1, w);
  }
  while (Q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int a, b, i;
      scanf("%d%d%d", &i, &a, &b);
      long double p = (long double)a / b;
      Win w;
      w.l = w.r = p;
      s.setValue(i - 1, i, w);
    }
    else {
      int l, r;
      scanf("%d%d", &l, &r);
      Win w = s.getSum(l - 1, r);
      printf("%.15lf\n", (double)w.l);
    }
  }
  return 0;
}