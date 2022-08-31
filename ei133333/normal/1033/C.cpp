#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int N, A[100000];
int dp[100000];

bool rec(int idx) {
  if(~dp[idx]) return dp[idx];
  for(int i = A[idx]; i <= N; i += A[idx]) {
    int latte = idx + i;
    if(0 <= latte && latte < N && A[idx] < A[latte]) {
      if(!rec(latte)) return dp[idx] = true;
    }
    int malta = idx - i;
    if(0 <= malta && malta < N && A[idx] < A[malta]) {
      if(!rec(malta)) return dp[idx] = true;
    }
  }
  return dp[idx] = false;
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  memset(dp, -1, sizeof(dp));
  string s="BA";
  for(int i = 0; i < N; i++) {
    cout << s[rec(i)];
  }
  cout << endl;
}