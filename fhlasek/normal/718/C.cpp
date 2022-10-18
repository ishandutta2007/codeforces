/* Written by Filip Hlasek 2014 */
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

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)
#define REP(i, b) for(int i=0;i<b;i++)

using namespace std;

#define MOD 1000000007

struct Fib {
  int a, b, c, d;
  Fib(int x = 0) {
    if (x == 1) { a = 0; b = 1; c = 1; d = 1; }
    else        { a = 1; b = 0; c = 0; d = 1; }
  }
  bool operator ==(const Fib &x) const {
    return a == x.a && b == x.b && c == x.b && d == x.d;
  }
  Fib operator +(const Fib &x) const {
    Fib ans;
    ans.a = a + x.a;
    ans.b = b + x.b;
    ans.c = c + x.c;
    ans.d = d + x.d;
    if (ans.a >= MOD) ans.a -= MOD;
    if (ans.b >= MOD) ans.b -= MOD;
    if (ans.c >= MOD) ans.c -= MOD;
    if (ans.d >= MOD) ans.d -= MOD;
    return ans;
  }
  Fib operator *(const Fib &x) const {
    Fib ans;
    ans.a = ((long long)a * x.a + (long long)b * x.c) % MOD;
    ans.b = ((long long)a * x.b + (long long)b * x.d) % MOD;
    ans.c = ((long long)c * x.a + (long long)d * x.c) % MOD;
    ans.d = ((long long)c * x.b + (long long)d * x.d) % MOD;
    return ans;
  }
  Fib operator ^(long long exponent) const {
    Fib ans, tmp;
    tmp.a = a; tmp.b = b; tmp.c = c; tmp.d = d;
    while (exponent) {
      if (exponent & 1) ans = ans * tmp;
      tmp = tmp * tmp;
      exponent >>= 1;
    }
    return ans;
  }
};

template <class ValueType>
class SegmentTree {
  private:
    int SIZE; // the smallest power of two, which is at least number of elements
    int *Left, *Right;
    ValueType *value, *lazy_add;

    void clearVertex(int v) {
      if (!(lazy_add[v] == Fib())) {
        value[v] = value[v] * lazy_add[v];
        if (Left[v] + 1 != Right[v]) {
          lazy_add[2 * v] = lazy_add[2 * v] * lazy_add[v];
          lazy_add[2 * v + 1] = lazy_add[2 * v + 1] * lazy_add[v];
        }
        lazy_add[v] = Fib();
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
      if (l == Left[v] && r == Right[v]) {
        lazy_add[v] = val; return;
      }
      int middle = (Left[v] + Right[v]) / 2;
      if (middle >= r) add(2 * v, l, r, val);
      else if (middle <= l) add(2 * v + 1, l, r, val);
      else {
        add(2 * v, l, middle, val);
        add(2 * v + 1, middle, r, val);
      }
      clearVertex(2 * v); clearVertex(2 * v + 1);
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
      lazy_add = (ValueType*)malloc(sizeof(ValueType) * 2 * SIZE);

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
      }
    }
    ValueType getSum(int l, int r) { return getSum(1, l, r); }
    void add(int l, int r, ValueType val) { add(1, l, r, val); }
};

SegmentTree<Fib> s;
int main(int argc, char *argv[]) {
  int N, Q;
  scanf("%d%d", &N, &Q);
  s.init(N);
  REP(i, N) {
    int a;
    scanf("%d", &a);
    s.add(i, i + 1, Fib(1) ^ (a - 1));
  }
  while (Q--) {
    int type, l, r;
    scanf("%d%d%d", &type, &l, &r); l--;
    if (type == 1) {
      int a;
      scanf("%d", &a);
      s.add(l, r, Fib(1) ^ a);
    }
    else {
      Fib ans = s.getSum(l, r);
      printf("%d\n", (ans.a + ans.b) % MOD);
    }
  }
  return 0;
}