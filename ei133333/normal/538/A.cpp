#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  string T = "CODEFORCES";
  string S;
  cin >> S;

  for(int i = 0; i < S.size(); i++) {
    for(int j = i + 1; j <= S.size(); j++) {
      string p = S.substr(0, i) + S.substr(j);
      if(p == T) {
        cout << "YES" << endl;
        return(0);
      }
    }
  }
  cout << "NO" << endl;
}