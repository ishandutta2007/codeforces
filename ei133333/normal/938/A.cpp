#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

const string T = "aeiouy";

int main()
{
  int N;
  string S;
  cin >> N;
  cin >> S;
  bool pv = false;
  for(int i = 0; i < N; i++) {
    if(!pv || T.find(S[i]) == string::npos) cout << S[i];
    pv = T.find(S[i]) != string::npos;
  }
  cout << endl;
}