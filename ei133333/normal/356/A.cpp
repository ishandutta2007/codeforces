#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector< int > ans(N);
  set< int > st;
  for(int i = 0; i < N; i++) {
    st.emplace(i);
  }
  for(int i = 0; i < M; i++) {
    int L, R, X;
    cin >> L >> R >> X;
    --L, --R, --X;
    auto p = st.lower_bound(X);
    ++p;
    while(p != end(st) && *p <= R) {
      ans[*p] = X + 1;
      p = st.erase(p);
    }
    p = st.lower_bound(X);
    while(p != begin(st)) {
      --p;
      if(L <= *p) {
        ans[*p] = X + 1;
        p = st.erase(p);
      } else {
        break;
      }
    }
  }
  for(int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
}