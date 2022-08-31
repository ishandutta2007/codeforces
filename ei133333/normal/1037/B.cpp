#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, S, A[200000];
  scanf("%d %d", &N, &S);
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);
  sort(A, A + N);
  int64 ret = 0;
  for(int i = 0; i < N / 2; i++) ret += max(A[i] - S, 0);
  ret += abs(A[N / 2] - S);
  for(int i = N / 2 + 1; i < N; i++) ret += max(S - A[i], 0);
  cout << ret << endl;
}