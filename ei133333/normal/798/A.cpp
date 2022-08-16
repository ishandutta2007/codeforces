#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;

  string T = S;
  reverse(begin(T), end(T));

  int beet = 0;
  for(int i = 0; i < S.size(); i++) beet += S[i] != T[i];

  if(beet == 2 || (S.size() % 2 == 1 && beet == 0)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}