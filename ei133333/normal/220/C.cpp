#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > Pi;

const int INF = 1LL << 29;

int main()
{
  int N, A[100000], B[100000];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", A + i), --A[i];
  for(int i = 0; i < N; i++) scanf("%d", B + i), --B[i];

  vector< int > rev(N);
  multiset< int > beet;
  for(int i = 0; i < N; i++) rev[A[i]] = i;
  for(int i = 0; i < N; i++) beet.emplace(i - rev[B[i]]);

  vector< int > ans(N);
  for(int i = 0; i < N; i++) {
    auto latte = beet.lower_bound(i);
    ans[i] = INF;
    if(latte != beet.end()) ans[i] = min(ans[i], *latte - i);
    if(latte != beet.begin()) ans[i] = min(ans[i], i - *--latte);
    beet.erase(beet.find(i - rev[B[i]]));
    beet.emplace(i + N - rev[B[i]]);
  }
  for(int i = 0; i < N; i++) {
    printf("%d\n", ans[i]);
  }

}