#include<bits/stdc++.h>

using namespace std;

int H, W;
string S[5000];
int dp[5000][5000], beet[5001];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W;
  for(int i = 0; i < H; i++) {
    cin >> S[i];
  }

  for(int i = 0; i < H; i++) {
    int sum = 0;
    for(int j = W - 1; j >= 0; j--) {
      if(S[i][j] == '1') ++sum;
      else sum = 0;
      dp[i][j] = sum;
    }
  }

  int ret = 0;

  for(int j = 0; j < W; j++) {
    for(int i = 0; i < H; i++) ++beet[dp[i][j]];
    int latte = 0;
    for(int i = 5000; i >= 0; i--) {
      latte += beet[i];
      ret = max(ret, latte * i);
      beet[i] = 0;
    }
  }

  cout << ret << endl;
}