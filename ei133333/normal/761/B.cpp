#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, L, A[50], B[50];

  cin >> N >> L;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  for(int i = 0; i < L; i++) {
    for(int j = 0; j < L; j++) {
      vector< bool > add1(L, false), add2(L, false);
      for(int k = 0; k < N; k++) add1[(i + A[k]) % L] = true;
      for(int k = 0; k < N; k++) add2[(j + B[k]) % L] = true;
      bool match = true;
      for(int k = 0; k < L; k++) if(add1[k] != add2[k]) match = false;
      if(match) {
        cout << "YES" << endl;
        return(0);
      }
    }
  }

  cout << "NO" << endl;
}