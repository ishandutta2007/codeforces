#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, M, L[200000], R[200000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
  }
  sort(L, L + N);
  sort(R, R + N);


  int ret = 0;
  cin >> M;
  for(int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    ret = max(ret, A - R[0]);
    ret = max(ret, L[N - 1] - B);
  }

  cout << ret << endl;
}