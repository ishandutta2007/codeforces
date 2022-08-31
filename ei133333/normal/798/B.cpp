#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;

  cin >> N;
  vector< string > S(N);
  for(int i = 0; i < N; i++) cin >> S[i];

  if(N == 1) {
    cout << 0 << endl;
    return (0);
  }

  vector< string > Q;
  for(int i = 0; i <= 50; i++) {
    Q.push_back(S[0]);
    rotate(S[0].begin(), S[0].begin() + 1, S[0].end());
  }

  for(int i = 1; i < N; i++) {
    bool flag = false;
    for(string &t : Q) flag |= t == S[i];
    if(!flag) {
      cout << -1 << endl;
      return (0);
    }
  }


  int latte = numeric_limits< int >::max();
  for(int i = 0; i < Q.size(); i++) {

    vector< string > vv(N - 1);
    for(int j = 0; j < N - 1; j++) vv[j] = S[j + 1];

    int beet = i;
    for(int j = 0; j < N - 1; j++) {
      while(vv[j] != Q[i]) {
        ++beet;
        rotate(vv[j].begin(), vv[j].begin() + 1, vv[j].end());
      }
    }

    latte = min(latte, beet);
  }

  cout << latte << endl;
}