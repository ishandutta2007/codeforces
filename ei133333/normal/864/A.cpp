#include<bits/stdc++.h>

using namespace std;

struct Taplis
{
  void TapTap()
  {
    int N, A[100];

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      scanf("%d", &A[i]);
    }

    if(N % 2 != 0) {
      cout << "NO" << endl;
      return;
    }

    sort(A, A + N);

    if(A[0] == A[N / 2 - 1] && A[N / 2] == A[N - 1] && A[0] != A[N - 1]) {
      cout << "YES" << endl;
      cout << A[0] << " " << A[N - 1] << endl;
    } else {
      cout << "NO" << endl;
    }
  }
};

int main()
{
  Taplis().TapTap();
}