#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int N, K, C[300000];

  int ans[300000];

  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; i++) scanf("%d", &C[i]);

  priority_queue< pair< int, int > > st;
  for(int i = 0; i < K; i++) st.emplace(C[i], i);
  
  int64 ret = 0LL;
  for(int i = K; i < N + K; i++) {
    if(i < N) st.emplace(C[i], i);
    auto p = st.top();
    st.pop();
    ret += 1LL * p.first * (i - p.second);
    ans[p.second] = i;
  }

  printf("%lld\n", ret);
  for(int i = 0; i < N; i++) printf("%d ", ans[i] + 1);
  puts("");
}