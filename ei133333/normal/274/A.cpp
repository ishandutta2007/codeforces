#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, K, A[100000];

  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);

  set< int64 > ng;
  int ret = 0;
  for(int i = 0; i < N; i++) {
    if(ng.count(A[i])) continue;
    ng.emplace(A[i] * K);
  }

  cout << ng.size() << endl;

}