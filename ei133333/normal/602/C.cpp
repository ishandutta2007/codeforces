#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

int main()
{
  int N, M;
  int graph[400][400];
  int m1[400][400], m2[400][400];
  fill_n(*m1, 400 * 400, INF >> 1);
  fill_n(*m2, 400 * 400, INF >> 1);
  
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    m1[A][B] = m1[B][A] = 1;
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(m1[i][j] != 1) m2[i][j] = 1;
    }
  }
  for(int k = 0; k < N; k++) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        m1[i][j] = min(m1[i][j], m1[i][k] + m1[k][j]);
        m2[i][j] = min(m2[i][j], m2[i][k] + m2[k][j]);
      }
    }
  }

  if(m1[0][N - 1] == (INF >> 1) || m2[0][N - 1] == (INF >> 1)) {
    cout << -1 << endl;
  } else {
    cout << max(m1[0][N - 1], m2[0][N - 1]) << endl;
  }
}