#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
int main()
{
  int64 N, K;
  cin >> N >> K;
  vector< int64 > vv;
  for(int64 i = 1; i * i <= N; i++) {
    if(N % i == 0) {
      vv.push_back(i);
      if(i * i != N) vv.push_back(N / i);
    }
  }
  sort(begin(vv), end(vv));

  if(--K >= vv.size()) cout << -1 << endl;
  else cout << vv[K] << endl;
}