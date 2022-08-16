#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[100];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  deque< int > deq;
  for(int i = 0; i < N; i++) {
    if(i & 1) deq.emplace_back(A[i]);
    else deq.emplace_front(A[i]);
  }
  for(auto p : deq) cout << p << " ";
  cout << endl;
}