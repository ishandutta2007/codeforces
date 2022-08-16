#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N, A[100000];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);
  sort(A, A + N);
  
  int ret = 0;
  for(int i = 0; i < N; i++) {
    if(ret < A[i]) ++ret;
  }
  printf("%d\n", ret + 1);
}