#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[100000];
  cin >> N;
  multiset< int > st;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    st.emplace(A[i]);
  }
  sort(A, A + N);
  int ret = 0;
  for(int i = 0; i < N; i++) {
    auto it = st.upper_bound(A[i]);
    if(it == st.end()) continue;
    st.erase(it);
    ++ret;
  }
  cout << ret << endl;
}