#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  int A[100000], B[100000];

  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  for(int i = 0; i < M; ++i) {
    scanf("%d", &B[i]);
  }

  auto able = [&](long long dist)
  {
    int head = 0;
    for(int i = 0; i < M; i++) {
      while(head < N && llabs((long long)B[i] - A[head]) <= dist) ++head;
    }
    return(head == N);
  };

  long long low = 0, high = 1LL << 40;
  while(high - low > 0) {
    long long mid = (low + high) / 2;
    if(able(mid)) high = mid;
    else low = mid + 1;
  }
  cout << low << endl;
}