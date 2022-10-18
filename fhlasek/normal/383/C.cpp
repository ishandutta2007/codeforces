/* Written by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)
#define REP(i, b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 222222
#define MAXM MAXN

int start[MAXN], n[2 * MAXM], cost[2 * MAXM], tmp[MAXN], eA[MAXM], eB[MAXM], eC[MAXM], N, M, _stack[MAXN], S;
int father[MAXN], depth[MAXN], root;
int Left[MAXN], Right[MAXN], array[MAXN], INDEX;

class Graph{
  public:
    void buildFromEdges(int _N, int _M) {
      N = _N;
      M = _M;
      REP(i, N) tmp[i] = 0;
      REP(i, M) {
        tmp[eA[i]]++;
        tmp[eB[i]]++; // comment if only one direction
      }
      REP(i, N) start[i+1] = start[i] + tmp[i];
      REP(i, M) {
        int a = start[eA[i]] + (--tmp[eA[i]]), b = start[eB[i]] + (--tmp[eB[i]]);
        n[a] = eB[i]; cost[a] = eC[i];
        n[b] = eA[i]; cost[b] = eC[i]; // comment if only one direction
      }
    }
};
class Tree : public Graph{
  public:
    void buildFromEdges(int _N) {
      Graph::buildFromEdges(_N, _N - 1);
      root = 0;
      father[root] = root;
      depth[root] = 0;
      S = 0;
      _stack[S++] = root;
      while(S) {
        int x = _stack[--S];
        for(int i = start[x]; i < start[x+1]; i++) {
          if(n[i] != father[x]) {
            father[n[i]] = x;
            depth[n[i]] = depth[x] + 1;
            _stack[S++] = n[i];
          }
        }
      }
    }

    void decompose_dfs(int v) {
      array[INDEX] = depth[v]; // WHATEVER
      Left[v] = INDEX++;
      for(int i = start[v]; i < start[v+1]; i++) if(n[i] != father[v])
        decompose_dfs(n[i]);
      Right[v] = INDEX;
    }
    void decompose() {
      INDEX = 0;
      decompose_dfs(0);
    }
};

int a[MAXN];

#define MAX (1<<18)
int _left[2*MAX], _right[2*MAX];
int value[2*MAX], minimum[2*MAX], maximum[2*MAX];
int lazy_add[2*MAX], lazy_set_val[2*MAX];
bool lazy_set[2*MAX];

template <class ValueType>
class SegmentTree{
  private:
    void clearVertex(int v) {
      if(lazy_set[v]) {
        value[v] = lazy_set_val[v] * (_right[v] - _left[v]);
        minimum[v] = maximum[v] = lazy_set_val[v];
        lazy_set[v] = false;
        if(_left[v] + 1 != _right[v]) {
          lazy_set[2*v] = lazy_set[2*v+1] = true;
          lazy_set_val[2*v] = lazy_set_val[2*v+1] = lazy_set_val[v];
          lazy_add[2*v] = lazy_add[2*v+1] = 0;
        }
      }
      if(lazy_add[v]) {
        value[v] += lazy_add[v] * (_right[v] - _left[v]);
        minimum[v] += lazy_add[v];
        maximum[v] += lazy_add[v];
        if(_left[v] + 1 != _right[v]) {
          if(lazy_set[2*v]) clearVertex(2*v);
          lazy_add[2*v] += lazy_add[v];
          if(lazy_set[2*v+1]) clearVertex(2*v+1);
          lazy_add[2*v+1] += lazy_add[v];
        }
        lazy_add[v] = 0;
      }
    }
    ValueType getSum(int v, int l, int r) {
      clearVertex(v);
      if(l == _left[v] && r == _right[v]) return value[v];
      int middle = (_left[v] + _right[v]) / 2;
      if(middle >= r) return getSum(2*v, l, r);
      if(middle <= l) return getSum(2*v+1, l, r);
      return getSum(2*v, l, middle) + getSum(2*v+1, middle, r);
    }
    ValueType getMin(int v, int l, int r) {
      clearVertex(v);
      if(l == _left[v] && r == _right[v]) return minimum[v];
      int middle = (_left[v] + _right[v]) / 2;
      if(middle >= r) return getMin(2*v, l, r);
      if(middle <= l) return getMin(2*v+1, l, r);
      return min(getMin(2*v, l, middle), getMin(2*v+1, middle, r));
    }
    ValueType getMax(int v, int l, int r) {
      clearVertex(v);
      if(l == _left[v] && r == _right[v]) return maximum[v];
      int middle = (_left[v] + _right[v]) / 2;
      if(middle >= r) return getMax(2*v, l, r);
      if(middle <= l) return getMax(2*v+1, l, r);
      return max(getMax(2*v, l, middle), getMax(2*v+1, middle, r));
    }
    void add(int v, int l, int r, ValueType val) {
      clearVertex(v);
      if(l == _left[v] && r == _right[v]) { lazy_add[v] = val; return; }
      int middle = (_left[v] + _right[v]) / 2;
      if(middle >= r) add(2*v, l, r, val);
      else if(middle <= l) add(2*v+1, l, r, val);
      else{
        add(2*v, l, middle, val);
        add(2*v+1, middle, r, val);
      }
      value[v] += (r-l) * val;
      minimum[v] = min(minimum[2*v] + lazy_add[2*v], minimum[2*v+1] + lazy_add[2*v+1]);
      maximum[v] = max(maximum[2*v] + lazy_add[2*v], maximum[2*v+1] + lazy_add[2*v+1]);
    }
    void setValue(int v, int l, int r, ValueType val) {
      clearVertex(v);
      if(l == _left[v] && r == _right[v]) { lazy_set_val[v] = val; lazy_set[v] = true; return; }
      int middle = (_left[v] + _right[v]) / 2;
      if(middle >= r) setValue(2*v, l, r, val);
      else if(middle <= l) setValue(2*v+1, l, r, val);
      else{
        setValue(2*v, l, middle, val);
        setValue(2*v+1, middle, r, val);
      }
      value[v] = ( lazy_set[2*v] ? lazy_set_val[2*v] * (middle - _left[v]) : value[2*v] ) +
             ( lazy_set[2*v+1] ? lazy_set_val[2*v+1] * (_right[v] - middle) : value[2*v+1] );
      minimum[v] = min( ( lazy_set[2*v] ? lazy_set_val[2*v] : minimum[2*v] ),
                    ( lazy_set[2*v+1] ? lazy_set_val[2*v+1] : minimum[2*v+1] ));
      maximum[v] = max( ( lazy_set[2*v] ? lazy_set_val[2*v] : maximum[2*v] ),
                    ( lazy_set[2*v+1] ? lazy_set_val[2*v+1] : maximum[2*v+1] ));
    }

  public:
    SegmentTree() {
      _left[1] = 0;
      _right[1] = MAX;
      FOR(i, 1, MAX-1) {
        _left[2*i] = _left[i];
        _right[2*i] = (_left[i] + _right[i]) / 2;
        _left[2*i+1] = (_left[i] + _right[i]) / 2;
        _right[2*i+1] = _right[i];
      }
      REP(i, 2*MAX) value[i] = minimum[i] = maximum[i] = lazy_add[i] = lazy_set[i] = 0;
    }
    ValueType getSum(int l, int r) { return getSum(1, l, r); }
    ValueType getMin(int l, int r) { return getMin(1, l, r); }
    ValueType getMax(int l, int r) { return getMax(1, l, r); }
    void add(int l, int r, ValueType val) { add(1, l, r, val); }
    void setValue(int l, int r, ValueType val) { setValue(1, l, r, val); }
};

Tree t;
SegmentTree<int> s;
int main(int argc, char *argv[]) {
  int N, Q;
  scanf("%d%d", &N, &Q);
  REP(i, N) scanf("%d", a + i);
  REP(i, N-1) {
    scanf("%d%d", eA+i, eB+i);
    eA[i]--; eB[i]--; // 1-indexed
  }
  t.buildFromEdges(N);
  t.decompose();

  int cmd, node, val;

  while(Q--) {
    scanf("%d%d", &cmd, &node); node--;
    if (cmd == 1) {
      scanf("%d", &val);
      if (depth[node] % 2 == 0) val *= -1;
      s.add(Left[node], Right[node], val);
    }
    else {
      val = s.getSum(Left[node], Left[node] + 1);
      if (depth[node] % 2 == 0) val *= -1;
      printf("%d\n", a[node] + val); 
    }
  }

  return 0;
}