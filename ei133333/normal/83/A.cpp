#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
using vi = vector< int >;
const int mod = 1e9 + 7;

int main()
{
  int N;

  scanf("%d", &N);
  vector< pair< int, int > > range;
  for(int i = 0; i < N; i++) {
    int A;
    scanf("%d", &A);
    if(range.empty() || range.back().first != A) {
      range.emplace_back(A, 1);
    } else {
      ++range.back().second;
    }
  }

  int64 ret = 0;
  for(auto& p : range) {
    ret += 1LL * p.second * (p.second + 1) / 2;
  }
  printf("%lld\n", ret);
}