#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
int lcp[100002][32];

int main()
{
  string S, W;
  cin >> S;
  cin >> W;
  for(int i = S.size() - 1; i >= 0; i--) {
    for(int j = W.size() - 1; j >= 0; j--) {
      lcp[i][j] = S[i] == W[j] ? lcp[i + 1][j + 1] + 1 : 0;
    }
  }
  int ret = 0;
  for(int i = 0; i < S.size(); i++) {
    if(lcp[i][0] != W.size()) continue;
    ++ret;
    i += W.size() - 1;
  }
  cout << ret << endl;
}