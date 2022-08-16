#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 59;

int main() {
  int N, A[1001] = {};
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector< int > ans;
  for(int i = 1; i <= N; i++) {
    if(A[i - 1] + 1 != A[i]) {
      ans.emplace_back(A[i - 1]);
    }
  }
  cout << ans.size() << endl;
  for(auto &v : ans) cout << v << " ";
  cout << endl;
}