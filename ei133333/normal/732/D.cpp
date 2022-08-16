#include <bits/stdc++.h>

using namespace std;

int N, M, D[100000], A[100000];

bool last[100000];
int able[100000];

bool check(int right)
{
  memset(last, false, sizeof(last));
  memset(able, -1, sizeof(able));

  for(int i = right; i >= 0; i--) {
    if(~D[i]) {
      if(last[D[i]]++) continue;
      able[i] = D[i];
    }
  }

  for(int i = 0; i < M; i++) {
    if(!last[i]) return(false);
  }

  long long cost = 0;
  for(int i = right; i >= 0; i--) {
    if(~able[i]) cost += A[able[i]];
    else cost = max(0LL, cost - 1);
  }

  return (cost == 0);
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    scanf("%d", &D[i]);
    --D[i];
  }
  for(int i = 0; i < M; i++) {
    scanf("%d", &A[i]);
  }

  if(!check(N - 1)) {
    cout << -1 << endl;
  } else {
    int low = 1, high = N - 1;
    while(high - low > 0) {
      int mid = (low + high) >> 1;
      if(check(mid)) high = mid;
      else low = mid + 1;
    }
    printf("%d\n", low + 1);
  }
}