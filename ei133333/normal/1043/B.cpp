#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[1001] = {};
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  vector< int > sa(N + 1);
  for(int i = 1; i <= N; i++) {
    sa[i] = A[i] - A[i - 1];
  }

  vector< int > ans;
  for(int k = 1; k <= N; k++) {
    bool flag = true;
    for(int j = 1; j <= k; j++) {
      int pass = sa[j];
      for(int i = 0; i+j <= N; i += k) {
        if(pass != sa[i+j]) flag = false;
      }
    }
    if(flag) ans.push_back(k);
  }
  cout << ans.size() << endl;
  for(auto &p : ans) cout << p << " ";
  cout << endl;

}