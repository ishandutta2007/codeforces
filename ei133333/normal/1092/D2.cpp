#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

using pi = pair< int64, int >;


int N;
int64 A[200000];

bool st() {
  stack< pair< int64, int > > st;
  for(int i = 1; i <= N; i++) {
    while(st.size() && st.top().first < A[i - 1]) {
      auto p = st.top();
      if((i - p.second) % 2 == 1) {
        return false;
      }
      st.pop();
    }
    if(st.empty() || st.top().first != A[i - 1]) {
      st.emplace(A[i - 1], i);
    }
  }

  while(st.size()>1) {
    auto p = st.top();
    if((N+1 - p.second) % 2 == 1) {
      return false;
    }
    st.pop();
  }

  return st.size() <= 1;
}


int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  if(st()) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}