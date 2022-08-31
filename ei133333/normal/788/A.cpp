#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 58;

int main()
{
  int N;
  int64 A[100000];

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  int64 ret = -INF;

  int64 sum = 0;
  for(int i = 0; i < N - 1; i++) {
    int64 call = llabs(A[i] - A[i + 1]) * (i % 2 ? -1 : 1);
    if(i % 2 == 1) sum += call;
    else sum = max(sum + call, call);
    ret = max(ret, sum);
  }

  sum = 0;
  for(int i = 1; i < N - 1; i++) {
    int64 call = llabs(A[i] - A[i + 1]) * (i % 2 ? 1 : -1);
    if(i % 2 == 0) sum += call;
    else sum = max(sum + call, call);
    ret = max(ret, sum);
  }

  cout << ret << endl;
}