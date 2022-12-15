#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef vector<int> vi;

const int ms = 1005;
const int inf = 0x3f3f3f3f;

int a[ms][ms];
int ans[ms];

int raiz(int x) {
  int lo = 1, hi = 1e9;
  while(lo <= hi) {
    int mi = (lo+hi)/2;
    if(mi*mi < x) {
      lo = mi+1;
    } else if(mi * mi > x) {
      hi = mi - 1;
    } else {
      return mi;
    }
  }
}

main() {
  int n;
  // cout << raiz(25) << endl;
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  ans[0] = raiz(a[0][1]*a[0][2]/a[1][2]);
  for(int i = 1; i < n; i++) {
    ans[i] = a[0][i]/ans[0];
  }
  for(int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
}