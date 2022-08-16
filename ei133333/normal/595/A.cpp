#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N, M, A[2];
  cin >> N >> M;
  int ret = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 2 * M; j += 2) {
      cin >> A[0] >> A[1];
      if(A[0] || A[1]) ++ret;
    }
  }
  cout << ret << endl;
}