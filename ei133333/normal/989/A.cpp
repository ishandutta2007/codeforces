#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  cin >> S;
  string q = "ABC.";
  for(int i = 2; i < S.size(); i++) {
    int bit = 0;
    bit |= 1 << q.find(S[i - 2]);
    bit |= 1 << q.find(S[i - 1]);
    bit |= 1 << q.find(S[i - 0]);
    if(bit == 7) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}