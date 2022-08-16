#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int main() {
  int N;
  cin >> N;
  vector< int64 > B(N / 2);
  for(auto &c : B) cin >> c;
  vector< int64 > A(N);
  A[0] = 0;
  A[N - 1] = B[0];
  for(int i = 1; i < N / 2; i++) {
    int64 ok = B[i], ng = A[i - 1] - 1;
    while(ok - ng > 1) {
      int64 mid = (ok + ng) / 2;
      if(A[i - 1] <= mid && (B[i] - mid) <= A[N - i]) ok = mid;
      else ng = mid;
    }
    A[i] = ok;
    A[N - i - 1] = B[i] - ok;
  }

  for(int i = 0; i < N; i++) cout << A[i] << " ";
  cout << endl;

}