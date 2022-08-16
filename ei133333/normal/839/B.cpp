#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, K, A[100];

  cin >> N >> K;
  for(int i = 0; i < K; i++) cin >> A[i];
  sort(A, A + K);

  for(int i = 0; i <= N; i++) {
    int one = i;
    int two = N * 2 + i;
    int four = N - i;

    bool flag = true;

    for(int j = K - 1; j >= 0; j--) {
      int get = A[j];
      int need = min(four, get / 4);
      get -= need * 4;
      four -= need;

      need = min(two, get / 2);
      get -= need * 2;
      two -= need;

      need = min(one, get);
      get -= need;
      one -= need;

      need = min(two, (get + 1) / 2);
      get -= need * 2;
      two -= need;

      need = min(four, (get + 3) / 4);
      get -= need * 4;
      four -= need;

      if(get > 0) flag = false;
    }

    if(flag) {
      cout << "YES" << endl;
      return (0);
    }
  }

  cout << "NO" << endl;
}