#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int dp[201][201][4][4][6][2];


int rec(int aWin, int bWin, int times, int a, int b, bool which) {
  if(which) {
    if(aWin == 0) return bWin == 0 && a == 0 && b == 0;
  } else {
    if(bWin == 0) return aWin == 0 && a == 0 && b == 0;
  }
  if(~dp[a][b][aWin][bWin][times][which]) return dp[a][b][aWin][bWin][times][which];
  int lim = (times < 4 ? 25 : 15);

  if(aWin > 0) {
    for(int i = lim; i <= min(lim, a); i++) {
      for(int j = min(b, i - 2); j >= 0; j--) {
        if(rec(aWin - 1, bWin, times + 1, a - i, b - j, which)) {
          return dp[a][b][aWin][bWin][times][which] = true;
        }
      }
    }

    for(int i = lim + 1; i <= a; i++) {
      if(b >= i - 2) {
        if(rec(aWin - 1, bWin, times + 1, a - i, b - (i - 2), which)) {
          return dp[a][b][aWin][bWin][times][which]= true;
        }
      }
    }

  }
  if(bWin > 0) {
    for(int i = lim; i <= min(lim, b); i++) {
      for(int j = min(a, i - 2); j >= 0; j--) {
        if(rec(aWin, bWin - 1, times + 1, a - j, b - i, which)) {
          return dp[a][b][aWin][bWin][times][which] = true;
        }
      }
    }


    for(int i = lim + 1; i <= b; i++) {
      if(a >= i - 2) {

        if(rec(aWin, bWin - 1, times + 1, a - (i - 2), b - i, which)) {
          return dp[a][b][aWin][bWin][times][which] = true;
        }

      }
    }


  }
  return dp[a][b][aWin][bWin][times][which] = false;
}


int rec2(int aWin, int bWin, int times, int a, int b, bool which, bool f = false) {
  if(which) {
    if(aWin == 0) return bWin == 0 && a == 0 && b == 0;
  } else {
    if(bWin == 0) return aWin == 0 && a == 0 && b == 0;
  }
  int lim = (times < 4 ? 25 : 15);

  if(aWin > 0) {
    for(int i = lim; i <= min(lim, a); i++) {
      for(int j = min(b, i - 2); j >= 0; j--) {
        if(rec(aWin - 1, bWin, times + 1, a - i, b - j, which)) {
          if(!f) cout << " ";
          cout << i << ":" << j;
          rec2(aWin - 1, bWin, times + 1, a - i, b - j, which);
          return true;
        }
      }
    }

    for(int i = lim + 1; i <= a; i++) {
      if(b >= i - 2) {
        if(rec(aWin - 1, bWin, times + 1, a - i, b - (i - 2), which)) {
          if(!f) cout << " ";
          cout << i << ":" << i - 2;
          rec2(aWin - 1, bWin, times + 1, a - i, b - (i - 2), which);
          return true;
        }
      }
    }

  }
  if(bWin > 0) {
    for(int i = lim; i <= min(lim, b); i++) {
      for(int j = min(a, i - 2); j >= 0; j--) {
        if(rec(aWin, bWin - 1, times + 1, a - j, b - i, which)) {
          if(!f) cout << " ";
          cout << j << ":" << i;
          rec2(aWin, bWin - 1, times + 1, a - j, b - i, which);
          return true;
        }
      }
    }


    for(int i = lim + 1; i <= b; i++) {
      if(a>= i - 2) {
        if(rec(aWin, bWin - 1, times + 1, a - (i - 2), b - i, which)) {
          if(!f) cout << " ";
          cout << i - 2 << ":" << i;
          rec2(aWin, bWin - 1, times + 1, a - (i - 2), b - i, which);
          return true;
        }
      }
    }


  }
  return false;

}

int main() {
  int M;
  cin >> M;
  memset(dp, -1, sizeof(dp));

  while(M--) {
    int A, B;
    cin >> A >> B;

    bool f = false;
    for(int i = 0; i <= 2; i++) {
      if(rec(3, i, 0, A, B, true)) {
        cout << "3:" << i << endl;

        rec2(3, i, 0, A, B, true, true);
        cout << endl;
        f = true;
        break;
      }
    }
    if(f) continue;
    for(int i = 2; i >= 0; i--) {
      if(rec(i, 3, 0, A, B, false)) {

        cout << i << ":3" << endl;
        rec2(i, 3, 0, A, B, false, true);
        cout << endl;
        f = true;
        break;
      }
    }
    if(f) continue;
    cout << "Impossible\n";
  }
}