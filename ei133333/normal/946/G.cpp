#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

template< class T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, -INF);
  }

  T sum(int k) {
    T ret = -INF;
    for(++k; k > 0; k -= k & -k) ret = max(ret, data[k]);
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] = max(data[k], x);
  }
};


int main() {
  int N;
  int A[200002], B[200002];

  cin >> N;
  N += 2;
  vector< int > xs, ys;
  for(int i = 0; i < N; i++) {
    if(i == 0) A[i] = -1600000000;
    else if(i + 1 < N) cin >> A[i];
    else A[i] = 1600000001;
    B[i] = A[i] - i + 1;
    A[i] = A[i] - i;
    xs.emplace_back(A[i]);
    xs.emplace_back(B[i]);
    ys.emplace_back(B[i]);
  }

  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  sort(begin(ys), end(ys));
  ys.erase(unique(begin(ys), end(ys)), end(ys));

  BinaryIndexedTree< int > dp2(ys.size());
  BinaryIndexedTree< int > dp_pv(xs.size());

  for(int i = 0; i < N; i++) {
    int vv = lower_bound(begin(xs), end(xs), B[i]) - begin(xs);
    A[i] = lower_bound(begin(xs), end(xs), A[i]) - begin(xs);
    B[i] = lower_bound(begin(ys), end(ys), B[i]) - begin(ys);
    dp2.add(B[i], max(dp_pv.sum(vv), dp2.sum(B[i])) + 1);
    if(i) dp_pv.add(A[i - 1], max(dp_pv.sum(A[i - 1]) + 1, 1));
  }
  cout << (N - 1) - dp2.sum((int) ys.size() - 1) << endl;
}