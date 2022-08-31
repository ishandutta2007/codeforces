#include<bits/stdc++.h>

using namespace std;


int main()
{
  string S;
  cin >> S;

  string st = "1689";
  string curr[7];

  do {
    int mod = st[0] - '0';
    for(int i = 1; i < st.size(); i++) {
      mod *= 10;
      mod += st[i] - '0';
      mod %= 7;
    }
    curr[mod] = st;
  } while(next_permutation(begin(st), end(st)));




  for(int i = 0; i < 7; i++) {
    string t;
    bool used[10] = {};
    int mod = i;
    for(auto &c : S) {
      if(c == '1' || c == '6' || c == '8' || c == '9') {
        if(!used[c - '0']) {
          used[c - '0'] = true;
          continue;
        }
      }
      t += c;
      mod *= 10;
      mod += c - '0';
      mod %= 7;
    }
    if(mod == 0) {
      cout << curr[i] + t << endl;
      return(0);
    }
  }
}