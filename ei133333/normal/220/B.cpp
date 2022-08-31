#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  scanf("%d %d", &N, &M);
  vector< vector< int > > odd(N + 1);

  for(int i = 0; i < N; i++) {
    int A;
    scanf("%d", &A);
    if(A <= N) odd[A].push_back(i);
  }

  vector< int > call;
  for(int i = 1; i <= N; i++) {
    if(odd[i].size() >= i) call.push_back(i);
  }
  while(M--) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, b;
    int ret = 0;
    for(auto& s : call) {
      ret += lower_bound(begin(odd[s]), end(odd[s]), b) - lower_bound(begin(odd[s]), end(odd[s]), a) == s;
    }
    printf("%d\n", ret);
  }

}