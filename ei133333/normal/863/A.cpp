#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;

  string add;
  for(int i = 0; i < 1333; i++) {
    string T = add + S;
    string Q = T;
    reverse(begin(Q), end(Q));
    if(T == Q) {
      cout << "YES" << endl;
      return(0);
    }
    add += "0";
  }

  cout << "NO" << endl;
}