#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 5e5+5;
int pd[20][5][2];

string l, r;

ll solve(string &s) {
  int n = s.size();
  
  for(int i = n; i >= 0; i--) {
    for(int j = 0; j <= 3; j++) {
      for(int k = 0; k < 2; k++) {
        pd[i][j][k] = 0;
        if(i == n) {
          pd[i][j][k] = 1;
        } else if(j > 0) {
          if(k == 0) {
            pd[i][j][k] = pd[i+1][j][k];
            for(int x = '1'; x <= '9'; x++) {
              pd[i][j][k] += pd[i+1][j-1][k];
            }
          } else {
            //cout << "Entrei aq ";
            //cout << s[i] << ' ';
            pd[i][j][k] = (s[i] == '0') ? pd[i+1][j][1] : pd[i+1][j][0];
            for(int x = '1'; x < s[i]; x++) {
              pd[i][j][k] += pd[i+1][j-1][0];
            }
            if(s[i] != '0') pd[i][j][k] += pd[i+1][j-1][k];
          }
        } else {
          pd[i][j][k] = 1;
        }
        //cout << i << ' ' << j << ' ' << k << ' ' << pd[i][j][k] << endl;
      }
    }
  }
  //cout << pd[0][3][1] << ' ';
  return pd[0][3][1];
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    cin >> l >> r;
    int aux = 0;
    for(int i = 0; i < l.size(); i++) {
      if(l[i] != '0') aux++;
    }
    cout << solve(r) - solve(l) + (aux <= 3) << endl;
  }
  return 0;
}