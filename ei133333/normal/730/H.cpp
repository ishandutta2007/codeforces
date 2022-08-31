#include <bits/stdc++.h>

using namespace std;

int main()
{
  int M, N;
  string S[100];

  cin >> M >> N;
  for(int i = 0; i < M; i++) {
    cin >> S[i];
  }

  vector< string > kk(N);
  bool used[100] = {};
  for(int i = 0; i < N; i++) {
    int K;
    cin >> K;
    kk[i] = S[--K];
    used[K] = true;
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i; j++) {
      if(kk[i].size() != kk[j].size()) {
        cout << "No" << endl;
        return (0);
      }
    }
  }

  string TT = "";
  for(int i = 0; i < kk[0].size(); i++) {
    set< char > cc;
    for(int j = 0; j < kk.size(); j++) cc.insert(kk[j][i]);
    if(cc.size() >= 2) TT += "?";
    else TT += *cc.begin();
  }

  for(int i = 0; i < M; i++) {
    if(!used[i]) {
      if(TT.size() != S[i].size()) continue;
      bool match = true;
      for(int j = 0; j < TT.size(); j++) {
        if(TT[j] == '?' || S[i][j] == TT[j]) continue;
        match = false;
      }
      if(match) {
        cout << "No" << endl;
        return(0);
      }
    }
  }

  cout << "Yes" << endl;
  cout << TT << endl;
}