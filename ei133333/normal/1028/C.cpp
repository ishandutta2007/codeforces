#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = (1 << 30) - 1;


int main() {
  int N;
  cin >> N;
  vector< int > A(N + 2), B(N + 2), C(N + 2), D(N + 2);
  A[0] = -INF, B[0] = -INF, C[0] = INF, D[0] = INF;
  for(int i = 1; i <= N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }
  A[N+1]=A[0], B[N+1]=B[0], C[N+1]=C[0], D[N+1]=D[0];

  vector< int > a(A), b(B), c(C), d(D);
  for(int i = A.size() - 2; i >= 0; i--) {
    a[i] = max(a[i], a[i + 1]);
    b[i] = max(b[i], b[i + 1]);
    c[i] = min(c[i], c[i + 1]);
    d[i] = min(d[i], d[i + 1]);
  }
  for(int i = 1; i < A.size(); i++) {
    A[i] = max(A[i], A[i - 1]);
    B[i] = max(B[i], B[i - 1]);
    C[i] = min(C[i], C[i - 1]);
    D[i] = min(D[i], D[i - 1]);
  }

  for(int i = 1; i + 1 < A.size(); i++) {
    int aa = max(A[i - 1], a[i + 1]);
    int bb = max(B[i - 1], b[i + 1]);
    int cc = min(C[i - 1], c[i + 1]);
    int dd = min(D[i - 1], d[i + 1]);

    if(aa <= cc && bb <= dd) {
      cout << aa << " " << bb << endl;
      return 0;
    }

  }

}