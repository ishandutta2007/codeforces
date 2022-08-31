#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, K, A[200000];
  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];
  string S;
  cin >> S;

  stack< char > st;
  vector< vector< int > > v;

  for(int i = 0; i < N; i++) {
    if(st.empty() || S[i] != st.top()) {
      st.emplace(S[i]);
      v.emplace_back();
    }
    v.back().emplace_back(A[i]);
  }
  int64 ret = 0;
  for(auto &p : v) {
    sort(p.rbegin(), p.rend());
    for(int i = 0; i < min((int) p.size(), K); i++) ret += p[i];
  }
  cout << ret << endl;
}