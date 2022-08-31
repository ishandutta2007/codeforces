#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < N; i++) {
    vector< int > B;
    int highest = A[0];
    for(int j = 1; j < A.size(); j++) {
      if(abs(A[j] - A[j - 1]) >= 2) {
        cout << "NO" << endl;
        return (0);
      }
      highest = max(highest, A[j]);
    }
    for(int j = 0; j < A.size(); j++) {
      if(highest == A[j]) {
        highest = -1;
      } else {
        B.emplace_back(A[j]);
      }
    }
    A.swap(B);
  }
  cout << "YES" << endl;
}