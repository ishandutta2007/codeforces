#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N, A[100];

  cin >> N;
  int all = 0;

  for(int i = 0; i < N; i++) {
    cin >> A[i];
    all += A[i];
  }
  sort(A, A + N);


  int low = INF;
  for(int i = 0; low == INF; i++) {
    if(i * 2 >= N * 9) low = i;
  }

  int need = 0;
  if(all < low) {
    for(int i = 0; i < N; i++) {
      all -= A[i];
      all += 5;
      if(all >= low) {
        need = i + 1;
        break;
      }
    }
  }

  cout << need << endl;
}