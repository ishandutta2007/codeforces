#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int H, W;
  string S[250];

  cin >> H >> W;
  for(int i = 0; i < H; i++) {
    cin >> S[i];
    for(auto &p : S[i]) p -= 'a';
  }

  int64 ans = 0;
  for(int left = 0; left < W; left++) {
    int sz = H * 2 + 1;
    vector< vector< int > > sum(sz);
    vector< int > bit(sz);
    for(int i = 0; i < H; i++) sum[i * 2 + 1].resize(27);
    for(int right = left; right < W; right++) {
      for(int i = 0; i < H; i++) {
        sum[i * 2 + 1][S[i][right]]++;
        bit[i * 2 + 1] ^= 1 << S[i][right];
      }
      int ptr = 1;
      for(int i = 0; i < H; i++) {
        if(__builtin_popcount(bit[i * 2 + 1]) > 1) sum[2 * i + 1][26] = ptr++;
        else sum[2 * i + 1][26] = 0;
      }
      vector< int > rad(sz);
      int i = 0, j = 0;
      while(i < sz) {
        while(i - j >= 0 && i + j < sz && sum[i - j] == sum[i + j]) {
          ++j;
        }
        rad[i] = j;
        int k = 1;
        while(i - k >= 0 && i + k < sz && k + rad[i - k] < j) {
          rad[i + k] = rad[i - k];
          ++k;
        }
        i += k;
        j -= k;
      }


      for(int k = 0; k < sz; k += 2) {
        ans += rad[k] / 2;
      }
      for(int k = 1; k < sz; k += 2) {
        if(sum[k][26] == 0) ans += (rad[k] + 1) / 2;
      }
    }
  }
  cout << ans << endl;
}