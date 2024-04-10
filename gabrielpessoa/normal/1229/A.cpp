#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int a[ms], b[ms];
set<int> eq;

int isSubmask(int a, int b) {
  for(int i = 0; i < 60; i++) {
    if((a & (1ll << i)) && !(b & (1ll << i))) {
      return false;
    }
  }
  return true;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j <n; j++) {
      if(a[i] == a[j]) {
        eq.insert(a[i]);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j : eq) {
      if(isSubmask(a[i], j)) {
        ans += b[i];
        break;
      }
    }
  }
  cout << ans << '\n';
}