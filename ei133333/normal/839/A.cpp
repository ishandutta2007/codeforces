#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, K, A[100];

  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];

  int curr = 0, ret = 0;
  for(int i = 0; i < N; i++) {
    curr += A[i];
    ret += min(curr, 8);
    curr -= min(curr, 8);
    if(ret >= K) {
      cout << i + 1 << endl;
      return(0);
    }
  }
  cout << -1 << endl;
}