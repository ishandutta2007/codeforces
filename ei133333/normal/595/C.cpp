#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

int main()
{
  int N, A[200000];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);

  int ret = INF;
  for(int i = 0; i < N; i++) {
    if(i + (N - 2) / 2 + 1 < N) {
      ret = min(ret, A[i + (N - 2) / 2 + 1] - A[i]);
    }
  }
  cout << ret << endl;
}