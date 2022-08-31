#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

int main()
{
  int N, M, B[100000], A[100001] = {};

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    int F;
    cin >> F;
    if(A[F] != 0) A[F] = -1;
    else A[F] = i + 1;
  }
  for(int i = 0; i < M; i++) {
    cin >> B[i];
  }

  stringstream S;
  bool F = false;
  for(int i = 0; i < M; i++) {
    if(i > 0) S << " ";
    if(A[B[i]] == 0) {
      cout << "Impossible" << endl;
      exit(0);
    } else if(A[B[i]] == -1) {
      F = true;
    } else {
      S << A[B[i]];
    }
  }
  if(F)  {
    cout << "Ambiguity" << endl;
  } else {
    cout << "Possible" << endl;
    cout << S.str() << endl;
  }
}