#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, Q;
  bitset< 1000 > matrix1[1000], matrix2[1000];

  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      bool s;
      scanf("%d", &s);
      matrix1[i][j] = s;
      matrix1[j][i] = s;
    }
  }

  int sum = 0;
  for(int i = 0; i < N; i++) {
    sum += (matrix1[i] ^ matrix2[i]).count();
    sum &= 1;
  }

  scanf("%d", &Q);
  while(Q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int x;
      scanf("%d", &x);
      --x;
      sum ^= 1;
    } else if(t == 2) {
      int x;
      scanf("%d", &x);
      --x;
      sum ^= 1;
    } else {
      printf("%d", sum);
    };
  }

  puts("");
}