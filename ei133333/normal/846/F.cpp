#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N;
  vector< int > range[1000000];

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    int A;
    scanf("%d", &A);
    range[--A].emplace_back(i);
  }
  int64 ret = 0;
  for(int i = 0; i < 1000000; i++) {
    int64 all = 1LL * N * N;
    for(int j = 0; j <= range[i].size(); j++) {
      int64 left, right;
      left = (j == 0 ? 0 : range[i][j - 1] + 1);
      right = (j == range[i].size() ? N : range[i][j]);
      all -= (right - left) * (right - left);
    }
    ret += all;
  }
  printf("%.20Lf\n", (long double) ret / N / N);
}