#include<bits/stdc++.h>

using namespace std;


int main()
{
  int N, M, K, A[100][100];

  cin >> N >> M >> K;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }

  int ret = 0, cnt = 0;

  for(int j = 0; j < M; j++) {

    int pvsum = 0, curr = 0, operation = 0;

    for(int i = 0; i < N; i++) {
      if(A[i][j] == 1) {
        int sum = 0;
        for(int k = 0; k < K; k++) {
          if(i + k >= N) break;
          sum += A[i + k][j];
        }
        if(curr < sum) {
          curr = sum;
          operation = pvsum;
        }
        ++pvsum;
      }
    }

    ret += curr;
    cnt += operation;
  }

  cout << ret << " " << cnt << endl;
}