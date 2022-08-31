#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N, M, D[100000], H[100000];

  cin >> N >> M;
  for(int i = 0; i < M; i++) cin >> D[i] >> H[i];

  int ret = 0;
  for(int i = 1; i < M; i++) {
    int distance = D[i] - D[i - 1];
    int height = abs(H[i] - H[i - 1]);
    if(height > distance) {
      cout << "IMPOSSIBLE" << endl;
      return (0);
    }
    distance -= max(H[i], H[i - 1]) - min(H[i], H[i - 1]);
    ret = max(ret, max(H[i], H[i - 1]) + distance / 2);
  }
  ret = max(ret, H[0] + D[0] - 1);
  ret = max(ret, (N - D[M - 1]) + H[M - 1]);

  cout << ret << endl;

}