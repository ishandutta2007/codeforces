#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, K, A[100000];
  cin >> N >> K;
  int gcd = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] %= K;
    gcd = __gcd(A[i], gcd);
  }
  vector< int > used(K);
  int init = gcd;
  while(!used[init]) {
    used[init] = true;
    (init += gcd) %= K;
  }
  vector< int > ans;
  for(int i =0 ; i < K; i++) {
    if(used[i]) ans.emplace_back(i);
  }
  cout << ans.size() << endl;
  for(auto& p : ans) cout << p << " ";
  cout << endl;
}