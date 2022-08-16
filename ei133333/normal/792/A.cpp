#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N;
  cin >> N;
  vector< int64 > vs(N);
  for(int i = 0; i < N; i++) cin >> vs[i];
  sort(begin(vs), end(vs));

  int64 ret = numeric_limits< int64 >::max();
  for(int i = 1; i < N; i++) {
    ret = min(ret, vs[i] - vs[i - 1]);
  }
  int sum = 0;
  for(int i = 1; i < N; i++) {
    sum += vs[i] - vs[i - 1] == ret;
  }

  cout << ret << " " << sum << endl;
}