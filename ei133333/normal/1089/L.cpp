#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, K, A[100000], B[100000];
  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];
  vector< int > mp[100000];
  for(int i = 0; i < N; i++) {
    mp[--A[i]].push_back(B[i]);
  }
  int64 ret = 0;
  vector< int > ans;
  for(int i = 0; i < K; i++) {
    sort(begin(mp[i]), end(mp[i]));
    for(int j = 0; j+1 < mp[i].size(); j++) {
      ans.push_back(mp[i][j]);
    }
  }
  sort(begin(ans), end(ans));
  int ptr = 0;
  for(int i = 0; i < K; i++) {
    if(mp[i].empty()) ret += ans[ptr++];
  }

  cout << ret << endl;
}