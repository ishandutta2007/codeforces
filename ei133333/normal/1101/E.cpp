#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

template< class T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, -1);
  }

  T sum(int k) {
    T ret = -1;
    for(++k; k > 0; k -= k & -k) ret = max(ret, data[k]);
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] = max(data[k], x);
  }
};

template< class T >
struct BinaryIndexedTreeReversed {
  vector< T > data;

  BinaryIndexedTreeReversed(int sz) {
    data.assign(++sz, -1);
  }

  T sum(int k) {
    T ret = -1;
    for(++k; k < data.size(); k += k & -k) ret = max(ret, data[k]);
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k > 0; k -= k & -k) data[k] = max(data[k], x);
  }
};

int main() {
  int N, X[500000], Y[500000];
  char C[500000];

  scanf("%d", &N);
  vector< int > ys;
  for(int i = 0; i < N; i++) {
    scanf(" %c %d %d", &C[i], &X[i], &Y[i]);
    if(X[i] > Y[i])swap(X[i], Y[i]);
    ys.emplace_back(Y[i]);
  }
  sort(begin(ys), end(ys));
  ys.erase(unique(begin(ys), end(ys)), end(ys));
  BinaryIndexedTree< int > latte(ys.size() + 1);
  BinaryIndexedTreeReversed< int > malta(ys.size() + 1);
  int y_max = -1;
  for(int i = 0; i < N; i++) {
    Y[i] = lower_bound(begin(ys), end(ys), Y[i]) - begin(ys);
    if(C[i] == '+') {
      latte.add(Y[i], X[i]);
      malta.add(Y[i], X[i]);
      y_max = max(y_max, Y[i]);
    } else {
      if(y_max <= Y[i] && malta.sum(Y[i] + 1) <= X[i] && latte.sum(Y[i]) <= X[i]) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  }

  // HW

  // xy, xy
  // yH      xW
  // yH yW xH

}