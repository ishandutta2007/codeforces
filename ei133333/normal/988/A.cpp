#include <bits/stdc++.h>

using namespace std;


int main() {
  int N, K, vs[100];
  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> vs[i];

  vector< int > ans;
  set< int > st;
  for(int i = 0; i < N; i++) {
    if(st.count(vs[i])) continue;
    st.emplace(vs[i]);
    ans.push_back(i);
  }

  if(st.size() >= K) {
    cout << "YES" << endl;
    for(int i = 0; i < K; i++) cout << ans[i] + 1 << " ";
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}