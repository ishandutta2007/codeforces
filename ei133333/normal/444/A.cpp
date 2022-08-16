#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M, S[500];

  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    scanf("%d", S + i);
  }

  double ret = 0;
  for(int i = 0; i < M; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    ret = max(ret, double(S[--u] + S[--v]) / x);
  }

  cout << fixed << setprecision(10) << ret << endl;


}