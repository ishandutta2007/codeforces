#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N, L[100000], R[100000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
  }

  int A = accumulate(L, L + N, 0);
  int B = accumulate(R, R + N, 0);
  int ret = abs(A - B);

  for(int i = 0; i < N; i++) {
    ret = max(ret, abs(A - B + (R[i] - L[i]) * 2));
  }

  for(int i = 0; i < N; i++) {
    if(ret == abs(A - B + (R[i] - L[i]) * 2)) {
      cout << i + 1 << endl;
      return(0);
    }
  }

  cout << 0 << endl;

}