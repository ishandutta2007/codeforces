#include <bits/stdc++.h>
using namespace std;

const int ms = 5e5+5;
typedef long long ll;
int n, t;
string s;
ll pd[100][100];
int mark[100];
char val[100];
int b[100]; 

void kmpPreprocess() {
    int i = 0, j = -1;
    b[0] = -1;
    while(i < t) {
        while(j >= 0 && s[i] != s[j]) j = b[j];
        b[++i] = ++j;
    }
}

int main() {
  cin >> n;
  cin >> s;
  t = s.size();
  ll ans = 0;
  kmpPreprocess();
  for(int i = 0; i < n; i++) {
    for(int pos = 0; pos < t; pos++) {
      pd[n - i + t - 2][pos] = 1;
    }
    pd[n - i + t - 2][t] = 0;
    int livres = n - t;
    memset(mark, 0, sizeof mark);
    for(int j = n - 1; j <= n + t - 3; j++) {
      mark[j] = 1;
      val[j] = s[j-n+1];
    }
    for(int j = 0; j < t-1; j++) {
      mark[j] = 1;
      val[j] = s[j+1];
    }
    for(int k =  n - i + t - 3; k >= 0; k--) {
      if(!mark[k]) livres--;
      pd[k][t] = 0;
      for(int j = 0; j < t; j++) {
        if(!mark[k]) {
          //cout << i << ' ' << k << ' ' << j << endl;
          int j0 = j;
          while(j0 >= 0 && '0' != s[j0]) j0 = b[j0];
          j0++;
          int j1 = j;
          while(j1 >= 0 && '1' != s[j1]) j1 = b[j1];
          j1++;
          pd[k][j] = pd[k+1][j0] + pd[k+1][j1];
        } else {
          int jx = j;
          while(jx >= 0 && val[k] != s[jx]) jx = b[jx];
          jx++;
          pd[k][j] = pd[k+1][jx];
        }
      }
    }
    //cout << pd[0][0] << ' ' << i << endl;
    ans += pd[0][0] << livres;//min(n-t, i);
    //cout << pd[0][0] << endl;
  }
  cout << ans << endl;
  return 0;
}