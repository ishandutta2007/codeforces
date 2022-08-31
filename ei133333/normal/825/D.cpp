#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
  string S, T;
  int latte[28] = {}, malta[28] = {}, question = 0;

  cin >> S >> T;
  for(auto& c : S) {
    if(c == '?') ++question;
    else ++latte[c - 'a'];
  }
  for(auto& c : T) {
    ++malta[c - 'a'];
  }


  int ret = 0;
  for(int i = 0; i < 1000001; i++) {
    int need = 0;
    for(int j = 0; j < 26; j++) {
      need += max(0LL, malta[j] * i - latte[j]);
    }
    if(question >= need) {
      ret = i;
    }
  }

  for(auto& c : S) {
    if(c == '?') {
      for(int j = 0; j < 27; j++) {
        if(j == 26 || latte[j] < malta[j] * ret) {
          c = (j == 26 ? 'a' : (j + 'a'));
          ++latte[j];
          break;
        }
      }
    }
  }

  cout << S << endl;

}