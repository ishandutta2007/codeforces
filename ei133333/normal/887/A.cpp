#include<bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;

  auto p = S.find('1');

  if(p == string::npos) {
    cout << "no" << endl;
  } else {
    int ret = 0;
    for(int i = p; i < S.size(); i++) {
      if(S[i] == '0') ++ret;
    }
    if(ret >= 6) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}