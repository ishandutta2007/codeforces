#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

int main() {
  int N, K;
  cin >> N >> K;

  string S;
  cin >> S;

  int ret = 0;

  for(char c = 'a'; c <= 'z'; c++) {
    int add = 0, cnt = 0;
    for(int k = 0; k < N; k++) {
      if(S[k] == c) ++add;
      else add = 0;
      if(add == K) add = 0, ++cnt;
    }
    ret = max(ret, cnt);
  }
  cout << ret << endl;
}