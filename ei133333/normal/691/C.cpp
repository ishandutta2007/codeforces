#include<bits/stdc++.h>
using namespace std;

int main()
{
  string T;
  cin >> T;
  deque< char > S(T.begin(), T.end());
  if(count(S.begin(), S.end(), '.') == 0) {
    S.push_back('.');
  }
  
  while(!S.empty() && S.back()  == '0') S.pop_back();
  while(!S.empty() && S.front() == '0') S.pop_front();
  if(!S.empty() && S.back() == '.') S.pop_back();
  int E = 0;
  if(S.front() == '.') {
    S.pop_front();
    for(int i = 0; i < S.size() && S[i] == '0'; i++) {
      if(S[i] == '0') { S.pop_front(), i--, --E; continue; }
      --E;
    }
  } else {
    for(int i = 0; i < S.size() && S[i] != '.'; i++) ++E;
  }

  cout << S[0];
  bool first = false, sec = true;
  string Q;
  for(int i = 1; i < S.size(); i++) {
    if(S[i] == '.') continue;
    if(!first++) Q += ".", sec = false;
    Q += S[i];
  }
  while(!sec && !Q.empty() && Q.back() == '0') Q.pop_back();
  if(!Q.empty() && Q.back() == '.') Q.pop_back();
  cout << Q;
  if(E != 1) cout << "E" << E - 1 << endl;
}