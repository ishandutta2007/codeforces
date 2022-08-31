#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const string beet = "aeiou";

int main() {
  int N, K;
  cin >> N >> K;
  int mask = (1 << 4) - 1;
  for(int i = 0; i < N; i++) {
    string s[4];
    for(int j = 0; j < 4; j++) {
      string p;
      cin >> p;
      reverse(begin(p), end(p));
      int cnt = 0;
      s[j] = "";
      for(auto &c : p) {
        if(beet.find(c) != string::npos) {
          ++cnt;
        }
        s[j] += c;
        if(cnt == K) break;
      }
      if(cnt < K) {
        cout << "NO\n";
        return 0;
      }
    }
    int nxtmask = 0;
    if(s[0] == s[1] && s[2] == s[3]) nxtmask |= 1;
    if(s[0] == s[2] && s[1] == s[3]) nxtmask |= 2;
    if(s[0] == s[3] && s[1] == s[2]) nxtmask |= 4;
    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) nxtmask |= 8;
    mask &= nxtmask;
  }
  if(mask & 8)cout << "aaaa\n";
  else if(mask & 4)cout << "abba\n";
  else if(mask & 2) cout << "abab\n";
  else if(mask & 1) cout << "aabb\n";
  else cout << "NO\n";
}