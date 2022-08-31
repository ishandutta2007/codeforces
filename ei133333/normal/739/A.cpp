#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main()
{
  int N, M;
  int K = INF;

  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++) {
    int U, V;
    scanf("%d %d", &U, &V);
    K = min(K, V - U + 1);
  }
  cout << K << endl;
  for(int i = 0; i < N; i++) {
    cout << i % K << " ";
  }
}

//[2 1 0]
//    [0 2 1]
//      [1 0]