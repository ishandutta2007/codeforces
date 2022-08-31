#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, S, A[100000];
  cin >> N >> S;
  for(int i = 0; i < N; i++) cin >> A[i];

  auto check = [&](int64 k, bool output)
  {
    vector< int64 > vs;
    for(int64 i = 0; i < N; i++) vs.push_back(A[i] + (i+1)*k);
    sort(begin(vs), end(vs));
    int64 ret = 0;
    for(int i = 0; i < k; i++) ret = min(S + 1, ret + vs[i]);
    if(output) cout << k << " " << ret << endl;
    return(ret <= S);
  };

  int low = 0, high = N;
  while(high - low > 0) {
    int mid = (low + high + 1) >> 1;
    if(check(mid, false)) low = mid;
    else high = mid - 1;
  }

  check(low, true);
}