#include <bits/stdc++.h>
using namespace std;

int N, M, P;
string S, T;
int prv[600000], nxt[600000], build[600000];

int main()
{
  cin >> N >> M >> P;
  cin >> S;
  cin >> T;
  S = "*" + S;
  for(int i = 0; i < S.size(); i++) prv[i] = i - 1;
  for(int i = 0; i < S.size(); i++) nxt[i] = i + 1;
  
  stack< int > ss;
  ss.push(0);
  for(int i = 1; i < S.size(); i++) {
    int now = ss.top();
    if(S[i] == '(') {
      ss.push(i);
    } else {
      build[i] = now;
      build[now] = i;
      ss.pop();
    }
  }
  for(char query : T) {
    if(query == 'L') {
      P = prv[P];
    } else if(query == 'R') {
      P = nxt[P];
    } else {
      int s = min(P, build[P]);
      int t = max(P, build[P]);
      nxt[prv[s]] = nxt[t];
      prv[nxt[t]] = prv[s];
      if(nxt[t] == S.size()) P = prv[s];
      else                   P = nxt[t];
    }
  }
  string ret = "";
  int ptr = 0;
  while(ptr != S.size()) {
    if(ptr != 0) ret += S[ptr];
    ptr = nxt[ptr];
  }
  cout << ret << endl;
}