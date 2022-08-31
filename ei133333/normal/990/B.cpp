#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, K, A[200000];
  cin >> N >> K;
  multiset< int > st;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    st.emplace(A[i]);
  }

  int ret = N;
  for(int i = N - 1; i >= 0; i--) {
    auto it = st.upper_bound(A[i]);
    if(it == st.end()) continue;
    ret -= *it <= A[i] + K;
  }

  cout << ret << endl;
}